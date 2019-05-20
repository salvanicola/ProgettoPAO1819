#ifndef IMAGEMESSAGE_H
#define IMAGEMESSAGE_H
#include <QString>
#include "message.h"

class imagemessage: public message
{
private:
    QString url;
    QString description;
protected:
    virtual void changeimg(QString );
public:
    imagemessage();
    imagemessage(bool, QString, QString="uknown", QString="uknown", QString =nullptr);
    virtual ~imagemessage()override = default ;
    QString geturl()const;
    QString getdescription()const;//may return nullptr
    virtual imagemessage* sendmex()override;
    friend QDataStream& operator<<(QDataStream& , const imagemessage& );
};

#endif // IMAGEMESSAGE_H
