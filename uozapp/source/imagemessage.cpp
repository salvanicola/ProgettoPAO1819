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

QDataStream& operator<<(QDataStream& out, const imagemessage& m){
    out <<QString("imagemessage") << m.getSender() << m.getReceiver() << m.getDate()->toString() << QString(m.getreceive()) << m.url << m.description;
    return out;
}

bool imagemessage::similarImage(const QString & t){
    return description.contains(t);
}

bool imagemessage::operator==(const imagemessage & t){
    if(message::operator==(t) && url==t.url && description==t.description) return true;
    else return false;
}
