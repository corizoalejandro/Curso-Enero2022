#include "ventanaprincipal.h"
#include "ingresodatosdialog.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Ventana principal!");
    this->resize(ANCHO_VENTANA_MAIN, LARGO_VENTANA_MAIN);

    this->inicializa_widget_central();
    this->inicializa_eventos();
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
    this->lineEditNombre = new QLineEdit();
    this->lineEditNombre->setEnabled(false);
    this->lineEditEdad = new QLineEdit();
    this->lineEditEdad->setEnabled(false);
    this->lineEditGenero = new QLineEdit();
    this->lineEditGenero->setEnabled(false);
    this->widgetCentral = new QWidget();

    // organizamos el contenido
    this->layoutInfoDatos->addWidget(this->lineEditNombre);
    this->layoutInfoDatos->addWidget(this->lineEditEdad);
    this->layoutInfoDatos->addWidget(this->lineEditGenero);

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

void VentanaPrincipal::inicializa_eventos()
{
    // parametro 1: objeto de donde voy a tomar la señal
    // parametro 2: usar SIGNAL() y poner la funcion de señal
    // parametro 3: objeto de donde voy a lanzar el slot/evento
    // parametro 4: usar SLOT() y poner la funcion de slot
    QObject::connect(this->botonAgregar, SIGNAL(clicked()), this, SLOT(agregar_nueva_persona()));
    QObject::connect(this->listaDatos, SIGNAL(currentRowChanged(int)), this, SLOT(evento_lista_seleccionado(int)));
}

void VentanaPrincipal::agrega_datos_a_lista(Persona *p)
{
    // lista de datos
    this->listaPersonas.push_back(p);
    // lista grafica
    this->listaDatos->addItem(p->nombre);
}

void VentanaPrincipal::mostrar_datos_seleccionados(Persona *p)
{
    if(!p){
        QMessageBox mb(QMessageBox::Icon::Critical, "Error :(", "Dato corrompido o nulo :(");
        mb.exec();
        return;
    }
    this->lineEditNombre->setText(p->nombre);
    this->lineEditEdad->setText(p->edad);
    switch(p->genero){
    case FEMENINO:
        this->lineEditGenero->setText("Femenino");
        break;
    case MASCULINO:
        this->lineEditGenero->setText("Masculino");
        break;
    case OTRO:
        this->lineEditGenero->setText("Otro");
        break;
    default:
        this->lineEditGenero->setText("Desconocido");
        break;
    }
}

void VentanaPrincipal::agregar_nueva_persona()
{
    IngresoDatosDialog w;
    if(w.exec() == QDialog::Accepted){
//        QMessageBox mb(QMessageBox::Icon::Information, "Mensajito", "Se presionó OK");
//        mb.exec();
        this->agrega_datos_a_lista(w.datos_persona());
    }else{
//        QMessageBox mb(QMessageBox::Icon::Warning, "Mensajito", "Se presionó Cancel");
//        mb.exec();
    }
}

void VentanaPrincipal::evento_lista_seleccionado(int row)
{
    if(row < 0 || row > this->listaPersonas.size()){
        QMessageBox mb(QMessageBox::Icon::Critical, "Error", "No se puede acceder a ese dato D:");
        mb.exec();
        return;
    }
    this->mostrar_datos_seleccionados(this->listaPersonas.at(row));
}

