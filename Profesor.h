//
// Created by Geronimo Basso on 6/11/22.
//
#include <iostream>

using namespace std;

#ifndef EJERCICIO_6_PROFESOR_H
#define EJERCICIO_6_PROFESOR_H


class Profesor {
private:
    string nombre;
    string apellido;
    int codigoEmpleado;
public:
    Profesor(){
        Profesor::nombre = "Jorge";
        Profesor::apellido = "Garcia";
        Profesor::codigoEmpleado = 1234;
    }
    Profesor(string nombre, string apellido, int codigoEmpleado){
        Profesor::nombre = nombre;
        Profesor::apellido = apellido;
        Profesor::codigoEmpleado = codigoEmpleado;
    }
    ~Profesor(){

    }
    string imprimirProfesor(){
        return to_string(codigoEmpleado) << " " << nombre << " " << apellido;
    }

};


#endif //EJERCICIO_6_PROFESOR_H
