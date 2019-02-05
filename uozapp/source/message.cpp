#include "message.h"

message::message(QString s, QString r, message* m): sender(s), receiver(r), date(QDateTime::currentDateTime()), receive(false), send(false), read(false), answer(m){
    if(answer!=nullptr){
        receiver=answer->sender;
    }
}

void message::setread(){
    read=true;
}

void message::setsend(){
    send=true;
}

void message::setreceive(){
    receive=true;
}
