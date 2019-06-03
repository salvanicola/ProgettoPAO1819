#include "contactmessage.h"

contactmessage::contactmessage(bool f, char num[10], char pref[2], QString m, QString d, QString na, QString sur, QString nick): message(f,m,d), name(na), surname(sur), nickname(nick)
{
    for(int i=0; i<10;++i) number[i]=num[i];
    for(int i=0;i<2; i++) prefix[i]=pref[i];
}

QString contactmessage::getname()const{
    return name;
}
QString contactmessage::getsurname()const{
    return surname;
}
QString contactmessage::getnickname()const{
    return nickname;
}
const char* contactmessage::getnumber()const{
    return number;
}
const char* contactmessage::getprefix()const{
    return prefix;
}
contactmessage* contactmessage::sendmex(){
    contactmessage* aux= new contactmessage(*this);
    setreceive();
    return aux;
}

QDataStream& operator<<(QDataStream& out, const contactmessage& m){
    QString num(m.number);
    QString pr(m.prefix);
    out << QString("contactmessage") << m.getSender() << m.getReceiver() << m.getDate()->toString() << QString(m.getreceive()) << m.name << m.surname << m.nickname << num  << pr;
    return out;
}

bool contactmessage::similarContact(const QString& t){
    ContainerList<QString> c;
    if(t == name) return true;
    if(t == surname)  return true;
    if(t == nickname) return true;
    else return false;
    /*bool control=true;
    for(int i=0; i < 10 && control; ++i){
         if(i < 2) control = (prefix[i]==t);
         else control = false;
         if(control) control = (number[i]==t);
         else control = false;
    }
    if(control) c.push_back("number");*/
}

bool contactmessage::operator==(const contactmessage & t){
    if(message::operator==(t) && name==t.name && surname==t.surname && nickname==t.nickname){
        bool control=true;
        for(int i=0; i < 10 && control; ++i){
            if(i < 2) control = (prefix[i]==t.prefix[i]);
            else control = false;
            if(control) control = (number[i]==t.number[i]);
            else control = false;
        }
        return control;
    }
    else return false;
}
