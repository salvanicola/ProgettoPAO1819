#ifndef CONTROLCORE_H
#define CONTROLCORE_H

#include <QObject>
#include <QMainWindow>

class UozAppview;
class Modeluozapp;//necessari per inclusione incrociata dei file .h che darebbe errore sull'ifndef

class ControlCore : public QObject
{
    Q_OBJECT
private:
    QMainWindow* mainwindow;
    Modeluozapp* model1;
    Modeluozapp* model2;
    UozAppview* view1;
    UozAppview* view2;
    QString chatter1;
    QString chatter2;
public:
    explicit ControlCore(QMainWindow *parent = nullptr);
    void sendATMessage(UozAppview* );
    void sendAIMessage(UozAppview* , QString);
signals:

public slots:
    void showchat(QString , QString );    
};

#endif // CONTROLCORE_H
