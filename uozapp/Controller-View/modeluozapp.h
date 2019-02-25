#ifndef MODELUOZAPP_H
#define MODELUOZAPP_H

#include <QObject>
#include "./QontainerList/containerlist.h"
#include "./source/message.h"
#include "./source/imagemessage.h"
#include "./source/textmessage.h"

class Modeluozapp : public QObject
{
    Q_OBJECT
public:
    static Modeluozapp* getinstance();
private:
    ContainerList<message*> v;
    explicit Modeluozapp(QObject *parent = nullptr);
    static Modeluozapp* themodel;//unique model
signals:
    void newmessage();
    void messagereceived(message* );
    //void messageremoved();
    void messagesend(message* );
    message* answeringto(message* );
public slots:
    message* sendmessage(QString, QString ="uknown", QString="uknown", message* =nullptr, QString=nullptr);
    void receivemessage(message* );
    //void removemessage(message* )
};

#endif // MODELUOZAPP_H
