#include "mysonwid.h"
#include "ui_mysonwid.h"

mySonWid::mySonWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mySonWid)
{
    ui->setupUi(this);

    m_label_count = 0;

    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    //this->setAttribute(Qt::WA_DeleteOnClose);
    m_layOut = new QVBoxLayout;
}

mySonWid::~mySonWid()
{
    qDebug()<<"mySonWid::~mySonWid()";
    delete ui;
}

void mySonWid::m_add_lable()
{
    qDebug()<<"void mySonWid::m_add_lable()";
    label = new QLabel;

    label->setText(QString::number(m_label_count++));

    m_label_list.append(label);

    m_layOut->addWidget(label);

    this->setLayout(m_layOut);
}

void mySonWid::m_change_label()
{
    for(int index = 0; index< m_label_count; index++)
    {
        label = m_label_list.at(index);
        label->setText(QString::number(label->text().toInt()*2));
    }
}
