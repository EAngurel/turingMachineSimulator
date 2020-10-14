#include "graphwidget.h"
#include "node.h"

#include <math.h>

#include <QKeyEvent>

GraphWidget::GraphWidget(QWidget *parent)
    : QGraphicsView(parent), timerId(0)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 400, 400);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(400, 400);
    Node *node1 = new Node(this);
    Node *node2 = new Node(this);
    Node *node3 = new Node(this);
    Node *node4 = new Node(this);
    centerNode = new Node(this);
    Node *node6 = new Node(this);
    Node *node7 = new Node(this);
    Node *node8 = new Node(this);
    Node *node9 = new Node(this);


    node1->setPos(-200, -200);
    node2->setPos(0, -50);
    node3->setPos(50, -50);
    node4->setPos(-50, 0);
    centerNode->setPos(10, 10);
    node6->setPos(50, 0);
    node7->setPos(-50, 50);
    node8->setPos(0, 50);
    node9->setPos(50, 50);
}

void GraphWidget::itemMoved()
{

}

void GraphWidget::keyPressEvent(QKeyEvent *event)
{
    QRectF tmp;
    switch (event->key()) {
    case Qt::Key_0:
        tmp = sceneRect();
        tmp.setLeft(tmp.left() - 10);
        tmp.setRight(tmp.right() - 10);
        setSceneRect(tmp);
        break;
    case Qt::Key_Up:
        centerNode->moveBy(0, -20);
        break;
    case Qt::Key_Down:
        centerNode->moveBy(0, 20);
        break;
    case Qt::Key_Left:
        centerNode->moveBy(-20, 0);
        break;
    case Qt::Key_Right:
        centerNode->moveBy(20, 0);
        break;
    default:
        break;
    }
}


void GraphWidget::timerEvent(QTimerEvent *event)
{
}


#ifndef QT_NO_WHEELEVENT

void GraphWidget::wheelEvent(QWheelEvent *event)
{
}

#endif




