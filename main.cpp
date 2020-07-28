#include "principal.h"
#include<QTranslator>
#include<QInputDialog>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator traduccion;

    QStringList idiomas;
    idiomas << "Ingles" << "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                           "Idioma",
                                           "Seleccione un idioma",
                                           idiomas);

    if(idiomaSeleccionado == "Ingles"){
        traduccion.load(":/examen_guaraca_fernanda2_en_US.qm");
    }
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traduccion);
    }
    Principal w;
    w.show();
    return a.exec();
}
