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

class IngresoDatosDialog : public QDialog
{
    Q_OBJECT
public:
    IngresoDatosDialog(QWidget *parent = nullptr);
private:
    // layouts
    QVBoxLayout *layoutPrincipal;
    QFormLayout *layoutDatos;

    // widgets
    QLabel *etiquetaNombrePersona;
    QLineEdit *lineEditNombrePersona;
    QRadioButton *botonRadioSexoMasculino;
    QRadioButton *botonRadioSexoFemenino;
    QRadioButton *botonRadioSexoIndefinido;
    QButtonGroup *grupoBotones;
    QDialogButtonBox *cajitaBotones;
};

#endif // INGRESODATOSDIALOG_H
