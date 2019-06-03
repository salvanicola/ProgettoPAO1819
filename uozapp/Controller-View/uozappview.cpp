#include "controlcore.h"
#include "uozappview.h"


UozAppview::UozAppview(ControlCore* control, QDockWidget *parent) : QDockWidget(parent),controller(control), chat(new QTextBrowser(this)), textbox(new QTextEdit()), p(new QPushButton("send")), buttonimage(new QPushButton("send image")), buttoncontact(new QPushButton("send contact")), searchmessage(new QPushButton("search")), removemessage(new QPushButton("remove"))
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
    layout->addWidget(searchmessage,4,0);
    layout->addWidget(removemessage,4,1);
    QWidget* widget=new QWidget();
    widget->setLayout(layout);
    setWidget(widget);
    connect(p, SIGNAL(clicked()), this , SLOT(pressSendT()));
    connect(searchmessage, SIGNAL(clicked()), this, SLOT(searching()));
    connect(p, SIGNAL(clicked()), textbox, SLOT(clear()));
    connect(buttonimage, SIGNAL(clicked()), this, SLOT(pressSendI()));
    connect(buttoncontact,SIGNAL(clicked()),this, SLOT(pressSendC()));
    connect(removemessage, SIGNAL(clicked()),this,SLOT(removing()));

}

UozAppview::~UozAppview(){
    delete chat;
    delete textbox;
    delete p;
    delete buttonimage;
    delete buttoncontact;
    delete searchmessage;
    delete removemessage;
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
    showMessageOnBrowser(m,chat, false);
}

void UozAppview::showmessagereceived(message* m){
    showMessageOnBrowser(m,chat, true);
}

void UozAppview::showMessageOnBrowser(message* m, QTextBrowser* b, bool rec){
    if(dynamic_cast<textmessage*>(m)){
        QString text4chat="<";
        if(rec)text4chat.append(receiver);
        else text4chat.append(sender);
        text4chat.append("> ");
        text4chat.append(dynamic_cast<textmessage*>(m)->getText());
        text4chat=text4chat.rightJustified(8);
        b->append(text4chat);
    }
    if(dynamic_cast<imagemessage*>(m)){
        QString text4chat="<";
        if(rec)text4chat.append(receiver);
        else text4chat.append(sender);
        text4chat.append("> ");
        text4chat.append("send an image:");
        chat->append(text4chat);
        QTextDocumentFragment fragment;
        QString url=QString("<img src='").append(dynamic_cast<imagemessage*>(m)->geturl()).append(QString("'>"));
        fragment = QTextDocumentFragment::fromHtml(url);
        b->textCursor().insertFragment(fragment);
        b->setVisible(true);
        if(dynamic_cast<imagemessage*>(m)->getdescription()!=nullptr){
            b->append(QString("description: ").append(dynamic_cast<imagemessage*>(m)->getdescription()));
        }
    }
    else if(dynamic_cast<contactmessage*>(m)){
        QString text4chat="<";
        if(rec)text4chat.append(receiver);
        else text4chat.append(sender);
        text4chat.append("> ");
        text4chat.append("send a contact:");
        b->append(text4chat);
        contactmessage* contact=dynamic_cast<contactmessage*>(m);
        b->append(QString("Name: ").append(contact->getname()));
        b->append(QString("Surname: ").append(contact->getsurname()));
        b->append(QString("nickname: ").append(contact->getnickname()));
        b->append(QString("Prefix: ").append(QString(contact->getprefix())));
        b->append(QString("Number: ").append(QString(contact->getnumber())));
    }
}

void UozAppview::searching(){
    QWidget* textpage=new QWidget();
    QGridLayout* layout=new QGridLayout();
    QLabel* ltext=new QLabel("search a word",textpage);
    layout->addWidget(ltext,1,0);
    QLineEdit* text= new QLineEdit(textpage);
    layout->addWidget(text,1,1);
    QPushButton* start=new QPushButton("start search",textpage);
    layout->addWidget(start,2,1);
    connect(start, &QPushButton::clicked, controller, [this,text,textpage](){controller->searchSomething(text->text(), this, textpage);});
    textpage->setLayout(layout);    
    textpage->show();
}

void UozAppview::showResult(ContainerList<message*> c, QWidget* w){
        if(!c.vuota()){
            QTextBrowser* brow=new QTextBrowser();
            QGridLayout* layout=dynamic_cast<QGridLayout*>(w->layout());
            if(layout){
                layout->addWidget(brow, 2,0);
                layout->rowStretch(2);
                for (auto it=c.begin();it!=c.end();++it) {
                    showMessageOnBrowser(c[it],brow, c[it]->getreceive());
                }
                w->setLayout(layout);
            }
        }
        else{
            QMessageBox msg(this);
            msg.setText("no result");
            msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            msg.setDefaultButton(QMessageBox::Ok);
            int ret = msg.exec();
            if(ret == QMessageBox::Ok){
                w->close();
                searching();
            }
            else{
                w->close();
            }
        }
}

void UozAppview::removing(){
    QWidget* textpage=new QWidget();
    QGridLayout* layout=new QGridLayout();
    QLabel* ltext=new QLabel("search a message to remove",textpage);
    layout->addWidget(ltext,1,0);
    QLineEdit* text= new QLineEdit(textpage);
    layout->addWidget(text,1,1);
    QPushButton* start=new QPushButton("start search",textpage);
    layout->addWidget(start,2,1);
    connect(start, &QPushButton::clicked, controller, [this,text,textpage](){controller->removeSomething(text->text(), this, textpage);});
    textpage->setLayout(layout);
    textpage->show();
}

void UozAppview::clearChat(){
    chat->clear();
}

void UozAppview::showmessageremoved(message * m){
    controller->reloadChat(this);
}

void UozAppview::showMessageOnChat(message * m, bool rec){
    showMessageOnBrowser(m,chat,rec);
}
