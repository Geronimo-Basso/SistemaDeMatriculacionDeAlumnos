//
// Created by Geronimo Basso on 6/11/22.
//
#include <iostream>

using namespace std;

#ifndef EJERCICIO_6_ALUMNO_H
#define EJERCICIO_6_ALUMNO_H


class Alumno {
private:
    string nombre;
    string apellido;
    int codigoAlumno;
public:
    Alumno(string nombre, string apellido, int codigoAlumno){
        Alumno::nombre = nombre;
        Alumno::apellido = apellido;
        Alumno::codigoAlumno = codigoAlumno;
    }
    ~Alumno(){

    }

};


#endif //EJERCICIO_6_ALUMNO_H<<