#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_pushButton_clicked();

    void on_actionGuardar_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::Principal *ui;

};
#endif // PRINCIPAL_H
