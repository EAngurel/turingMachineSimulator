#include "machine.h"
#include "ui_machine.h"
#include "codeeditor.h"
#include "node.h"
#include <QSlider>
#include <QStyle>
#include <QToolButton>
#include "node.h"
#include "graphwidget.h"





machine::machine(QWidget *parent) :
    QMainWindow(parent)
  , ui(new Ui::machine)
  , playButton(0)
  , stopButton(0)
  , nextButton(0)
  , previousButton(0)
{
    ui->setupUi(this);
    //ui->horizontalLayout_2->addWidget(&cinta);
    ui->verticalLayout->addWidget(&editor);

    playButton = new QToolButton(this);
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    connect(playButton, SIGNAL(clicked()), this, SLOT(playClicked()));

    stopButton = new QToolButton(this);
    stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    stopButton->setEnabled(false);

    connect(stopButton, SIGNAL(clicked()), this, SIGNAL(stop()));

    nextButton = new QToolButton(this);
    nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));

    connect(nextButton, SIGNAL(clicked()), this, SIGNAL(next()));

    previousButton = new QToolButton(this);
    previousButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));

    connect(previousButton, SIGNAL(clicked()), this, SIGNAL(previous()));

    ui->horizontalLayout->setMargin(0);
    ui->horizontalLayout->addWidget(stopButton);
    ui->horizontalLayout->addWidget(previousButton);
    ui->horizontalLayout->addWidget(playButton);
    ui->horizontalLayout->addWidget(nextButton);

    int x = 10;
    for(size_t i = 0;i < 20;++i)
    {
        QLineEdit * car = new QLineEdit(ui->groupBox);
        car->setGeometry(x,20,32,32);
        car->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QFont _font = car->font();
        _font.setPointSize(16);
        const QFont __font = _font;
        car->setFont(__font);
        car->show();
        car->setReadOnly(true);
        car->setText("$");
        caracteres.push_back(car);
        x+=37;
    }
}

machine::~machine()
{
    delete ui;
}

