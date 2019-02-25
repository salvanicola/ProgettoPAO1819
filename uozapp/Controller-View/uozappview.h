#ifndef UOZAPPVIEW_H
#define UOZAPPVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>
#include <QGroupBox>
#include<QTextBrowser>

class ControlCore;//necessari per inclusione incrociata dei file .h che darebbe errore sull'ifndef

class UozAppview : public QWidget
{
    Q_OBJECT
public:
    explicit UozAppview(ControlCore *control = nullptr, QWidget *parent = nullptr);
    void setSender_Receiver(QString, QString);
    QString getText();
    QString* getsender_receiver();   
signals:

public slots:
    void newMessage(QString, QString);
    void pressSend();
private:
    ControlCore* controller;
    QTextBrowser* chat;
    QLineEdit* textbox;
    QPushButton* p;
    QString sender;
    QString receiver;
};

#endif // UOZAPPVIEW_H
