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
    setreceive();
    return aux;
}

QString textmessage::getText() const{
    return text;
}
