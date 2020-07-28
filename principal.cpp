#include "principal.h"
#include "ui_principal.h"

#include "atarea.h"
#include <QDate>
#include<QFileDialog>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    QStringList titulos;
    ui->tableWidget->setColumnCount(3);
    titulos<<"Nombre"<<"Tipo"<<"Fecha";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_pushButton_clicked()
{

    QString nombre;
    int prioridad;
    int respuesta;
    QDate date1;

    Atarea tarea(this);
    respuesta = tarea.exec();

    if(respuesta == QDialog::Rejected)
        return;

    nombre= tarea.nombre();
    prioridad= tarea.prioridad();
    date1 = tarea.dates();

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(nombre));

    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(prioridad));

    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(date1.toString()));


}




void Principal::on_actionGuardar_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                       "Guardar datos", QDir::home().absolutePath(), "Archivo de texto (*.txt)");
    QFile data(fileName);
}
