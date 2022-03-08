#include "ventanita.h"
#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    // viendo los argumentos del sistema/programa
//    for(int i=1;i<argc;i++){
//        std::cout << argv[i] << std::endl;
//    }
    QApplication a(argc, argv);
    Ventanita w;
    w.show();
    return a.exec();
}
