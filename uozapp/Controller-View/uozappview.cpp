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

QString* UozAppview::getsender_receiver(){
    QString array[2] = {sender, receiver};
    return  array;
}

void UozAppview::newMessage(QString text, QString sender){
    QString text4chat="<";
    text4chat.append(sender);
    text4chat.append("> ");
    text4chat.append(text);
    text4chat=text4chat.rightJustified(8);
    chat->append(text4chat);
    //chat->addWidget(label);
}
