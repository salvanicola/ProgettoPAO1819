#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H
#include "message.h"

class textmessage: public message
{
private:
    QString text;
public:
    textmessage(bool, QString="uknown", QString="uknown", QString ="");
    virtual ~textmessage()override = default;
    void write(QString );
    QString getText()const;
    int getlenght()const;//size_t può essere convertito in int
    virtual textmessage* sendmex()override;
};

#endif // TEXTMESSAGE_H
