#include "room.h"
#include "MainWindow.h"

room::room(MainWindow *parent) :
    QGraphicsScene(parent)
{ myParent = parent;

}

void room::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{   QPointF x = event->scenePos();
    QPoint X = x.toPoint();

    myParent->onMouseEvent("ll",X);

}

