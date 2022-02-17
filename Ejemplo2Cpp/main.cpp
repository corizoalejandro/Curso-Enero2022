#include <iostream>
#include "fecha.h"

int main()
{
    Fecha fecha(17,2,2022);
    std::string fechaDelDia = Fecha::muestra_en_formato(17,2,2022);
    std::cout << "La fecha de hoy: " << fechaDelDia << std::endl;
    std::cout << "La fecha del objeto: " << fecha.muestra_en_formato() << std::endl;
    return 0;
}
