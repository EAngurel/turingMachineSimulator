#ifndef MACHINE_H
#define MACHINE_H
#include "node.h"
#include <QMainWindow>
#include "codeeditor.h"
#include "graphwidget.h"
#include <QLineEdit>
#include <QFont>


QT_BEGIN_NAMESPACE
class QAbstractButton;
class QComboBox;
QT_END_NAMESPACE

namespace Ui {
class machine;
}

class machine : public QMainWindow
{
    Q_OBJECT

public:
    explicit machine(QWidget *parent = 0);
    ~machine();

signals:
    void play();
    void pause();
    void stop();
    void next();
    void previous();

private:
    Ui::machine *ui;

    CodeEditor editor;
    QAbstractButton *playButton;
    QAbstractButton *stopButton;
    QAbstractButton *nextButton;
    QAbstractButton *previousButton;
    //GraphWidget cinta;
    QList <QLineEdit*> caracteres;
};

#endif // MACHINE_H
