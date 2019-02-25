#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H
#include "message.h"

class textmessage: public message
{
private:
    QString text;
public:
    textmessage(QString="uknown", QString="uknown", message* =nullptr, QString ="");
    virtual ~textmessage()override = default;
    void write(QString );
    int getlenght()const;//size_t può essere convertito in int
    virtual textmessage* sendmex()override;
    virtual textmessage* receivemex()override;//non ritorna nulla
};

#endif // TEXTMESSAGE_H
