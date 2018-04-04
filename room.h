#ifndef ROOM_H
#define ROOM_H
#include "MainWindow.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>


class room : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit room(MainWindow *parent = 0);

signals:

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    MainWindow *myParent;
    QGraphicsView *graphicsView;

public slots:
};

#endif // ROOM_H
