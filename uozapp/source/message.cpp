#include "message.h"

message::message(bool f, QString s, QString r): sender(s), receiver(r), date(new QDateTime(QDateTime::currentDateTime())), receive(f){

}

void message::setsend(){
    if(receive)receive=false;
}

void message::setreceive(){
    if(!receive){
        receive=true;
    }
}

const QDateTime* message::getDate() const{
    return date;
}

bool message::getreceive() const{
    return receive;
}

bool message::operator==(const message & m){
    if(sender==m.sender  && receiver == m.receiver && date == m.date) return true;
    else return false;
}

QString message::getSender() const{
    return sender;
}

QString message::getReceiver() const{
    return receiver;
}
