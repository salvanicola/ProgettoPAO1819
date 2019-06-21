#include "modeluozapp.h"

Modeluozapp::Modeluozapp(ControlCore* c, QObject *parent) : QObject (parent), core(c)
{


}


message* Modeluozapp::sendmessage(ContainerList<QString>* content, QString sender, QString receiver){
    ContainerList<QString>::iterator it=content->begin();
    int sizing=content->size();
    if(sizing>2){
        contactmessage* contact=new contactmessage(false,(*content)[it].toLocal8Bit().data(),(*content)[++it].toLocal8Bit().data(),sender, receiver, (*content)[++it],(*content)[++it],(*content)[++it]);
        v.push_back(contact);
        emit messagesend(contact);
        return contact;
    }
    else if(sizing==2){
        imagemessage* image=new imagemessage(false, (*content)[it], sender, receiver, (*content)[++it]);
        v.push_back(image);
        emit messagesend(image);
        return image;
    }
    else if(sizing==1){
        textmessage* mex= new textmessage(false, sender, receiver, (*content)[it]);
        v.push_back(mex);
        textmessage* tosend=mex->sendmex();
        emit messagesend(mex);
        return tosend;        
    }
    else{
        return nullptr;//errore messaggio vuoto
    }
}

void Modeluozapp::receivemessage(message* m){
    if(m!=nullptr){
        v.push_back(m);
        emit messagereceive(m);
    }
}

QDataStream& operator <<(QDataStream& os, const Modeluozapp& m){
    for (auto it=m.v.begin() ; it!=nullptr; ++it) {
        if(dynamic_cast<textmessage*>(m.v[it])){
            os << QString("continue");
            os << *(dynamic_cast<textmessage*>(m.v[it]));
        }
        if(dynamic_cast<imagemessage*>(m.v[it])){
            os << QString("continue");
            os << *(dynamic_cast<imagemessage*>(m.v[it]));
        }
        if(dynamic_cast<contactmessage*>(m.v[it])){
            os << QString("continue");
            os << *(dynamic_cast<contactmessage*>(m.v[it]));
        }
    }
    os << QString("stop");
    return os;
}

QDataStream& operator >>(QDataStream& in, Modeluozapp& m){
    QString status;
    in >> status;
    while(in.status() != QDataStream::ReadPastEnd && status!=QString("stop") && status==QString("continue")){
        ContainerList<QString>* data=new ContainerList<QString>();
        QString type;
        in >> type;
        if(type==QString("textmessage")){
            QString send;
            in >> send;
            QString rec;
            in >> rec;
            QString da;
            in >> da;
            QString boo;
            in >> boo;
            QString text;
            in >> text;
            data->push_back(text);
            m.sendmessage(data, send, rec);
        }
        else if(type==QString("imagemessage")){
            QString send;
            in >> send;
            QString rec;
            in >> rec;
            QString da;
            in >> da;
            QString boo;
            in >> boo;
            QString url;
            in >> url;
            QString description;
            in >>description;
            data->push_back(url);
            data->push_back(description);
            m.sendmessage(data, send, rec);
        }
        else if(type==QString("contactmessage")){
            QString send;
            in >> send;
            QString rec;
            in >> rec;
            QString da;
            in >> da;
            QString boo;
            in >> boo;
            QString name;
            in >> name;
            QString surname;
            in >> surname;
            QString nick;
            in >> nick;
            QString num;
            in >> num;
            QString pr;
            in >> pr;
            num.remove("\t");
            pr.remove("\t");
            data->push_back(num);
            data->push_back(pr);
            data->push_back(name);
            data->push_back(surname);
            data->push_back(nick);
            m.sendmessage(data, send, rec);
        }
        in >> status;
        delete data;
    }
    return in;
}

ContainerList<message*> Modeluozapp::searchThis(const QString& s){
    ContainerList<message*> c;
    ContainerList<message* >::iterator it=v.begin();
    for (;it!=v.end();++it) {
        if(dynamic_cast<textmessage*>(v[it]) && dynamic_cast<textmessage*>(v[it])->similarText(s)){
            c.push_back(v[it]);
        }
        else if(dynamic_cast<imagemessage*>(v[it]) && dynamic_cast<imagemessage*>(v[it])->similarImage(s)){
            c.push_back(v[it]);
        }
        else if(dynamic_cast<contactmessage*>(v[it]) && dynamic_cast<contactmessage*>(v[it])->similarContact(s)){
            c.push_back(v[it]);
        }
    }
    return c;
}

void Modeluozapp::removeThisMessage(ContainerList<message*> c){
    ContainerList<message* >::iterator it=c.begin();
    for (;it!=c.end();++it) {
        int sizebef= v.size();
        message* torem;
        if(dynamic_cast<textmessage*>(c[it])) torem=new textmessage(*dynamic_cast<textmessage*>(c[it]));
        else if(dynamic_cast<imagemessage*>(c[it])) torem=new imagemessage(*dynamic_cast<imagemessage*>(c[it]));
        else if(dynamic_cast<contactmessage*>(c[it])) torem=new contactmessage(*dynamic_cast<contactmessage*>(c[it]));
        v.remove(c[it]);
        int sizenow=v.size();
        if(sizebef==sizenow+1) {
            emit removesuccess(torem);
        }
        else emit failedremove();
    }
}

message* Modeluozapp::operator[](ContainerList<message*>::const_iterator it)const{
    return v[it];
}

message* Modeluozapp::operator[](ContainerList<message*>::iterator it){
    return v[it];
}

bool Modeluozapp::empty() const{
    return v.vuota();
}

ContainerList<message*>::const_iterator Modeluozapp::begin()const{
    return v.begin();
}

ContainerList<message*>::iterator Modeluozapp::begin(){
    return v.begin();
}


ContainerList<message*>::const_iterator Modeluozapp::end()const{
    return v.end();
}

ContainerList<message*>::iterator Modeluozapp::end(){
    return v.end();
}

