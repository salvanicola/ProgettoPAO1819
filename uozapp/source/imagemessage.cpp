#include "imagemessage.h"

imagemessage::imagemessage(bool f, QString u, QString m, QString d, QString desc): message(f,m,d), url(u), description(desc)
{

}

void imagemessage::changeimg(QString img){
    url=img;
}

QString imagemessage::geturl() const{
    return url;
}

QString imagemessage::getdescription() const{
    return description;
}

imagemessage* imagemessage::sendmex(){
    imagemessage* aux= new imagemessage(*this);
    setreceive();
    return aux;
}

