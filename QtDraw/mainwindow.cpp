#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pixmap{750,400}
    , x{40}
    , y{40}
{
    ui->setupUi(this);

    pixmap.fill(QColor("white"));
    DrawRight();

    connect(ui->rightButton,&QPushButton::clicked,this,&MainWindow::DrawRight);
    connect(ui->downButton,&QPushButton::clicked,this,&MainWindow::DrawDown);
    connect(ui->upButton,&QPushButton::clicked,this,&MainWindow::DrawUp);
    connect(ui->leftButton,&QPushButton::clicked,this,&MainWindow::DrawLeft);

    connect(ui->editWidth,SIGNAL(triggered()),this,SLOT(EditWidth()));
    connect(ui->editColor,SIGNAL(triggered()),this,SLOT(EditColour()));

    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Save",this,&MainWindow::DrawSave);
    fileMenu->addAction("Help",this,&MainWindow::HelpMessage);
    fileMenu->addAction("Exit",this,&MainWindow::close);
}

void MainWindow::DrawRight()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x, y, x+20, y);
    ui->label->setPixmap(pixmap);
    x += 20;
    //QPushButton *a = new QPushButton;
}

void MainWindow::DrawDown()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x ,y ,x ,y+20);
    ui->label->setPixmap(pixmap);
    y += 20;
    //QPushButton *a = new QPushButton;
}

void MainWindow::DrawUp()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x, y, x, y-20);
    ui->label->setPixmap(pixmap);
    y -= 20;
    //QPushButton *a = new QPushButton;
}

void MainWindow::DrawLeft()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x, y, x-20, y);
    ui->label->setPixmap(pixmap);
    x -= 20;
    //QPushButton *a = new QPushButton;
}

void MainWindow::EditWidth()
{
    width = QInputDialog::getInt(this, "Pen Width", "Enter a width:", 10, 1);
}

void MainWindow::EditColour()
{
    colour = QColorDialog::getColor(Qt::green, this, "Pen color");
}

void MainWindow::DrawSave()
{
    QString file_name = QFileDialog::getSaveFileName(this, tr("Save draw"), QDir::currentPath(), tr("Image Files (*.png, *.jpg);;All Files(*)"));
    if (file_name != "") {
        ui->label->grab().save(file_name);
    }
}

void MainWindow::HelpMessage()
{
    QString help_message = "\nDraw help.\n\n\n1.Save\nYou can save by clicking on the menu bar \"File/Save\" and then you can choose the file destination.\n\n";
    help_message += "2.Change colour\nYou can change the pen colour by clicking on the menu bar \"Style/Colour\".\n\n";
    help_message += "3. Change width\n You can change the pen width by clicking on the menu bar \"Style/Width\".\n\n";
    help_message += "4. Exit \nYou can exit this program by clicking on the menu bar \"File/Exit\".\n\n";
    QMessageBox::information(this,tr("Draw help"), help_message);
}

MainWindow::~MainWindow()
{
//    https://stackoverflow.com/questions/16362191/qt-grab-widget-and-save-image
    ui->label->grab().save("image.png");
    delete ui;
}

