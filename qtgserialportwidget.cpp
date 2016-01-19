#include "qtgserialportwidget.h"
#include <QGridLayout>
#include <QLabel>

QTGSerialPortWidget::QTGSerialPortWidget(QWidget *parent) : QWidget(parent),
    _connectButtonText(tr("connect")),
    _connectDisconnectButtonText(tr("disconnect")),
    _serialPortComboBox(new QComboBox(this)),
    _connectDisconnectButton(new QPushButton(_connectButtonText,this)),
    _refreshButton(new QPushButton(tr("refresh"), this))
{
    QGridLayout *mainLayout = new QGridLayout(this);
    QLabel *portLabel = new QLabel(tr("Port"), this);
    QFont portLabelFont = portLabel->font();
    portLabelFont.setBold(true);

    portLabel->setFont(portLabelFont);
    mainLayout->addWidget(portLabel, 0,0);
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        _serialPortComboBox->addItem(info.portName());
    }
    mainLayout->addWidget(_serialPortComboBox, 0, 1, 1,3);
    mainLayout->addWidget(_connectDisconnectButton, 0,4);
    connect(_refreshButton, SIGNAL(clicked(bool)), this, SLOT(onRefreshButtonClick(bool)));
    mainLayout->addWidget(_refreshButton, 0,5);


    setLayout(mainLayout);

    connect(_connectDisconnectButton, SIGNAL(clicked(bool)), this, SLOT(onConnectButtonClick(bool)));
}

QComboBox *QTGSerialPortWidget::getSerialPortComboBox()
{
    return _serialPortComboBox;
}

void QTGSerialPortWidget::setConnected()
{
    _serialPortComboBox->setDisabled(true);
    _refreshButton->setDisabled(true);
    _connectDisconnectButton->setText(tr("disconnect"));
}
void QTGSerialPortWidget::setDisconnected()
{
    _serialPortComboBox->setEnabled(true);
    _refreshButton->setEnabled(true);
    _connectDisconnectButton->setText(tr("connect"));
}

void QTGSerialPortWidget::setCurrentIndex(int value)
{
    _serialPortComboBox->setCurrentIndex(value);
}

void QTGSerialPortWidget::setCurrentText(QString value)
{
    _serialPortComboBox->setCurrentText(value);
}

void QTGSerialPortWidget::onConnectButtonClick(bool value)
{
    Q_UNUSED(value);
    if(_connectDisconnectButton->text() == _connectButtonText)
    {
        emit connectionRequest(_serialPortComboBox->currentText());
    }
    else if(_connectDisconnectButton->text() == _connectDisconnectButtonText)
    {
        emit disconnectionRequest();
    }
}

void QTGSerialPortWidget::onRefreshButtonClick(bool value)
{
    Q_UNUSED(value);
    _serialPortComboBox->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        _serialPortComboBox->addItem(info.portName());
    }
}

