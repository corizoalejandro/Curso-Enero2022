#include "ventanita.h"
#include <QDebug>

Ventanita::Ventanita(QWidget *parent)
    : QWidget(parent)
{
    // inicializamos funciones de la ventana
    this->setWindowTitle("Esta es mi primer ventanita! :D");
    this->resize(ANCHO_VENTANA, ALTO_VENTANA);

    // inicializamos variables de la ventana

    // primero inicializamos los layouts
    this->layoutPrincipal = new QHBoxLayout();
    this->layoutPrincipal->setAlignment(Qt::AlignCenter);

    // luego inicializamos las variables
    this->etiqueta = new QLabel("¡Hola mundo!");

    // despues metemos los datos al layout
    this->layoutPrincipal->addWidget(etiqueta);

    // al final seteamos los Layouts
    this->setLayout(this->layoutPrincipal);
}

Ventanita::~Ventanita()
{
    delete layoutPrincipal;
    delete etiqueta;
}

void Ventanita::closeEvent(QCloseEvent *event)
{
    qDebug() << "Cerrando ventana";
    QWidget::closeEvent(event);
}

