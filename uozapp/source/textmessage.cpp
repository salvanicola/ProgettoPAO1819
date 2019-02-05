#include "textmessage.h"

textmessage::textmessage(QString m, QString d, message* a, QString s): message(m,d,a), text(s)
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
