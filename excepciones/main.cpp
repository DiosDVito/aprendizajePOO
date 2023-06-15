#include "myException.h"
#include <string>
#include <iostream>

void metodoD(){
    bool condicion = true;
    if(condicion){
        throw MyException("Ocrrio un error fatal en D");
    }
}

void metodoC(){
    metodoD();
}

void metodoB(){
    metodoC();
}

void metodoA(){
    metodoB();
}

int main(){
    try{
    cout<<"Ejemplo de excepciones"<<endl;
    metodoA();
    cout<<"Finalizamos con exito"<<endl;
    }catch(MyException& ex){
        cout<<"Ocurrio un error: "<<ex.what()<<endl;
    };
    return 0;
}