#include "mainwindow.h"
#include <QApplication>
#include "container.h"
#include <iostream>

int main(int argc, char *argv[])
{
    //test
    container<int>* c=new container<int>(4);
    c->add(0);
    c->add(3);
    c->add(2);
    c->add(1);
    c->at(0)=8;
    c->stmp();
    /*try {
        c->at(4)=3;
    } catch (const std::out_of_range& oor) {
        std::cerr << "out of range: " << oor.what() << std::endl;
    }*/
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}