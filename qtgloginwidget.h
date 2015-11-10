#ifndef QTGLOGINWIDGET_H
#define QTGLOGINWIDGET_H

#include <QLineEdit>
#include <QWidget>

class QTGLoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QTGLoginWidget(QWidget *parent = 0);
protected:
    void keyPressEvent(QKeyEvent *event);
protected:
    QLineEdit *_usernameLineEdit;
    QLineEdit *_passwordLineEdit;

signals:
    void connectionRequest(QString username, QString password);

public slots:
private slots:
    void onConnectButtonClicked(bool value);
};

#endif // QTGLOGINWIDGET_H
