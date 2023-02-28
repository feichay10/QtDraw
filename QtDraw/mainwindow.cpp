#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pixmap{750,400}
    , cursor{0}
{
    ui->setupUi(this);

    pixmap.fill(QColor("white"));

    DrawRight();
    connect(ui->rightButton,&QPushButton::clicked,this,&MainWindow::DrawRight);
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Exit",this,&MainWindow::close);
}

void MainWindow::DrawRight()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::green,5));
    painter.drawLine(cursor,100,cursor+20,100);
    ui->label->setPixmap(pixmap);
    cursor+=20;
    QPushButton *a = new QPushButton;
}


MainWindow::~MainWindow()
{
//    https://stackoverflow.com/questions/16362191/qt-grab-widget-and-save-image
    ui->label->grab().save("image.png");
    delete ui;
}

