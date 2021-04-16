#include "mainwindow.h"

#include <QApplication>
#include <arrays/Set.h>

int main(int argc, char *argv[])
{
    Set set;
    set.add(5);
    set.add(1);
    set.print();

    set.add(1);
    set.add(6);
    set.print();

    set.add(-1);
    set.add(4);
    set.add(4);
    set.add(4);
    set.add(-5);
    set.add(-5);
    set.add(8);
    set.add(8);
    set.add(-3);
    set.print();

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
}
