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
#include <QDockWidget>
#include <QTextDocumentFragment>
#include <QFileDialog>
#include "./source/message.h"
#include "./source/textmessage.h"
#include "./source/imagemessage.h"
#include "./source/contactmessage.h"

class ControlCore;//necessari per inclusione incrociata dei file .h che darebbe errore sull'ifndef

class UozAppview : public QDockWidget
{
    Q_OBJECT
public:
    explicit UozAppview(ControlCore *, QDockWidget * = nullptr);
    virtual ~UozAppview();
    void setSender_Receiver(QString, QString);
    QString getText();
    QString getsender();
    QString getreceiver();
    void showResult(ContainerList<message*> , QWidget* );
    void showMessageOnBrowser(message*, QTextBrowser*, bool);
    void showMessageOnChat(message*, bool);
signals:

public slots:
    void pressSendT();
    void pressSendI();
    void pressSendC();
    void showmessagesent(message* );
    void showmessagereceived(message*);
    void showmessageremoved(message* );
    void searching();
    void removing();
    void clearChat();
private:
    ControlCore* controller;
    QTextBrowser* chat;
    QTextEdit* textbox;
    QPushButton* p;
    QPushButton* buttonimage;
    QPushButton* buttoncontact;
    QPushButton* searchmessage;
    QPushButton* removemessage;
    QString sender;
    QString receiver;
};

#endif // UOZAPPVIEW_H
