#include "qtgloginwidget.h"
#include <QKeyEvent>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

QTGLoginWidget::QTGLoginWidget(QWidget *parent) : QWidget(parent),
    _usernameLineEdit(new QLineEdit(this)),
    _passwordLineEdit(new QLineEdit(this))
{
    QVBoxLayout *containerLayout = new QVBoxLayout(this);
    QWidget *mainWidget = new QWidget(this);
    QGridLayout *mainLayout = new QGridLayout(mainWidget);
    QLabel *usernameLabel = new QLabel(tr("username"), this);
    QFont labelFont = usernameLabel->font();
    labelFont.setBold(true);
    usernameLabel->setFont(labelFont);
    mainLayout->addWidget(usernameLabel,0,0);
    mainLayout->addWidget(_usernameLineEdit,0,1);

    QLabel *passwordLabel = new QLabel(tr("password"), this);
    passwordLabel->setFont(labelFont);
    mainLayout->addWidget(passwordLabel);

    _passwordLineEdit->setEchoMode(QLineEdit::Password);
    _passwordLineEdit->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);
    mainLayout->addWidget(_passwordLineEdit,1,1);
    QPushButton *connectButton = new QPushButton(tr("connect"), this);
    connect(connectButton, SIGNAL(clicked(bool)), this, SLOT(onConnectButtonClicked(bool)));

    mainLayout->addWidget(connectButton);

    mainWidget->setLayout(mainLayout);

    containerLayout->addWidget(mainWidget);
    containerLayout->addSpacerItem(new QSpacerItem(1,1, QSizePolicy::Expanding));
    setLayout(containerLayout);
}

void QTGLoginWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return)
    {
        QString username = _usernameLineEdit->text();
        if(!username.isEmpty())
        {
            onConnectButtonClicked(true);
        }
    }
}

void QTGLoginWidget::onConnectButtonClicked(bool value)
{
    Q_UNUSED(value);
    emit connectionRequest(_usernameLineEdit->text(), _passwordLineEdit->text());
}

