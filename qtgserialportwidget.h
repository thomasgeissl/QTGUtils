#ifndef QTGSERIALPORTWIDGET_H
#define QTGSERIALPORTWIDGET_H

#include <QComboBox>
#include <QPushButton>
#include <QtSerialPort>
#include <QWidget>

class QTGSerialPortWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QTGSerialPortWidget(QWidget *parent = 0);
    QComboBox *getSerialPortComboBox();
private:
    QString _connectButtonText;
    QString _connectDisconnectButtonText;
    QComboBox *_serialPortComboBox;
    QPushButton *_connectDisconnectButton;

signals:
    void connectionRequest(QString port);
    void disconnectionRequest();


public slots:
    void setConnected();
    void setDisconnected();
    void setCurrentIndex(int value);
    void setCurrentText(QString value);
private slots:
    void onConnectButtonClick(bool value);
    void onRefreshButtonClick(bool value);

};

#endif // QTGSERIALPORTWIDGET_H
