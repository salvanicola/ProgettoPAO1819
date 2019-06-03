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
    bool operator ==(const textmessage& );
    bool similarText(const QString& );
    virtual textmessage* sendmex()override;
    friend QDataStream& operator<<(QDataStream& , const textmessage& );
    friend QDataStream& operator>>(QDataStream& , const textmessage& );
};

#endif // TEXTMESSAGE_H
