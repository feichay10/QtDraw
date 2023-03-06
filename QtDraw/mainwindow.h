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
