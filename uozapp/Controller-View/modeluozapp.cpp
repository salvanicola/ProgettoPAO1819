#include "modeluozapp.h"

Modeluozapp::Modeluozapp(QObject *parent) : QObject(parent)
{

}


message* Modeluozapp::sendmessage(QString text, QString sender, QString receiver, QString urlimg){
    if(urlimg!=nullptr){
        imagemessage* image=new imagemessage(false, urlimg, sender, receiver, text);
        v.push_back(image);
        emit messagesend(image);
        return image;
    }
    else{
        textmessage* mex= new textmessage(false, sender, receiver, text);
        v.push_back(mex);
        textmessage* tosend=mex->sendmex();
        emit messagesend(mex);
        return tosend;        
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
