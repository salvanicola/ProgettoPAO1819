#ifndef MODELUOZAPP_H
#define MODELUOZAPP_H

#include <QObject>
#include "controlcore.h"
#include "./QontainerList/containerlist.h"
#include "./source/message.h"
#include "./source/imagemessage.h"
#include "./source/textmessage.h"
#include "./source/contactmessage.h"

class Modeluozapp : public QObject
{
    Q_OBJECT
public:
    explicit Modeluozapp(ControlCore* ,QObject *parent = nullptr);
    virtual ~Modeluozapp();
private:
    ContainerList<message*> v;
    ControlCore* core;
signals:
    void newmessage();
    void messagereceive(message* );
    //void messageremoved();
    void messagesend(message* );
public slots:
    message* sendmessage(ContainerList<QString>*, QString ="uknown", QString="uknown");
    void receivemessage(message* );
    //void removemessage(message* )
    friend QDataStream& operator <<(QDataStream&, const Modeluozapp& );
    friend QDataStream& operator >>(QDataStream&, Modeluozapp& );
};

#endif // MODELUOZAPP_H
