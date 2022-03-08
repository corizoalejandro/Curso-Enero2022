#ifndef VENTANITA_H
#define VENTANITA_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

#define ANCHO_VENTANA 600
#define ALTO_VENTANA 400

class Ventanita : public QWidget
{
    Q_OBJECT

public:
    Ventanita(QWidget *parent = nullptr);
    ~Ventanita();
protected:
    void closeEvent(QCloseEvent *event = nullptr);
private:
    // el layout para organizar los datos de la ventana
    QHBoxLayout *layoutPrincipal;
    // etiqueta para mostrar texto en la ventana
    QLabel *etiqueta;
};
#endif // VENTANITA_H
