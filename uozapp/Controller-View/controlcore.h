#ifndef CONTROLCORE_H
#define CONTROLCORE_H

#include <QObject>
#include <QMainWindow>
#include <QMessageBox>

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
    void sendACMEssage(UozAppview*, QString,QString,QString,QString,QString);
    int getModelNum(Modeluozapp*);
signals:

public slots:
    void showchat(QString , QString );
    void saveToFile();
    void loadFromFile();
    void closechat();
    void searchSomething(const QString& , UozAppview* ,QWidget* );
    void removeSomething(const QString&, UozAppview*, QWidget* );
    void reloadChat(UozAppview* );
};

#endif // CONTROLCORE_H
