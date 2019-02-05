#ifndef MESSAGE_H
#define MESSAGE_H
#include <QDateTime>
#include <QString>

class message
{
private:
    QString sender;
    QString receiver;
    QDateTime date;//libreria Qt costr QDatetime(date, time) QDate(years, month, days) Qtime(h, m, s)
    //si riferisce alla data di creazione del messaggio
    bool receive;
    bool send;
    bool read;
    message* answer;
protected:
    virtual void setread();
    virtual void setsend();
    virtual void setreceive();
public:
    message(QString ="uknown", QString ="uknown", message* =nullptr) ;
    virtual ~message() = default;
    virtual message* sendmex() = 0;//metodo di clonazione con specifica non costante perchè segna send=true
    virtual message* receivemex() = 0;//metodo di clonazione con specifica non costante perchè segna receive=true
};

#endif // MESSAGE_H. 0
