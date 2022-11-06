//
// Created by Geronimo Basso on 6/11/22.
//
#include <iostream>
#include "Profesor.h"
#include "Alumno.h"
#include "vector"

#ifndef EJERCICIO_6_ASIGNATURA_H
#define EJERCICIO_6_ASIGNATURA_H


class Asignatura {
private:
    string codigo;
    string nombre;
    int ano;
    Profesor profesorAsociado;
    vector<Alumno> * alumnosAsignados;
public:
    Asignatura(string codigo, string nombre, int ano, Profesor profesorAsociado){
        Asignatura::codigo = codigo;
        Asignatura::nombre = nombre;
        Asignatura::ano = ano;
        Asignatura::profesorAsociado = profesorAsociado;
    }
    ~Asignatura(){

    }



};


#endif //EJERCICIO_6_ASIGNATURA_H
