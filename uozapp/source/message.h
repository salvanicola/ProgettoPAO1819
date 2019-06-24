#ifndef MESSAGE_H
#define MESSAGE_H
#include <QDateTime>
#include <QString>
#include "./QontainerList/containerlist.h"

class message
{
private:
    QString sender;
    QString receiver;
    const QDateTime* date;//libreria Qt costr QDatetime(date, time) QDate(years, month, days) Qtime(h, m, s)
    //si riferisce alla data di creazione del messaggio
    bool receive;
protected:
    virtual void setreceive();
    virtual void setsend();
    void setParam(QString, QString, QDateTime , bool );
public:
    message(bool , QString ="uknown", QString ="uknown") ;
    virtual ~message() = default;
    const QDateTime* getDate()const;
    bool getreceive()const;
    bool operator ==(const message& );
    QString getSender()const;
    QString getReceiver()const;
    virtual bool similar(const QString&)const = 0;
    virtual message* sendmex() = 0;//metodo di clonazione con specifica non costante perchè segna send=true    
};

#endif // MESSAGE_H. 0
