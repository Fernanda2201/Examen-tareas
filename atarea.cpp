#include "atarea.h"
#include "ui_atarea.h"

#include <QDate>
#include <QFile>

Atarea::Atarea(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Atarea)
{
    ui->setupUi(this);
}

Atarea::~Atarea()
{
    delete ui;
}

QString Atarea::nombre() const
{
    return ui->inNombre->text();
}

int Atarea::prioridad() const
{
    int prioridad=0;

    if(ui->inAlta->isChecked()){
        prioridad=1;
    }else if(ui->inMedia->isChecked()){
        prioridad=2;
    }else if(ui->inBaja->isChecked()){
        prioridad=3;
    }
    return prioridad;
}


QDate Atarea::dates() const
{
    return ui->inFecha->date();
}

QString Atarea::tipo() const
{
    QString tipo = "";
    switch (ui->inTipo->currentIndex()) {
    case 'U':
        {
          tipo= "Universidad";
        }

     break;
     case 'P':
        tipo= "Personales";
        break;
      case 'F':
        tipo= "Familiares";
        break;
      case 'O':
        tipo ="Otro";
        break;

}
}

void Atarea::on_buttonBox_accepted()
{
    accept();
}

void Atarea::on_buttonBox_rejected()
{
    reject();
}





