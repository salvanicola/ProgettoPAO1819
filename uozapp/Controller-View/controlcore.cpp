#include "controlcore.h"
#include "uozappview.h"
#include "modeluozapp.h"

ControlCore::ControlCore(QMainWindow *parent) : mainwindow(parent), model1(new Modeluozapp()), model2(new Modeluozapp()), view1(new UozAppview(this)), view2(new UozAppview(this))
{
    connect(model1, SIGNAL(messagesend(message* )),view1, SLOT(showmessagesent(message* )));
    connect(model2, SIGNAL(messagesend(message* )),view2, SLOT(showmessagesent(message* )));
    connect(model1, SIGNAL(messagereceive(message* )),view1, SLOT(showmessagereceived(message* )));
    connect(model2, SIGNAL(messagereceive(message* )),view2, SLOT(showmessagereceived(message* )));
}

void ControlCore::showchat(QString s1, QString s2){
    chatter1=s1;
    chatter2=s2;
    QString temp= s1;
    s1.append(" to ").append(s2);
    s2.append(" to ").append(temp);
    view1->setWindowTitle(s1);
    view2->setWindowTitle(s2);
    view1->setSender_Receiver(chatter1, chatter2);
    view2->setSender_Receiver(chatter2, chatter1);
    mainwindow->addDockWidget(Qt::LeftDockWidgetArea, view1);
    mainwindow->addDockWidget(Qt::RightDockWidgetArea, view2);
   /* view1->show();
    view2->show();*/
}

void ControlCore::sendAMessage(UozAppview* v){
    if(v==view1){
        message* toreceive=model1->sendmessage(v->getText(), (v->getsender()), (v->getreceiver())/*da mettere answer*/ /*damettereimmagine*/);
        model2->receivemessage(toreceive);
    }
    else{
        message* toreceive=model2->sendmessage(v->getText(), (v->getsender()), (v->getreceiver())/*da mettere answer*/ /*damettereimmagine*/);
        model1->receivemessage(toreceive);
    }
}
