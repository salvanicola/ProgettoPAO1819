#include "controlcore.h"
#include "uozappview.h"
#include "modeluozapp.h"

ControlCore::ControlCore(QObject *parent) : QObject(parent), model1(model1->getinstance()), model2(model2->getinstance()), view1(new UozAppview(this)), view2(new UozAppview(this)){}

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
    view1->show();
    view2->show();
}

void ControlCore::sendAMessage(UozAppview* v){
    model1->sendmessage(v->getText(), (v->getsender_receiver())[0], (v->getsender_receiver())[1]/*da mettere answer*/ /*damettereimmagine*/);
    view1->newMessage(v->getText(), (v->getsender_receiver())[0]);
    view2->newMessage(v->getText(), (v->getsender_receiver())[0]);
}
