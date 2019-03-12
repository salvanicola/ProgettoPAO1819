#include "message.h"

message::message(bool o, QString s, QString r): sender(s), receiver(r), receive(o), date(QDateTime::currentDateTime()){

}

void message::setreceive(){
    if(!receive)receive=true;
}

void message::setsend(){
    if(receive) receive=false;
}
