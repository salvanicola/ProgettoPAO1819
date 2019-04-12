#include "controlcore.h"
#include "uozappview.h"


UozAppview::UozAppview(ControlCore* control, QDockWidget *parent) : QDockWidget(parent),controller(control), chat(new QTextBrowser(this)), textbox(new QLineEdit()), p(new QPushButton("send")), buttonimage(new QPushButton("send image"))
{
    setWindowFlags(Qt::WindowTitleHint);
    QGridLayout* layout= new QGridLayout();
    textbox->setPlaceholderText("Nuovo Messaggio");
    layout->addWidget(chat,0,0,1,3);
    layout->addWidget(textbox, 1, 0, 1, 2);
    layout->addWidget(p, 1,2);
    layout->addWidget(buttonimage,2,2);
    QWidget* widget=new QWidget();
    widget->setLayout(layout);
    setWidget(widget);
    connect(p, SIGNAL(clicked()), this , SLOT(pressSendT()));
    connect(textbox, SIGNAL(returnPressed()), p, SLOT(click()));
    connect(p, SIGNAL(clicked()), textbox, SLOT(clear()));
    connect(buttonimage, SIGNAL(clicked()), this, SLOT(pressSendI()));

}

void UozAppview::setSender_Receiver(QString s1, QString s2){
    sender=s1;
    receiver=s2;
}

void UozAppview::pressSendT(){
    controller->sendATMessage(this);
}

void UozAppview::pressSendI(){
    QString file = QFileDialog::getOpenFileName(this, tr("Select an image"),
                                      ".", tr("Bitmap Files (*.bmp)\n"
                                        "JPEG (*.jpg *jpeg)\n"
                                        "GIF (*.gif)\n"
                                        "PNG (*.png)\n"));
    controller->sendAIMessage(this,file);
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
    }
    if(dynamic_cast<imagemessage*>(m)){
        QString text4chat="<";
        text4chat.append(sender);
        text4chat.append("> ");
        text4chat.append("send an image:");
        chat->append(text4chat);
        QTextDocumentFragment fragment;
        QString url=QString("<img src='").append(dynamic_cast<imagemessage*>(m)->geturl()).append(QString("'>"));
        fragment = QTextDocumentFragment::fromHtml(url);
        chat->textCursor().insertFragment(fragment);
        chat->setVisible(true);
        if(dynamic_cast<imagemessage*>(m)->getdescription()!=nullptr){
            chat->append(QString("description: ").append(dynamic_cast<imagemessage*>(m)->getdescription()));
        }
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
    }
    if(dynamic_cast<imagemessage*>(m)){
        QString text4chat="<";
        text4chat.append(receiver);
        text4chat.append("> ");
        text4chat.append("send an image:");
        chat->append(text4chat);
        QTextDocumentFragment fragment;
        QString url=QString("<img src='").append(dynamic_cast<imagemessage*>(m)->geturl()).append(QString("'>"));
        fragment = QTextDocumentFragment::fromHtml(url);
        chat->textCursor().insertFragment(fragment);
        chat->setVisible(true);
        if(dynamic_cast<imagemessage*>(m)->getdescription()!=nullptr){
            chat->append(QString("description: ").append(dynamic_cast<imagemessage*>(m)->getdescription()));
        }
    }
}
