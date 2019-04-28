#ifndef CONTACTMESSAGE_H
#define CONTACTMESSAGE_H
#include <QString>
#include "message.h"


class contactmessage: public message
{
private:
    QString name;
    QString surname;
    QString nickname;
    char number[10];
    char prefix[2];
public:
    contactmessage();
    contactmessage(bool, char[10], char[2], QString="uknown", QString="uknown", QString=nullptr, QString=nullptr, QString=nullptr);
    virtual ~contactmessage()override = default;
    QString getname()const;
    QString getsurname()const;
    QString getnickname()const;
    const char* getnumber()const;
    const char* getprefix()const;
    virtual contactmessage* sendmex()override;
};

#endif // CONTACTMESSAGE_H