#ifndef IMAGEMESSAGE_H
#define IMAGEMESSAGE_H
#include <QString>
#include "message.h"

class imagemessage: public message
{
private:
    QString url;//usa QPixmap
    QString description;
public:
    imagemessage();
    imagemessage(bool, QString , QString="uknown", QString ="uknown", QString=nullptr);
    virtual ~imagemessage()override = default ;
    virtual void changeimg(QString );
    QString geturl()const;
    QString getdescription()const;
    virtual imagemessage* sendmex()override;
    virtual imagemessage* receivemex()override;
};

#endif // IMAGEMESSAGE_H
