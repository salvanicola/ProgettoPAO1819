#ifndef CONTROLCORE_H
#define CONTROLCORE_H

#include <QObject>

class controlcore : public QObject
{
    Q_OBJECT
public:
    explicit controlcore(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CONTROLCORE_H