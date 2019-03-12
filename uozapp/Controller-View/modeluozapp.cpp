#include "modeluozapp.h"

Modeluozapp::Modeluozapp(QObject *parent) : QObject(parent)
{

}

void Modeluozapp::sendmessage(QString text, QString sender, QString receiver, QString urlimg){
    if(urlimg!=nullptr){
        imagemessage* image=new imagemessage(false, urlimg, sender, receiver, text);
        v.push_back(image);
    }
    else{
        textmessage* mex= new textmessage(false, sender, receiver, text);
        v.push_back(mex);
    }
}

void Modeluozapp::receivemessage(message* m){
    if(m!=nullptr){
        message* mexreceive=m->receivemex();
        v.push_back(mexreceive);
        emit messagereceived(mexreceive);
    }
}
