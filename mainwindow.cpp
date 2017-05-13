#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    testWid = NULL;
    testWid = new mySonWid();

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(OnPushButton()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(OnPushButton_2()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(OnPushButtonMove()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(OnPushButtonAddLabel()));
    connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(OnPushButtonChangeLabel()));
}

MainWindow::~MainWindow()
{
    qDebug()<<"MainWindow::~MainWindow()";
    if(NULL != testWid)
    {
        delete testWid;
        testWid = NULL;
    }
    delete ui;
}

void MainWindow::OnPushButton()
{
    qDebug()<<"void MainWindow::OnPushButton()";
    testWid->setVisible(true);
}

void MainWindow::OnPushButton_2()
{
    qDebug()<<"void MainWindow::OnPushButton_2()";
    testWid->setVisible(false);
}

void MainWindow::OnPushButtonMove()
{
    qDebug()<<"void MainWindow::OnPushButtonMove()";
    if(NULL != testWid)
    {
        QPoint mainWindowsPoint = this->pos();
        testWid->move(mainWindowsPoint.rx()- testWid->frameGeometry().width(), mainWindowsPoint.ry());
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug()<<"void MainWindow::closeEvent(QCloseEvent *event)";
    if(NULL != testWid)
    {
        delete testWid;
        testWid = NULL;
    }
}

void MainWindow::OnPushButtonAddLabel()
{
    if(NULL != testWid)
    {
        testWid->m_add_lable();
    }
}

void MainWindow::OnPushButtonChangeLabel()
{
    if(NULL != testWid)
    {
        testWid->m_change_label();
    }
}
