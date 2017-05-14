#include "mysonwid.h"
#include "ui_mysonwid.h"

mySonWid::mySonWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mySonWid)
{
    ui->setupUi(this);

    m_label_count = 0;

    this->setWindowFlags(Qt::WindowStaysOnTopHint
                         | this->windowFlags() &~ Qt::WindowMinMaxButtonsHint   //禁止最大化和最小化
                         /*| this->windowFlags() &~ Qt::WindowMaximizeButtonHint*/);//禁止最大化);

    //this->setAttribute(Qt::WA_DeleteOnClose);
    m_layOut = new QVBoxLayout;
}

mySonWid::~mySonWid()
{
    qDebug()<<"mySonWid::~mySonWid()";
    delete m_layOut;
    delete label;

    delete ui;
}

void mySonWid::m_add_lable(QString name, QPoint point)
{
    qDebug()<<"void mySonWid::m_add_lable()";
    label = new QLabel;

    QString showText = name + " :\t( "
            + QString::number(point.x()) + " , " + QString::number(point.y())
            + " ) ";

    m_map.insert(name,m_label_count++);

    label->setText(showText);

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

void mySonWid::m_change_label(QString name, QPoint point)
{
    int index = m_map.value(name);
    if(index >= m_label_count)
    {
        return;
    }

    label = m_label_list.at(index);
    QString showText = name + " :\t( "
            + QString::number(point.x()) + " , " + QString::number(point.y())
            + " ) ";
    label->setText(showText);
}
