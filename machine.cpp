#include "machine.h"
#include "ui_machine.h"
#include "codeeditor.h"
#include "Config.h"
#include "Mov.h"
#include <QSlider>
#include <QList>
#include <QPalette>
#include <QLayout>
#include <QStyle>
#include <QToolButton>





machine::machine(QWidget *parent) :
    QMainWindow(parent)
  , ui(new Ui::machine)
  , playButton(0)
  , stopButton(0)
  , nextButton(0)
  , previousButton(0)
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(&editor);
    exeCode = new playercontroller();
    connect(exeCode,SIGNAL(moving()),this,SLOT(on_exeCode_finished()));
    playButton = new QToolButton(this);
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    playButton->setEnabled(false);
    connect(playButton, SIGNAL(clicked()), this, SLOT(playClicked()));

    stopButton = new QToolButton(this);
    stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    stopButton->setEnabled(false);

    connect(stopButton, SIGNAL(clicked()), this, SLOT(sotpClicked()));

    nextButton = new QToolButton(this);
    nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    nextButton->setEnabled(false);
    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextClicked()));

    previousButton = new QToolButton(this);
    previousButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    previousButton->setEnabled(false);
    connect(previousButton, SIGNAL(clicked()), this, SLOT(previousClicked()));

    ui->horizontalLayout->setMargin(0);
    ui->horizontalLayout->addWidget(stopButton);
    ui->horizontalLayout->addWidget(previousButton);
    ui->horizontalLayout->addWidget(playButton);
    ui->horizontalLayout->addWidget(nextButton);
    setLECinta(100);
    int numcint;
    for(int i = 0; i < 45;i++){
        foreach(QLineEdit* edit , caracteres){
            numcint = edit->geometry().x()-37;
            edit->setGeometry(numcint,edit->geometry().y(),edit->geometry().width(),edit->geometry().height());
    }
    }
    Takepos();

}

machine::~machine()
{
    delete ui;
}
void machine::Runcode(){
    QString carac_conf;
    QString carct_cinta = caracteres[pointer]->text();
    ui->label_4->setText(QString::fromStdString(state_act));
    for(int i=0;i<conf.size();i++) {
        carac_conf.clear();
        carac_conf.push_back(conf[i].getCharacter());
        if(conf[i].getState()==state_act && carac_conf == carct_cinta){
            paintLine(conf[i].getLineNumber());
            caracteres[pointer]->setText(carac_conf);
            state_act = moves[i].getState();
            ui->label_4->setText(QString::fromStdString(state_act));
            if(state_act == eRor){
                ui->label_3->setText("Rechazado");
                //Cambiarle el color de las letras a rojo
                QColor color(255,0,0);
                QBrush brush(color);
                QPalette _palet = ui->label_3->palette();
                _palet.setBrush(QPalette::WindowText,brush);
                ui->label_3->setPalette(_palet);
                break;
            }
            else if(stef.contains(state_act)){
                ui->label_3->setText("Aceptado");
                //Cambiarle el color de las letras a verde
                QColor color(0,255,0);
                QBrush brush(color);
                QPalette _palet = ui->label_3->palette();
                _palet.setBrush(QPalette::WindowText,brush);
                ui->label_3->setPalette(_palet);
                break;
            }
            if(moves[i].getMove()=='I'){
                pointer--;
                MoveCinta('I');
            }
            if(moves[i].getMove()=='D'){
                pointer++;
                MoveCinta('D');
            }
            break;
        }
    }

}
void machine::setLECinta(int tam)
{

    //int x = 10;
    for(size_t i = 0;i < tam;++i)
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
    Takepos();
}

void machine::on_pushButton_clicked()
{
    errors.clear();
    conf.clear();
    moves.clear();
    QMessageBox mess;
    eRor = "";
    QString text = editor.toPlainText();
    Parser pars(text.toStdString());
    foreach (Erros var, pars.getErrorList()) {
       errors.push_back(var);
    }
    if(errors.isEmpty()){
    // conf = pars.getConfgList();
    foreach (Config var, pars.getConfgList()) {
       conf.push_back(var);
    }
   // moves = pars.getMovList();
    foreach (Mov var, pars.getMovList()) {
       moves.push_back(var);
    }
     // stef = pars.getFinalStatesList()
    foreach (string var, pars.getFinalStatesList()) {
       stef.push_back(var);
    }
    for(char ch : pars.getAlphabet()){
        alfabet.push_back(ch);
    }
    eRor = pars.getErrorState();
    state_act = conf[0].getState();
    paintLine(conf[0].getLineNumber());
    ui->label_4->setText(QString::fromStdString(state_act));
    mess.setText("Compilación Satisfactoria.");
    QColor color(0,180,0);
    QBrush brush(color);
    QPalette _palet = ui->label_3->palette();
    _palet.setBrush(QPalette::WindowText,brush);
    mess.setPalette(_palet);
    QFont fon;
    fon.setPointSize(24);
    mess.setFont(fon);
    QFont fon1;
    fon1.setPointSize(12);
    mess.addButton(QMessageBox::Ok)->setFont(fon1);
    //mess.button(QMessageBox::Ok)->setFont(fon1);
    mess.exec();
    playButton->setEnabled(true);
    previousButton->setEnabled(true);
    nextButton->setEnabled(true);
    ui->submit->setEnabled(true);
    }
    else{

        mess.setIcon(QMessageBox::Critical);
        QString details;
        int canterros = 0;
        foreach (Erros var, errors) {
           details += "Error en linea " + QString::number(var.getNline())+": " + "-- "+ QString::fromStdString(var.getMsgerr())+'\n';
           canterros ++;

        }
        mess.setDetailedText(details);
        mess.setText("Compilation Failed              ");
        mess.setInformativeText(QString::number(canterros)+" Errores encontrados.");
        mess.setFixedWidth(250);
        mess.exec();
    }
}

void machine::on_submit_clicked()
{
    QString text = ui->lineEdit->text();
    if(text.length()>(caracteres.length()-begi)){
        setLECinta(text.length());
    }
    for(int i=begi;i<caracteres.size();i++){
        if((i-begi)<text.length()){
        caracteres[i]->setText((QString)text[i-begi]);
        }
        else{
            caracteres[i]->setText("$");
        }
    }
    if(!conf.isEmpty()){
    state_act = conf[0].getState();
    }
    QString alpha;
    for(char ch1 : alfabet){
        alpha.push_back(ch1);
    }
    for(QChar ch : text){
        if(!alpha.contains(ch)){
            QMessageBox::warning(this,"Advertencia","La palabra contiene caracterres no definidos en el alfabeto del codigo de la maquina introducida. Esto podria ocacionar errores indeseados",QMessageBox::Discard);
            break;
        }
    }
}

void machine::on_exeCode_finished()
{
    if(run)
    {
        if(!stef.contains(state_act))
        {
            Runcode();
            exeCode->start();
        }
        else
            run = false;
    }
    else
    {
        playButton->setEnabled(true);
        previousButton->setEnabled(true);
        nextButton->setEnabled(true);
        stopButton->setEnabled(true);
    }
    /*while (run) {
        if(!stef.contains(state_act)){
            exeCode->start();
            //Runcode();
            //QTest::qWait(3000-(30*(ui->horizontalSlider->value())));
        }
        else{
            run = false;
        }
    }*/
}
void machine::playClicked(){
    sotpClicked();
    playButton->setEnabled(false);
    previousButton->setEnabled(false);
    nextButton->setEnabled(false);
    stopButton->setEnabled(true);
    pointer=begi;
    run=true;
    exeCode->velocity = ui->horizontalSlider->value();
    exeCode->start();
    /*while (run) {
        if(!stef.contains(state_act)){
            exeCode->start();
            //Runcode();
            //QTest::qWait(3000-(30*(ui->horizontalSlider->value())));
        }
        else{
            run = false;
        }
    }*/
    /*playButton->setEnabled(true);
    previousButton->setEnabled(true);
    nextButton->setEnabled(true);
    stopButton->setEnabled(true);*/
}
void machine::sotpClicked(){
    run = false;
    playButton->setEnabled(true);
    previousButton->setEnabled(true);
    nextButton->setEnabled(true);
    stopButton->setEnabled(false);
    state_act = conf[0].getState();
    paintLine(conf[0].getLineNumber());
    ui->label_3->setText("");
    ui->label_4->setText(QString::fromStdString(state_act));
    for(int i=0;i<caracteres.size();i++){
        caracteres[i]->setGeometry(geom[i].x(),geom[i].y(),geom[i].width(),geom[i].height());
        }
    pointer=begi;
}
void machine::nextClicked(){
    stopButton->setEnabled(true);
    previousButton->setEnabled(true);
    playButton->setEnabled(false);
    if(!stef.contains(state_act)){
        Runcode();
        //QTest::qWait(3000-(30*(ui->horizontalSlider->value())));
    }
    else{
        nextButton->setEnabled(false);
    }
}
void machine::previousClicked(){
    playButton->setEnabled(true);
    previousButton->setEnabled(true);
    nextButton->setEnabled(true);
    stopButton->setEnabled(false);
    pointer=begi;
    run = false;
}
void machine::paintLine(int nl){
     QColor color(Qt::yellow);
     editor.moveCursor(QTextCursor::Start);
     int i = 0;
     while(i < nl-1)
     {
        editor.moveCursor(QTextCursor::Down);
        ++i;
     }
     editor.setFocus();

}
void machine::MoveCinta(char dir){
    int num;
    if(dir == 'I'){
        for(int i = 0; i < 36;i++){
            foreach(QLineEdit* edit , caracteres){
                num = edit->geometry().x()+1;
                edit->setGeometry(num,edit->geometry().y(),edit->geometry().width(),edit->geometry().height());
            }
            //QTest::qWait((3000-(30*(ui->horizontalSlider->value())))/37);
        }
    }
    else if(dir == 'D'){
        int nuevo = (caracteres[1]->geometry().x()+(caracteres[1]->width()/2))-(caracteres[0]->geometry().x()+(caracteres[0]->width()/2));
        for(int i = 0; i < nuevo;i++){
            foreach(QLineEdit* edit , caracteres){
                num = edit->geometry().x()-1;
                edit->setGeometry(num,edit->geometry().y(),edit->geometry().width(),edit->geometry().height());
            }
             //QTest::qWait((3000-(30*(ui->horizontalSlider->value())))/37);
        }
    }
}
void machine::Takepos(){
    geom.clear();
    for(int i = 0;i < caracteres.size();i++){
        rec.setX(caracteres[i]->geometry().x());
        rec.setY(caracteres[i]->geometry().y());
        rec.setWidth(caracteres[i]->geometry().width());
        rec.setHeight(caracteres[i]->geometry().height());
        geom.push_back(rec);
    }
}
