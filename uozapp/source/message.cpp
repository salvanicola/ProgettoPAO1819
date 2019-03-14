#include "message.h"

message::message(bool f, QString s, QString r): sender(s), receiver(r), date(new QDateTime(QDateTime::currentDateTime())), receive(f){

}

void message::setsend(){
    if(receive)receive=false;
}

void message::setreceive(){
    if(!receive)receive=true;
}

const QDateTime* message::getDate() const{
    return date;
}
