#include "imagemessage.h"

imagemessage::imagemessage(bool r, QString u, QString m, QString d, QString desc): message(r,m,d), url(u), description(desc)
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
    setsend();
    return new imagemessage(*this);
}

imagemessage* imagemessage::receivemex(){
    setreceive();
    return new imagemessage(*this);
}
