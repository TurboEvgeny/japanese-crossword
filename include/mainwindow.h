#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "crossword_data.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void paintEvent(QPaintEvent *event);
    void draw(QRect &rect);
    Ui::MainWindow *ui;
    CrosswordData crossword;
};
#endif // MAINWINDOW_H
