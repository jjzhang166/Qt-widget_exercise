#ifndef MYSONWID_H
#define MYSONWID_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QList>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QMap>
#include <QPoint>

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

    QMap<QString, int> m_map;
public:
    void m_add_lable(QString, QPoint point);

    void m_change_label();

    void m_change_label(QString name, QPoint point);
};

#endif // MYSONWID_H
