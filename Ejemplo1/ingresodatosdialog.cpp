#include "ingresodatosdialog.h"

IngresoDatosDialog::IngresoDatosDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setWindowTitle("Datos de Persona");

    // inicializar layouts
    this->layoutPrincipal = new QVBoxLayout();
    this->layoutDatos = new QFormLayout();

    // inicializar widgets
    this->etiquetaNombrePersona = new QLabel("Nombre: ");
    this->lineEditNombrePersona = new QLineEdit();
    this->botonRadioSexoFemenino = new QRadioButton("Mujer");
    this->botonRadioSexoMasculino = new QRadioButton("Hombre");
    this->botonRadioSexoIndefinido = new QRadioButton("Otro");
    this->grupoBotones = new QButtonGroup();
    this->cajitaBotones = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    // organizamos elementos
    this->layoutDatos->addRow(this->etiquetaNombrePersona, this->lineEditNombrePersona);
    this->layoutDatos->addRow(NULL, this->botonRadioSexoFemenino);
    this->layoutDatos->addRow(NULL, this->botonRadioSexoMasculino);
    this->layoutDatos->addRow(NULL, this->botonRadioSexoIndefinido);
    // agrupar botones
    this->grupoBotones->addButton(this->botonRadioSexoFemenino);
    this->grupoBotones->addButton(this->botonRadioSexoMasculino);
    this->grupoBotones->addButton(this->botonRadioSexoIndefinido);

//    this->cajitaBotones->addButton(QDialogButtonBox::Ok);
//    this->cajitaBotones->addButton(QDialogButtonBox::Cancel);

    // meter todo a los layouts
    this->layoutPrincipal->addLayout(this->layoutDatos);
    this->layoutPrincipal->addWidget(this->cajitaBotones);

    this->setLayout(this->layoutPrincipal);
}
