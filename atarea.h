#ifndef ATAREA_H
#define ATAREA_H

#include <QDialog>

#include<QDate>

namespace Ui {
class Atarea;
}

class Atarea : public QDialog
{
    Q_OBJECT

public:
    explicit Atarea(QWidget *parent = nullptr);
    ~Atarea();

    QString nombre() const ;
    int prioridad() const;
    QDate dates() const;
    QString tipo() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::Atarea *ui;
};

#endif // ATAREA_H
