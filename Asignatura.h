#include <iostream>
#include "Profesor.h"
#include "Alumno.h"
#include "vector"

#ifndef EJERCICIO_6_ASIGNATURA_H
#define EJERCICIO_6_ASIGNATURA_H

//Creamos entidad Asignatura, la cual vamos a implementar para llevar a la realidad  nuestro programa.
class Asignatura {
private:
    //Definimos los atributos de asignatura que vamos a usar
    string codigo;
    string nombre;
    int anio;
    Profesor * profesorAsociado;
    vector<Alumno*> * alumnosAsignados = new vector<Alumno*>;
public:
    //creamos los constructores de la asginatura
    Asignatura(){

    }
    Asignatura(string codigo, string nombre, int anio, Profesor * profesorAsociado){ //constructor con parametros de Asignatura
        Asignatura::codigo = codigo;
        Asignatura::nombre = nombre;
        Asignatura::anio = anio;
        Asignatura::profesorAsociado = profesorAsociado;
    }
    //creamos el destructor de asignatura
    ~Asignatura(){
        cout << "Asignatura eliminada con exito" << endl;
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
        if (alumnosAsignados->size()>0){
            for (int i=0; i<alumnosAsignados->size(); i++){
                cout << alumnosAsignados->at(i)->imprimirAlumno() << endl;
            }
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

    //getter para obtener el vector de alumnos
    vector<Alumno *> *getAlumnosAsignados() const {
        return alumnosAsignados;
    }


};


#endif //EJERCICIO_6_ASIGNATURA_H
