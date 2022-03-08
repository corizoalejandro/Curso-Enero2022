#include "ventanaprincipal.h"
#include "ingresodatosdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    VentanaPrincipal w;
//    w.show();
    IngresoDatosDialog w;
    w.show();
    return a.exec();
}
