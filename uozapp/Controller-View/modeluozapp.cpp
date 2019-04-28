#include "modeluozapp.h"

Modeluozapp::Modeluozapp(QObject *parent) : QObject(parent)
{

}


message* Modeluozapp::sendmessage(ContainerList<QString>* content, QString sender, QString receiver){
;    ContainerList<QString>::const_iterator it=content->begin();
/*
    if((*content)[it+2]!=nullptr){

        contactmessage* contact=new contactmessage(false,(*content)[it].toLocal8Bit().data(),(*content)[it++].toLocal8Bit().data(),sender, receiver, (*content)[it+2],(*content)[it+3],(*content)[it+4]);
        v.push_back(contact);
        emit messagesend(contact);
        return contact;
    }
    else */if((*content)[it++]!=nullptr){
        /*imagemessage* image=new imagemessage(false, (*content)[it++], sender, receiver, (*content)[it]);
        v.push_back(image);
        emit messagesend(image);
        return image;*/
    }
    else if((*content)[it]!=nullptr){
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

#include <iostream>

void Modeluozapp::receivemessage(message* m){
    if(m!=nullptr){
        v.push_back(m);
        emit messagereceive(m);
    }
    else{
        //eccezione da mettere
    }
}
