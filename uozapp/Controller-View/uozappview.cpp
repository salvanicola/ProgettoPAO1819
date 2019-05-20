#include "controlcore.h"
#include "uozappview.h"


UozAppview::UozAppview(ControlCore* control, QDockWidget *parent) : QDockWidget(parent),controller(control), chat(new QTextBrowser(this)), textbox(new QTextEdit()), p(new QPushButton("send")), buttonimage(new QPushButton("send image")), buttoncontact(new QPushButton("send contact"))
{
    setFeatures(QDockWidget::NoDockWidgetFeatures);
    QGridLayout* layout= new QGridLayout();
    textbox->setPlaceholderText("Nuovo Messaggio");
    layout->addWidget(chat,0,0,1,3);
    layout->setRowStretch(0,2);
    layout->addWidget(textbox, 1, 0, 3, 2);
    layout->addWidget(p, 1,2);
    layout->addWidget(buttonimage,2,2);
    layout->addWidget(buttoncontact,3,2);
    QWidget* widget=new QWidget();
    widget->setLayout(layout);
    setWidget(widget);
    connect(p, SIGNAL(clicked()), this , SLOT(pressSendT()));
    //connect(textbox, SIGNAL(returnPressed()), p, SLOT(click()));se torna la QLineEdit
    connect(p, SIGNAL(clicked()), textbox, SLOT(clear()));
    connect(buttonimage, SIGNAL(clicked()), this, SLOT(pressSendI()));
    connect(buttoncontact,SIGNAL(clicked()),this, SLOT(pressSendC()));

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
                                      ".", tr(
                                        "JPEG (*.jpg *jpeg)\n"
                                        "GIF (*.gif)\n"
                                        "PNG (*.png)\n"
                                        "Bitmap Files (*.bmp)\n"));
    if(file!=nullptr)controller->sendAIMessage(this,file);
}

void UozAppview::pressSendC(){
    QWidget* contactdialog=new QWidget();
    QGridLayout* lay=new QGridLayout(contactdialog);
    lay->addWidget(new QLabel("Name"),0,0);
    QLineEdit* nome=new QLineEdit();
    nome->setPlaceholderText("Mario");
    lay->addWidget(nome,0,1);
    lay->addWidget(new QLabel("Surname"),1,0);
    QLineEdit* cognome=new QLineEdit();
    cognome->setPlaceholderText("Rossi");
    lay->addWidget(cognome,1,1);
    lay->addWidget(new QLabel("nickname"),2,0);
    QLineEdit* nickname=new QLineEdit();
    nickname->setPlaceholderText("mariorossi");
    lay->addWidget(nickname,2,1);
    QLineEdit* prefix=new QLineEdit();
    prefix->setPlaceholderText("prefix");
    QLineEdit* number=new QLineEdit();
    number->setPlaceholderText("number");    
    lay->addWidget(prefix,3,0);
    lay->addWidget(number,3,1);
    lay->setColumnStretch(1,2);
    QPushButton* ok=new QPushButton("send");
    connect(ok, &QPushButton::clicked, controller, [=](){controller->sendACMEssage(this,nome->text(),cognome->text(),nickname->text(),prefix->text(),number->text());});
    connect(ok, SIGNAL(clicked()), contactdialog, SLOT(close()));
    lay->addWidget(ok,4,1);
    contactdialog->setLayout(lay);
    contactdialog->show();
}

QString UozAppview::getText(){
    return textbox->toPlainText();
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
        text4chat.append(dynamic_cast<textmessage*>(m)->getSender());
        text4chat.append("> ");
        text4chat.append(dynamic_cast<textmessage*>(m)->getText());
        chat->append(text4chat);
    }
    else if(dynamic_cast<imagemessage*>(m)){
        QString text4chat="<";
        text4chat.append(dynamic_cast<imagemessage*>(m)->getSender());
        text4chat.append("> ");
        text4chat.append("send an image:");
        chat->append(text4chat);
        QTextDocumentFragment fragment;
        QString url=QString("<img src='").append(dynamic_cast<imagemessage*>(m)->geturl()).append(QString("'/>"));
        fragment = QTextDocumentFragment::fromHtml(url);
        chat->textCursor().insertFragment(fragment);
        chat->setVisible(true);
        if(dynamic_cast<imagemessage*>(m)->getdescription()!=nullptr){
            chat->append(QString("description: ").append(dynamic_cast<imagemessage*>(m)->getdescription()));
        }
    }
    else if(dynamic_cast<contactmessage*>(m)){
        QString text4chat="<";
        text4chat.append(dynamic_cast<contactmessage*>(m)->getSender());
        text4chat.append("> ");
        text4chat.append("send a contact:");
        chat->append(text4chat);
        contactmessage* contact=dynamic_cast<contactmessage*>(m);
        chat->append(QString("Name: ").append(contact->getname()));
        chat->append(QString("Surname: ").append(contact->getsurname()));
        chat->append(QString("nickname: ").append(contact->getnickname()));
        chat->append(QString("Prefix: ").append(contact->getprefix()));
        chat->append(QString("Number: ").append(contact->getnumber()));
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
    else if(dynamic_cast<contactmessage*>(m)){
        QString text4chat="<";
        text4chat.append(sender);
        text4chat.append("> ");
        text4chat.append("send a contact:");
        chat->append(text4chat);
        contactmessage* contact=dynamic_cast<contactmessage*>(m);
        chat->append(QString("Name: ").append(contact->getname()));
        chat->append(QString("Surname: ").append(contact->getsurname()));
        chat->append(QString("nickname: ").append(contact->getnickname()));
        chat->append(QString("Prefix: ").append(QString(contact->getprefix())));
        chat->append(QString("Number: ").append(QString(contact->getnumber())));
    }
}
