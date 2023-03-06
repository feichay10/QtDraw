/**
 *
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Degree: Informatics Engineering
 * Subject: Sistemas Operativos Avanzados
 * Grade: 3º
 * Practice 1: QtDraw
 * @file main.cpp
 * @author Cheuk Kelly Ng Pante (alu0101364544@ull.edu.es)
 * @brief This file contains the implementation of the main function
 * @version 0.2
 * @date 2023-03-07
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
