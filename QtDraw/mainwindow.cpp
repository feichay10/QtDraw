/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Degree: Informatics Engineering
 * Subject: Sistemas Operativos Avanzados
 * Grade: 3º
 * Practice 1: QtDraw
 * @file mainwindow.cpp
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief This file contains the implementation of the MainWindow class
 * @version 0.2
 * @date 2023-03-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "mainwindow.h"
#include "./ui_mainwindow.h"

/**
 * @brief Constructor of the MainWindow class 
 * 
 * @param parent 
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pixmap{750,400}
    , x{40}
    , y{40}
{
    ui->setupUi(this);

    pixmap.fill(QColor("white")); // Make the board white
    //DrawRight();
    ReadSettings();

    // Connecting directions buttons with methods
    connect(ui->rightButton,&QPushButton::clicked,this,&MainWindow::DrawRight);
    connect(ui->downButton,&QPushButton::clicked,this,&MainWindow::DrawDown);
    connect(ui->upButton,&QPushButton::clicked,this,&MainWindow::DrawUp);
    connect(ui->leftButton,&QPushButton::clicked,this,&MainWindow::DrawLeft);

    // Connecting menu bar buttons of the Style button
    connect(ui->editWidth,SIGNAL(triggered()),this,SLOT(EditWidth()));
    connect(ui->editColor,SIGNAL(triggered()),this,SLOT(EditColour()));

    // More options on the File button on the menu bar
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Save",this,&MainWindow::DrawSave);
    fileMenu->addAction("Help",this,&MainWindow::HelpMessage);
    fileMenu->addAction("Exit",this,&MainWindow::close);
}

/**
 * @brief MainWindow Destructor
 */
MainWindow::~MainWindow()
{
    WriteSettings();
    delete ui;
}

/**
 * @brief Draw a line to the right of size 20 pixels
 * 
 */
void MainWindow::DrawRight()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x, y, x+20, y);
    ui->label->setPixmap(pixmap);
    x += 20;
}

/**
 * @brief Draw a line down of size 20 pixels
 * 
 */
void MainWindow::DrawDown()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x ,y ,x ,y+20);
    ui->label->setPixmap(pixmap);
    y += 20;
}

/**
 * @brief Draw a line up of size 20 pixels
 * 
 */
void MainWindow::DrawUp()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x, y, x, y-20);
    ui->label->setPixmap(pixmap);
    y -= 20;
}

/**
 * @brief Draw a line to the left of size 20 pixels
 * 
 */
void MainWindow::DrawLeft()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour, width));
    painter.drawLine(x, y, x-20, y);
    ui->label->setPixmap(pixmap);
    x -= 20;
}

/**
 * @brief Edit the width of the pen
 * 
 */
void MainWindow::EditWidth()
{
    width = QInputDialog::getInt(this, "Pen Width", "Enter a width:", 10, 1);
}

/**
 * @brief Edit the colour of the pen
 * 
 */
void MainWindow::EditColour()
{
    colour = QColorDialog::getColor(Qt::green, this, "Pen color");
}

/**
 * @brief Save the draw in a file
 * 
 */
void MainWindow::DrawSave()
{
    QString file_name = QFileDialog::getSaveFileName(this, tr("Save draw"), QDir::currentPath(), tr("Image Files (*.png, *.jpg);;All Files(*)"));
    if (file_name != "") {
        ui->label->grab().save(file_name);
    }
}

/**
 * @brief Show a help message with the instructions
 * 
 */
void MainWindow::HelpMessage()
{
    QString help_message = "\nDraw help.\n\n\n1.Save\nYou can save by clicking on the menu bar \"File/Save\" and then you can choose the file destination.\n\n";
    help_message += "2.Change colour\nYou can change the pen colour by clicking on the menu bar \"Style/Colour\".\n\n";
    help_message += "3. Change width\n You can change the pen width by clicking on the menu bar \"Style/Width\".\n\n";
    help_message += "4. Exit \nYou can exit this program by clicking on the menu bar \"File/Exit\".\n\n";
    QMessageBox::information(this,tr("Draw help"), help_message);
}

/**
 * @brief Write the settings of the window
 * 
 */
void MainWindow::WriteSettings()
{
    QSettings settings("MySoft", "Monster Energy");

    settings.beginGroup("MainWindow");
    settings.setValue("geometry", saveGeometry()); // Save the actual geometry of the window
    settings.setValue("penColour", colour);
    settings.setValue("penWidth", width);
    settings.endGroup();
}

/**
 * @brief Read the settings of the window or set the default values
 * 
 */
void MainWindow::ReadSettings()
{
    QSettings settings("MySoft", "Monster Energy");

    settings.beginGroup("MainWindow");
    const auto geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        setGeometry(200, 200, 1037, 665);
    } else {
        restoreGeometry(geometry);
    }

    if (settings.value("penWidth").isNull()) {
        width = 5;
    } else {
        width = settings.value("penWidth").toInt();
    }
    colour = settings.value("penColour").value<QColor>();
    settings.endGroup();
}