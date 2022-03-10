#include "ingresodatosdialog.h"
#include <QMessageBox>

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
    this->lineEditEdadPersona = new QLineEdit();
    this->botonRadioSexoFemenino = new QRadioButton("Mujer");
    this->botonRadioSexoMasculino = new QRadioButton("Hombre");
    this->botonRadioSexoIndefinido = new QRadioButton("Otro");
    this->grupoBotones = new QButtonGroup();
    this->cajitaBotones = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    // organizamos elementos
    this->layoutDatos->addRow(this->etiquetaNombrePersona, this->lineEditNombrePersona);
    this->layoutDatos->addRow("Edad: ", this->lineEditEdadPersona);
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

    this->inicializa_eventos();

    // datos de la clase
    this->persona = NULL;
}

Persona *IngresoDatosDialog::datos_persona()
{
    this->toma_datos_interfaz();
    return this->persona;
}

void IngresoDatosDialog::closeEvent(QCloseEvent *e)
{
    this->toma_datos_interfaz();

    QDialog::closeEvent(e);
}

void IngresoDatosDialog::inicializa_eventos()
{
    QObject::connect(this->cajitaBotones, SIGNAL(accepted()), this, SLOT(accept()));
    QObject::connect(this->cajitaBotones, SIGNAL(rejected()), this, SLOT(reject()));
}

void IngresoDatosDialog::toma_datos_interfaz()
{
    // tomando datos de la interfaz
    QString nombre = this->lineEditNombrePersona->text();
    try {
        this->lineEditEdadPersona->text().toInt();
    } catch (std::bad_cast &e) {
        QMessageBox mb(QMessageBox::Icon::Critical, "Error :(", "Ingrese un número en edad >:( :" + QString(e.what()));
    }
    QString edad = this->lineEditEdadPersona->text();
    int genero = 0;
    if(this->botonRadioSexoFemenino->isChecked()){
        genero = FEMENINO;
    }else if(this->botonRadioSexoMasculino->isChecked()){
        genero = MASCULINO;
    }else if(this->botonRadioSexoIndefinido->isChecked()){
        genero = OTRO;
    }
    this->persona = new Persona(nombre, edad, genero);
}
