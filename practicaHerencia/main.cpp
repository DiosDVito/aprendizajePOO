#include <iostream>
#include "Figura.h"
#include "Rectangulo.h"
#include "Cuadrado.h"

int main() {
    std::cout << std::endl;
    Figura fig1;
    std::cout << "Área: " << fig1.area() << std::endl;
    std::cout << "Volumen: " << fig1.volumen() << std::endl;
    std::cout << "Perímetro: " << fig1.perimetro() << std::endl;
    std::cout << std::endl;

    Rectangulo rec1;
    rec1.imprimir();
    std::cout << "Área: " << rec1.area() << std::endl;
    std::cout << "Perímetro: " << rec1.perimetro() << std::endl;
    std::cout << std::endl;

    Rectangulo rec2(7.0,4.0);
    rec2.imprimir();
    std::cout << "Área: " << rec2.area() << std::endl;
    std::cout << "Perímetro: " << rec2.perimetro() << std::endl;
    std::cout << std::endl;

    Cuadrado cuad1;
    cuad1.imprimir();
    std::cout << "Área: " << cuad1.area() << std::endl;
    std::cout << "Perímetro: " << cuad1.perimetro() << std::endl;
    std::cout << std::endl;
}


   
