#ifndef MACHINE_H
#define MACHINE_H
#include "Config.h"
#include <list>
#include "Mov.h"
#include <QMainWindow>
#include "codeeditor.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QBrush>
#include <QColor>
//#include <QTest>
#include <QPalette>
#include <QListIterator>
#include <QString>
#include "parser.h"
#include "playercontroller.h"


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
    void setLECinta(int);
    void Runcode();
    void paintLine(int);
    void MoveCinta(char dir);
    void Takepos();
signals:
    void play();
    void pause();
    void stop();
    void next();
    void previous();

private slots:
    void on_pushButton_clicked();
    void playClicked();
    void sotpClicked();
    void nextClicked();
    void previousClicked();
    void on_submit_clicked();
    void on_exeCode_finished();

private:
    Ui::machine *ui;

    playercontroller *exeCode;
    QList<Config> conf;
    QList<Mov> moves;
    QList<string> stef;
    QList<Erros> errors;
    string eRor;
    string state_act;
    CodeEditor editor;
    QAbstractButton *playButton;
    QAbstractButton *stopButton;
    QAbstractButton *nextButton;
    QAbstractButton *previousButton;
    QList<QLineEdit*> caracteres;
    QList<QRect> geom;
    QRect rec;
    list<char> alfabet;
    QListIterator<QLineEdit*> iter(const &caracteres);
    int x = 10;
    int pointer;
    int begi=50;
    bool run;
};

#endif // MACHINE_H
