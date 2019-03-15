#include "controlcore.h"
#include "uozappview.h"


UozAppview::UozAppview(ControlCore* control, QWidget *parent) : QWidget(parent),controller(control), chat(new QTextBrowser(this)), textbox(new QLineEdit()), p(new QPushButton("send"))
{
    setWindowFlags(Qt::WindowTitleHint);
    QGridLayout* layout= new QGridLayout();
    textbox->setPlaceholderText("Nuovo Messaggio");
    layout->addWidget(chat,0,0,1,3);
    layout->addWidget(textbox, 1, 0, 1, 2);
    layout->addWidget(p, 1,2);
    setLayout(layout);
    connect(p, SIGNAL(clicked()), this , SLOT(pressSend()));
    connect(p, SIGNAL(clicked()), textbox, SLOT(clear()));
}

void UozAppview::setSender_Receiver(QString s1, QString s2){
    sender=s1;
    receiver=s2;
}

void UozAppview::pressSend(){
    controller->sendAMessage(this);
}

QString UozAppview::getText(){
    return textbox->text();
}

QString UozAppview::getsender(){
    return  sender;
}

QString UozAppview::getreceiver(){
    return  receiver;
}

void UozAppview::showmessagesent(message* m){
    if(dynamic_cast<textmessage*>(m)){
        QString text4chat="<";
        text4chat.append(sender);
        text4chat.append("> ");
        text4chat.append(dynamic_cast<textmessage*>(m)->getText());
        chat->append(text4chat);
        //chat->addWidget(label);
    }
}

void UozAppview::showmessagereceived(message* m){
    if(dynamic_cast<textmessage*>(m)){
        QString text4chat="<";
        text4chat.append(receiver);
        text4chat.append("> ");
        text4chat.append(dynamic_cast<textmessage*>(m)->getText());
        text4chat=text4chat.rightJustified(8);
        chat->append(text4chat);
        //chat->addWidget(label);
    }
}
