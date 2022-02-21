#ifndef FIGURA_H
#define FIGURA_H

#define PI 3.1416

// Esta es una clase abstracta
// Solo nos interesa que tenga hijos
class Figura
{
public:
    Figura();
    virtual int area();
    virtual int perimetro();
};

class Cuadrado : public Figura {
public:
    Cuadrado(int lado = 0);
    int area() override;
    int perimetro() override;
private:
    int lado;
};

class Triangulo : public Figura {
public:
    Triangulo(int base = 0, int altura = 0);
    int area() override;
    int perimetro() override;
private:
    int base;
    int altura;
};

class Circulo : public Figura {
public:
    Circulo(int diametro = 0);
    int area() override;
    int perimetro() override;
private:
    int diametro;
};

#endif // FIGURA_H
