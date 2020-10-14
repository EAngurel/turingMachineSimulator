#include "machine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    machine w;

    w.show();

    //Un comentario

    return a.exec();
}
