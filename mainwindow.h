#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPoint>
#include <QEvent>
#include <QMouseEvent>

#include "mysonwid.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeEvent(QCloseEvent *);

    void mouseMoveEvent(QMouseEvent*);

private:
    Ui::MainWindow *ui;

    mySonWid* testWid;

public slots:
    void OnPushButton();

    void OnPushButton_2();

    void OnPushButtonMove();

    void OnPushButtonAddLabel();

    void OnPushButtonChangeLabel();
};

#endif // MAINWINDOW_H
