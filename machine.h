#ifndef MACHINE_H
#define MACHINE_H

#include <QMainWindow>
#include "codeeditor.h"

namespace Ui {
class machine;
}

class machine : public QMainWindow
{
    Q_OBJECT

public:
    explicit machine(QWidget *parent = 0);
    ~machine();

private:
    Ui::machine *ui;

    CodeEditor editor;
};

#endif // MACHINE_H
