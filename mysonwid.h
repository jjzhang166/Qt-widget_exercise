#ifndef MYSONWID_H
#define MYSONWID_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QList>
#include <QVBoxLayout>
#include <QTabWidget>

namespace Ui {
class mySonWid;
}

class mySonWid : public QWidget
{
    Q_OBJECT

public:
    explicit mySonWid(QWidget *parent = 0);
    ~mySonWid();

private:
    Ui::mySonWid *ui;

    int m_label_count;

    QList<QLabel*> m_label_list;

    QVBoxLayout* m_layOut;

    QLabel *label;
public:
    void m_add_lable();

    void m_change_label();
};

#endif // MYSONWID_H
