#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QInputDialog>     // To select width

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

private:
    Ui::MainWindow *ui;
    QPixmap pixmap;
    int cursor;
    int x, y;           // cursor coordinates
    int width = 5;          // width
};
#endif // MAINWINDOW_H
