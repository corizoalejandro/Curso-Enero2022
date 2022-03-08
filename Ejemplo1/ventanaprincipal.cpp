#include "ventanaprincipal.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Ventana principal!");
    this->resize(ANCHO_VENTANA_MAIN, LARGO_VENTANA_MAIN);

    this->inicializa_widget_central();
}

VentanaPrincipal::~VentanaPrincipal()
{
}

void VentanaPrincipal::inicializa_widget_central()
{
    // inicializamos layouts
    this->layoutPrincipal = new QVBoxLayout();
    this->layoutDatos = new QHBoxLayout();
    this->layoutDatos->setAlignment(Qt::AlignLeft);
    this->layoutBotonesMenu = new QHBoxLayout();
    this->layoutBotonesMenu->setAlignment(Qt::AlignRight);
    this->layoutInfoDatos = new QVBoxLayout;

    // inicializamos widgets
    this->listaDatos = new QListWidget();
    this->listaDatos->setMaximumWidth(ANCHO_LISTA);
    this->botonAgregar = new QPushButton("Agregar");
    this->botonAgregar->setMaximumWidth(ANCHO_BOTON);
    this->widgetCentral = new QWidget();

    // organizamos el contenido
    this->layoutDatos->addWidget(this->listaDatos);
    this->layoutDatos->addLayout(this->layoutInfoDatos);

    this->layoutBotonesMenu->addWidget(this->botonAgregar);

    this->layoutPrincipal->addLayout(this->layoutDatos);
    this->layoutPrincipal->addLayout(this->layoutBotonesMenu);

    // agregamos el layout principal al
    // widget central
    this->widgetCentral->setLayout(this->layoutPrincipal);

    // seteamos el widget central
    this->setCentralWidget(this->widgetCentral);
}

