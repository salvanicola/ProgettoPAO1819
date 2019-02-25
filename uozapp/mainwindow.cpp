#include "mainwindow.h"
#include <QLabel>
#include "Controller-View/controlcore.h"
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QApplication>


mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget* w=new QWidget(this);
    QGridLayout* layout=new QGridLayout(w);
    setWindowTitle("Uozapp");
    QLabel* name=new QLabel("Chat Name 1", this);
    QLabel* sendto=new QLabel("Chat Name 2", this);
    layout->addWidget(name, 0,0);
    layout->addWidget(sendto, 0,1);
    QLineEdit* nameedit=new QLineEdit(this);
    QLineEdit* sendtoedit=new QLineEdit(this);
    layout->addWidget(nameedit, 1, 0);
    layout->addWidget(sendtoedit, 1, 1);
    QPushButton* p=new QPushButton("New Chat");
    ControlCore* core=new ControlCore(this);
    connect(p, &QPushButton::clicked, core, [=](){core->showchat(nameedit->text(), sendtoedit->text());});
    connect(p, &QPushButton::clicked, p, [p](){p->setEnabled(false);});
    //connect(p, &QPushButton::clicked, this, [this](){setWindowFlags(Qt::WindowTitleHint);});
    layout->addWidget(p ,2,1);
    QPushButton* quit=new QPushButton("exit");
    layout->addWidget(quit,2,0);
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    setCentralWidget(w);
}
