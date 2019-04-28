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
}

void ControlCore::sendATMessage(UozAppview* v){
    ContainerList<QString>* data=new ContainerList<QString>();
    if(v==view1){
        data->push_back(v->getText());
        message* toreceive=model1->sendmessage(data, (v->getsender()), (v->getreceiver()));
        model2->receivemessage(toreceive);
    }
    else{
        data->push_back(v->getText());
        message* toreceive=model2->sendmessage(data, (v->getsender()), (v->getreceiver()));
        model1->receivemessage(toreceive);
    }
}

void ControlCore::sendAIMessage(UozAppview *v, QString file){
    ContainerList<QString>* data=new ContainerList<QString>();
    if(v==view1){
        data->push_back(v->getText());
        data->push_back(file);
        message* toreceive=model1->sendmessage(data, (v->getsender()), (v->getreceiver()));
        model2->receivemessage(toreceive);
    }
    else{
        data->push_back(v->getText());
        data->push_back(file);
        message* toreceive=model2->sendmessage(data, (v->getsender()), (v->getreceiver()));
        model1->receivemessage(toreceive);
    }
}

void ControlCore::sendACMEssage(UozAppview* v, QString n,QString c, QString nick, QString p, QString num){

}

