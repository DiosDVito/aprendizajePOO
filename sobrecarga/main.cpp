#include "rectangular.h"
#include "polar.h"
#include <iostream>

int main(){
    Rectangular a(2.0,3.0),
                b(5.0,6.0),
                c(-1.0,4.0);
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<c<<std::endl;
    Rectangular d=a.suma(b).suma(c);
    Rectangular e = a+b+c;
    std::cout<<d<<std::endl;
    std::cout<<e<<std::endl;

    return 0;
}