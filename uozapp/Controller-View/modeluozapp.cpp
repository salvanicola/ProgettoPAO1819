#include "modeluozapp.h"
#include <iostream>

Modeluozapp* Modeluozapp::themodel = nullptr;

Modeluozapp* Modeluozapp::getinstance(){
    if(!themodel){
        themodel=new Modeluozapp();
    }
    return themodel;
}

Modeluozapp::Modeluozapp(QObject *parent) : QObject(parent)
{
    if(themodel==this){
        themodel=nullptr;
    }
}

message* Modeluozapp::sendmessage(QString text, QString sender, QString receiver, message* answer, QString urlimg){
    if(urlimg!=nullptr){
        imagemessage* image=new imagemessage(urlimg, sender, receiver, answer, text);
        imagemessage* tosend=image->sendmex();
        v.push_back(image);
        return tosend;
    }
    else{
        textmessage* mex= new textmessage(sender, receiver, answer, text);
        v.push_back(mex);
        textmessage* tosend=mex->sendmex();
        return tosend;
    }
    if (answer)emit answeringto(answer);
}

void Modeluozapp::receivemessage(message* m){
    if(m!=nullptr){
        message* mexreceive=m->receivemex();
        v.push_back(mexreceive);
        std::cout<<"puzzi";
        emit messagereceived(mexreceive);
    }
}
