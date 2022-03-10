#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QtWidgets>
#include <QList>
#include "persona.h"

#define ANCHO_VENTANA_MAIN 600
#define LARGO_VENTANA_MAIN 400
#define ANCHO_BOTON 100
#define ANCHO_LISTA 200

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    VentanaPrincipal(QWidget *parent = nullptr);
    ~VentanaPrincipal();
private:
    // layouts
    QVBoxLayout *layoutPrincipal;
    QHBoxLayout *layoutDatos;
    QHBoxLayout *layoutBotonesMenu;
    QVBoxLayout *layoutInfoDatos;

    // widgets
    QListWidget *listaDatos;
    QPushButton *botonAgregar;

    QLineEdit *lineEditNombre;
    QLineEdit *lineEditEdad;
    QLineEdit *lineEditGenero;
    // aquí va ir el contenido principal de
    // la ventana
    QWidget *widgetCentral;

    // datos de la clase
    QList<Persona*> listaPersonas;

    // funciones
    void inicializa_widget_central();
    void inicializa_eventos();
    void agrega_datos_a_lista(Persona *p);
    void mostrar_datos_seleccionados(Persona *p);
public Q_SLOTS:
    void agregar_nueva_persona();
    void evento_lista_seleccionado(int row);
};
#endif // VENTANAPRINCIPAL_H
