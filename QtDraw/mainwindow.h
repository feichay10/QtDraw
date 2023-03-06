/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Degree: Informatics Engineering
 * Subject: Sistemas Operativos Avanzados
 * Grade: 3º
 * Practice 1: QtDraw
 * @file mainwindow.h
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief This file contains the declaration of the MainWindow class
 * @version 0.2
 * @date 2023-03-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QInputDialog>     // To select width
#include <QColorDialog>     // To select colour
#include <QFileDialog>      // To save the draw
#include <QMessageBox>      // To show help message
#include <QSettings>        // To save colour and width selected

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void DrawRight();
    void DrawDown();
    void DrawUp();
    void DrawLeft();

private slots:
    void EditWidth();
    void EditColour();
    void DrawSave();
    void HelpMessage();
    void WriteSettings();
    void ReadSettings();

private:
    Ui::MainWindow *ui;
    QPixmap pixmap;
    int cursor;
    int x, y;                   // cursor coordinates
    int width;                  // width
    QColor colour = Qt::white;  // colour
};
#endif // MAINWINDOW_H
