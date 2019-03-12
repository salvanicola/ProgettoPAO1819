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
    setsend();
    return new textmessage(*this);
}

textmessage* textmessage::receivemex(){
    setreceive();
    return new textmessage(*this);
}
