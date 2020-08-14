#include "principal.h"
#include "ui_principal.h"

#include "atarea.h"
#include <QDate>
#include<QFileDialog>
#include<QTextStream>
#include <QMessageBox>

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

    int respuesta;
    QDate date1;

    Atarea tarea(this);
    respuesta = tarea.exec();

    if(respuesta == QDialog::Rejected){

        return;
}
    nombre= tarea.nombre();

    date1 = tarea.dates();



    int posicion= ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(posicion);
    ui->tableWidget->setItem(posicion,0, new QTableWidgetItem(nombre));
    ui->tableWidget->setItem(posicion,2, new QTableWidgetItem(date1.toString()));



 QString fileName = ("C:/Users/Nataly/Desktop/Tarea/Guardado/tareas.txt");
       QFile data(fileName);
       if (data.open(QFile::WriteOnly | QFile::Truncate)){
           QTextStream salida(&data);
           QStringList Lista;
           for( int columna = 0; columna < ui->tableWidget->columnCount(); ++columna ){
               Lista << "\" " + ui->tableWidget->horizontalHeaderItem(columna)->data(Qt::DisplayRole).toString() + "\" ";
           }
           salida << Lista.join(";") << "\n";
           for( int fila = 0; fila < ui->tableWidget->rowCount(); ++fila)
           {
               Lista.clear();
               for( int columna = 0; columna < ui->tableWidget->columnCount(); ++columna){
                   QTableWidgetItem* item = ui->tableWidget->item(fila,columna);
                   if (!item || item->text().isEmpty()){
                       ui->tableWidget->setItem(fila,columna,new QTableWidgetItem("0"));
                   }
                   Lista << "\" "+ui->tableWidget->item( fila, columna )->text()+"\" ";
               }
               salida<< Lista.join( ";" )+"\n";
           }
           ui->statusbar->showMessage("Datos almacenados en: " + fileName, 5000);
           data.close();
       }

}




void Principal::on_actionGuardar_triggered()
{
    QString nombre;

    int respuesta;
    QDate date1;

    Atarea tarea(this);
    respuesta = tarea.exec();

    if(respuesta == QDialog::Rejected){

        return;
}
    nombre= tarea.nombre();

    date1 = tarea.dates();



    int posicion= ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(posicion);
    ui->tableWidget->setItem(posicion,0, new QTableWidgetItem(nombre));
    ui->tableWidget->setItem(posicion,2, new QTableWidgetItem(date1.toString()));




}




void Principal::on_pushButton_2_clicked()
{
    ui->tableWidget->removeRow(0);
    ui->statusbar->showMessage(tr("Fila eliminada"), 4000);
}
