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
    int anio;
    Profesor * profesorAsociado;
    vector<Alumno*> * alumnosAsignados;
public:
    Asignatura(string codigo, string nombre, int anio, Profesor * profesorAsociado){ //constructor con parametros de Asignatura
        Asignatura::codigo = codigo;
        Asignatura::nombre = nombre;
        Asignatura::anio = anio;
        Asignatura::profesorAsociado = profesorAsociado;
    }
    ~Asignatura(){ //destructor de asignatura

    }

    void imprimirAsignatura(){ // imprime por consola de forma bonita la informacion de la consola
        // codigo de asignatura + nombre + anio
        //________________________________________________
        // en otra fila profesor
        //________________________________________________
        // mas abajo aun listado de alumnos con for
        cout << codigo << " " << nombre << " " << anio << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << profesorAsociado->imprimirProfesor() << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (int i=0; i<alumnosAsignados->size(); i++){
            cout << alumnosAsignados->at(i)->imprimirAlumno();
        }
    }
    string imprimirAsignaturaLite(){ // devuelve un string con la informacion basica de la asignatura
        return  (codigo + " " + nombre + " " + to_string(anio));
    }
    int numeroDeAlumnos(){ // devuelve el numero de alumnos apuntados en la asignatura
        return alumnosAsignados->size();
    }
    int contieneAlumno(Alumno * alumno){ // devuelve 1 si un alumno esta matriculado en la asignatura
        int encontrado = 0;
        for(int j=0; j<alumnosAsignados->size(); j++){
            if (alumnosAsignados->at(j)==alumno){
                encontrado = 1;
            }
        }
        return encontrado;
    }

    const string &getCodigo() const {
        return codigo;
    }


};


#endif //EJERCICIO_6_ASIGNATURA_H
