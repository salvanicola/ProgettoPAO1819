#include "modeluozapp.h"
#include <iostream>


Modeluozapp::Modeluozapp(QObject *parent) : QObject(parent)
{

}

message* Modeluozapp::sendmessage(QString text, QString sender, QString receiver, QString urlimg){
    if(urlimg!=nullptr){
        imagemessage* image=new imagemessage(false, urlimg, sender, receiver, text);
        imagemessage* tosend=image->sendmex();
        v.push_back(image);
        emit messagesend(tosend);
        return tosend;
    }
    else{
        textmessage* mex= new textmessage(false, sender, receiver, text);
        v.push_back(mex);
        textmessage* tosend=mex->sendmex();
        emit messagesend(tosend);
        return tosend;        
    }

}

void Modeluozapp::receivemessage(message* m){
    if(m!=nullptr){
        v.push_back(m);
        emit messagereceive(m);
    }
    else{
        //eccezione da mettere
    }
}
