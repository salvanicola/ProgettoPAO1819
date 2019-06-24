#include "textmessage.h"

textmessage::textmessage(bool r,QString m, QString d, QString s): message(r,m,d), text(s)
{

}

void textmessage::write(QString t){
    text.append(t);
}

int textmessage::getlenght()const{
    return text.length();
}

textmessage* textmessage::sendmex(){
    textmessage* aux= new textmessage(*this);
    aux->setreceive();
    return aux;
}

QString textmessage::getText() const{
    return text;
}

QDataStream& operator << (QDataStream& out, const textmessage& m){
    out << QString("textmessage") << m.getSender() << m.getReceiver() << m.getDate()->toString() << QString(m.getreceive()) << m.getText();
    return out;
}

bool textmessage::similar(const QString& t)const{
    return text.contains(t);
}

bool textmessage::operator==(const textmessage & t){
    if(message::operator==(t) && text==t.text) return true;
    else return false;
}
