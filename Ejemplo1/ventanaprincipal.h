#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QtWidgets>

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
    // aquí va ir el contenido principal de
    // la ventana
    QWidget *widgetCentral;

    // funciones
    void inicializa_widget_central();
};
#endif // VENTANAPRINCIPAL_H
