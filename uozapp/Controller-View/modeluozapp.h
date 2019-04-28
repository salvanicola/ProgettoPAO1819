#ifndef MODELUOZAPP_H
#define MODELUOZAPP_H

#include <QObject>
#include "./QontainerList/containerlist.h"
#include "./source/message.h"
#include "./source/imagemessage.h"
#include "./source/textmessage.h"
#include "./source/contactmessage.h"

class Modeluozapp : public QObject
{
    Q_OBJECT
public:
    explicit Modeluozapp(QObject *parent = nullptr);
private:
    ContainerList<message*> v;
signals:
    void newmessage();
    void messagereceive(message* );
    //void messageremoved();
    void messagesend(message* );
public slots:
    message* sendmessage(ContainerList<QString>*, QString ="uknown", QString="uknown");
    void receivemessage(message* );
    //void removemessage(message* )
};

#endif // MODELUOZAPP_H
