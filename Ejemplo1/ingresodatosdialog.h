#ifndef INGRESODATOSDIALOG_H
#define INGRESODATOSDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QButtonGroup>
#include <QDialogButtonBox>
#include "persona.h"

class IngresoDatosDialog : public QDialog
{
    Q_OBJECT
public:
    IngresoDatosDialog(QWidget *parent = nullptr);
    Persona* datos_persona();
protected:
    void closeEvent(QCloseEvent *e) override;
private:
    // datos
    Persona *persona;

    // layouts
    QVBoxLayout *layoutPrincipal;
    QFormLayout *layoutDatos;

    // widgets
    QLabel *etiquetaNombrePersona;
    QLineEdit *lineEditNombrePersona;
    QLineEdit *lineEditEdadPersona;
    QRadioButton *botonRadioSexoMasculino;
    QRadioButton *botonRadioSexoFemenino;
    QRadioButton *botonRadioSexoIndefinido;
    QButtonGroup *grupoBotones;
    QDialogButtonBox *cajitaBotones;

    void inicializa_eventos();
    void toma_datos_interfaz();
};

#endif // INGRESODATOSDIALOG_H
