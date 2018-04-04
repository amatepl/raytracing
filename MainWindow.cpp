#include "MainWindow.h"
#include "ui_ieee80211g.h"
#include "room.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IEEE80211g)
{
    ui->setupUi(this);

    scene = new room(this);
    scene->setSceneRect(ui->graphicsView->rect());
       ui->graphicsView->setScene(scene);

       //ui->graphicsView->centerOn(scene->activePanel());
       ui->graphicsView->ensureVisible(scene->sceneRect());

       ui->spinBoxPosX->setReadOnly(true);
       ui->spinBoxPosY->setReadOnly(true);
       ui->spinBoxPosX->setValue(cursor().pos().x());
       ui->spinBoxPosY->setValue(cursor().pos().y());
       configureSpinBox(ui->spinBoxPosX, -INT_MIN, +INT_MAX);
       configureSpinBox(ui->spinBoxPosX, -INT_MIN, +INT_MAX);
       QBrush greenBrush(Qt::green);
       QBrush blueBrush(Qt::blue);
       QPen outlinePen(Qt::black);
       outlinePen.setWidth(2);

       //rectangle = scene->addRect(100, 0, 80, 100, outlinePen, blueBrush);
       //rectangle->setFlag(QGraphicsItem::ItemIsMovable);

       // addEllipse(x,y,w,h,pen,brush)
       //ellipse = scene->addEllipse(0, -100, 300, 60, outlinePen, greenBrush);
       //ellipse->setFlag(QGraphicsItem::ItemIsMovable);

       //text = scene->addText("bogotobogo.com", QFont("Arial", 20) );
       // movable text
       //text->setFlag(QGraphicsItem::ItemIsMovable);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configureSpinBox(QSpinBox *spinBox, int min, int max)const{
    spinBox->setMinimum(min);
    spinBox->setMaximum(max);

}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    //onMouseEvent("lolo", event->pos());
    QWidget::mouseMoveEvent(event);
    //QGraphicsScene::mouseMoveEvent(event);
    //QGraphicsScene::mouseMoveEvent(event);


}
/*
void MainWindow::setMap(QPointF &pos){
    ui->graphicsView->mapToScene(pos);

}
*/

void MainWindow::mousePressEvent(QMouseEvent *event){
    //onMouseEvent("lala", event->pos());
    QWidget::mousePressEvent(event);

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    QWidget::mouseReleaseEvent(event);

}

void MainWindow::onMouseEvent(const QString &eventName, const QPoint &pos){
    statusBar()->showMessage(eventName);
    ui->spinBoxPosX->setValue(pos.x());
    ui->spinBoxPosY->setValue(pos.y());
}

void MainWindow::on_commandLinkButton_clicked()
{   statusBar()->showMessage("Lunch Ray-Tracing");

}

void MainWindow::on_antena_clicked()
{   statusBar()->showMessage("Place the antena");

}

void MainWindow::on_receiver_clicked()
{   statusBar()->showMessage("Place the receiver");

}
