#include "machine.h"
#include "ui_machine.h"
#include "codeeditor.h"

machine::machine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::machine)
{
    ui->setupUi(this);

    ui->verticalLayout->addWidget(&editor);
}

machine::~machine()
{
    delete ui;
}
