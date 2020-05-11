#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPainter painter = QPainter(this);
    painter.drawRect(100, 120, 500, 400);
    crossword.setSize(10, 30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QRect rect = event->rect();
    draw(rect);
}

void MainWindow::draw(QRect &rect)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);
    QRect square(0, 0, 10, 10);
    for (unsigned int x = 0 ; x < crossword.getWidth() ; x++)
    {
        square.moveRight((x+1) * 10);
        for (unsigned int y = 0 ; y < crossword.getHeight() ; y++)
        {
            square.moveBottom((y + 1) * 10);
            bool colored = crossword.isFieldColored(x, y);
            painter.drawRect(square);
            if (colored)
            {
                painter.fillRect(square, Qt::black);
            }
        }
    }

    painter.drawRect(square);
}

