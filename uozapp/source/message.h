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
protected:
    virtual void setreceive();
    virtual void setsend();
public:
    message(bool , QString ="uknown", QString ="uknown") ;
    virtual ~message() = default;
    virtual message* sendmex() = 0;//metodo di clonazione con specifica non costante perchè segna send=true
    virtual message* receivemex() = 0;//metodo di clonazione con specifica non costante perchè segna receive=true
};

#endif // MESSAGE_H. 0
