#include "mainwindow.h"
#include <QLabel>
#include "Controller-View/controlcore.h"
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QApplication>
#include <QDesktopWidget>


mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent)
{
    resize(QDesktopWidget().availableGeometry(this).size()*0.7);
    QWidget* w=new QWidget(this);
    QGridLayout* layout=new QGridLayout(w);
    setWindowTitle("Uozapp");
    QLineEdit* nameedit=new QLineEdit(this);
    QLineEdit* sendtoedit=new QLineEdit(this);
    nameedit->setPlaceholderText("chat name 1");
    sendtoedit->setPlaceholderText("chat name 2");
    layout->addWidget(nameedit, 1, 0);
    layout->addWidget(sendtoedit, 1, 1);
    QPushButton* p=new QPushButton("New Chat");
    QPushButton *loadButton=new QPushButton("load");
    QPushButton *saveButton=new QPushButton("save");
    layout->addWidget(loadButton,3,0);
    layout->addWidget(saveButton,3,1);
    saveButton->setEnabled(false);
    ControlCore* core=new ControlCore(this);
    layout->addWidget(p ,2,1);
    QPushButton* quit=new QPushButton("close chat");
    layout->addWidget(quit,2,0);
    QPushButton* exit=new QPushButton("exit");
    layout->addWidget(exit,4,0);
    connect(p, &QPushButton::clicked, core, [=](){core->showchat(nameedit->text(), sendtoedit->text());});
    connect(p, &QPushButton::clicked, p, [p](){p->setEnabled(false);});
    connect(p, &QPushButton::clicked, saveButton, [saveButton](){saveButton->setEnabled(true);});
    connect(loadButton, &QPushButton::clicked, saveButton, [saveButton](){saveButton->setEnabled(true);});
    connect(exit, SIGNAL(clicked()), core, SLOT(closechat()));
    connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(quit, &QPushButton::clicked, p,[p](){p->setEnabled(true);});
    connect(quit, SIGNAL(clicked()), core, SLOT(closechat()));
    connect(saveButton, SIGNAL(clicked()), core, SLOT(saveToFile()));
    connect(loadButton, SIGNAL(clicked()), core, SLOT(loadFromFile()));
    setCentralWidget(w);
}
