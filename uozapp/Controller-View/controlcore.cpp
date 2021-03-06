#include "controlcore.h"
#include "uozappview.h"
#include "modeluozapp.h"

ControlCore::ControlCore(QMainWindow *parent) : QObject(parent), mainwindow(parent), model1(nullptr), model2(nullptr), view1(nullptr), view2(nullptr)
{

}
void ControlCore::showchat(QString s1, QString s2){
    chatter1=s1;
    chatter2=s2;
    model1=new Modeluozapp(this);
    model2=new Modeluozapp(this);
    view1=new UozAppview(this);
    view2=new UozAppview(this);
    connect(model1, SIGNAL(messagesend(message* )),view1, SLOT(showmessagesent(message* )));
    connect(model2, SIGNAL(messagesend(message* )),view2, SLOT(showmessagesent(message* )));
    connect(model1, SIGNAL(messagereceive(message* )),view1, SLOT(showmessagereceived(message* )));
    connect(model2, SIGNAL(messagereceive(message* )),view2, SLOT(showmessagereceived(message* )));
    connect(model1, SIGNAL(removesuccess(message* )),view1, SLOT(showmessageremoved(message* )));
    connect(model2, SIGNAL(removesuccess(message* )),view2, SLOT(showmessageremoved(message* )));
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
    data->push_back(v->getText());
    if(v==view1){
        message* toreceive=model1->sendmessage(data, (v->getsender()), (v->getreceiver()));
        model2->receivemessage(toreceive);
    }
    else{
        message* toreceive=model2->sendmessage(data, (v->getsender()), (v->getreceiver()));
        model1->receivemessage(toreceive);
    }
    delete data;
}

void ControlCore::sendAIMessage(UozAppview *v, QString file){
    ContainerList<QString>* data=new ContainerList<QString>();
    if(v==view1){     
        data->push_back(file);
        data->push_back(v->getText());
        message* toreceive=model1->sendmessage(data, (v->getsender()), (v->getreceiver()));
        model2->receivemessage(toreceive);
    }
    else{
        data->push_back(file);
        data->push_back(v->getText());      
        message* toreceive=model2->sendmessage(data, (v->getsender()), (v->getreceiver()));
        model1->receivemessage(toreceive);
    }
    delete data;
}

void ControlCore::sendACMEssage(UozAppview* v, QString n,QString c, QString nick, QString p, QString num){
    ContainerList<QString>* data=new ContainerList<QString>();
    if(v==view1){
        data->push_back(num);
        data->push_back(p);
        data->push_back(n);
        data->push_back(c);
        data->push_back(nick);
        data->push_back(v->getText());
        message* toreceive=model1->sendmessage(data, (v->getsender()), (v->getreceiver()));
        model2->receivemessage(toreceive);
    }
    else{
        data->push_back(num);
        data->push_back(p);
        data->push_back(n);
        data->push_back(c);
        data->push_back(nick);
        data->push_back(v->getText());
        message* toreceive=model2->sendmessage(data, (v->getsender()), (v->getreceiver()));
        model1->receivemessage(toreceive);
    }
    delete data;
}

void ControlCore::saveToFile(){
    QString fileName = QFileDialog::getSaveFileName(mainwindow,
           tr("Save Chat"), QDir::root().path(),
           tr("Chat Format (*.chf);;All Files (*)"));
    if (fileName.isEmpty())
            return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(mainwindow, tr("Unable to open file"),
            file.errorString());
            return;
        }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << chatter1;
        out << chatter2;
        out << *model1;
        out << *model2;
    }
}

void ControlCore::loadFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(mainwindow,
        tr("Open Address Book"), QDir::root().path(),
        tr("Chat Format (*.chf);;All Files (*)"));
    if (fileName.isEmpty())
           return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(mainwindow, tr("Unable to open file"),
            file.errorString());
            return;
        }
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        closechat();
        in >> chatter1;
        in >> chatter2;
        showchat(chatter1, chatter2);
        in >> *model1;
        in >> *model2;
    }
}

void ControlCore::closechat(){
    if(view1){
        QMessageBox msgBox;
        msgBox.setText("The chat has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        msgBox.setGeometry(259,110,826,460);
        int ret = msgBox.exec();
        if(ret==QMessageBox::Save){
              saveToFile();
        }
        else if(ret == QMessageBox::Discard){
            disconnect(view1);
            view1->close();
            view1=nullptr;
            if(view2){
                disconnect(view2);
                view2->close();
                view2=nullptr;
            }
            disconnect(model1);
            disconnect(model2);
            if(model1){
                delete model1;
                model2=nullptr;
            }
            if(model2){
                delete model2;
                model2=nullptr;
            }
        }
    }
}

int ControlCore::getModelNum(Modeluozapp *m){
    if(m==model1) return 1;
    if(m==model2)return 2;
    return 0;
}

void ControlCore::searchSomething(const QString& s, UozAppview* v, QWidget* w){
    if(!s.isEmpty()){
        if(view1 == v){
            ContainerList<message*> c=model1->searchThis(s);
            view1->showResult(c, w);
        }
        else if(view2 == v){
            ContainerList<message*> c=model2->searchThis(s);
            view2->showResult(c, w);
        }
    }
    else{
        QMessageBox msg(w);
        msg.setText("no Argument for search");
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msg.setDefaultButton(QMessageBox::Ok);
        int ret = msg.exec();
        if(ret == QMessageBox::Ok){
            w->focusWidget();
        }
        else{
            w->focusWidget();
        }
    }
}


void ControlCore::removeSomething(const QString& s, UozAppview* v, QWidget* w){
    if(!s.isEmpty()){
        if(view1 == v){
            ContainerList<message*> c=model1->searchThis(s);
            view1->showResult(c, w);
            QPushButton* rem=new QPushButton("remove");
            QGridLayout* layout=dynamic_cast<QGridLayout*>(w->layout());
            layout->addWidget(rem,3,1);
            connect(rem, &QPushButton::clicked, model1, [this,c](){model1->removeThisMessage(c);});
        }
        else if(view2 == v){
            ContainerList<message*> c=model2->searchThis(s);
            view2->showResult(c, w);
            QPushButton* rem=new QPushButton("remove");
            QGridLayout* layout=dynamic_cast<QGridLayout*>(w->layout());
            layout->addWidget(rem,3,1);
        }
    }
    else{
        QMessageBox msg(w);
        msg.setText("no Argument for search");
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);
        int ret = msg.exec();
        if(ret == QMessageBox::Ok){
            w->focusWidget();
        }
    }
}

void ControlCore::reloadChat(UozAppview* v){
    v->clearChat();
    Modeluozapp* m;
    if(v==view1)m=model1;
    else m=model2;
    if(m->empty()==false){
        for(auto it=m->begin(); it!=m->end(); ++it){
            v->showMessageOnChat((*m)[it]);
        }
    }
}
