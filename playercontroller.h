#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <QObject>
#include <QThread>

class playercontroller : public QThread
{
    Q_OBJECT
public:
    //explicit playercontroller(QObject *parent = 0);
    void run() Q_DECL_OVERRIDE;
    int velocity;
signals:
    void moving();
public slots:
};

#endif // PLAYERCONTROLLER_H
