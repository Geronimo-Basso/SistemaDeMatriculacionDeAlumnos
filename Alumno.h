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
    Alumno(){

    }
    Alumno(string nombre, string apellido, int codigoAlumno){ // constructor de Alumno con parametros
        Alumno::nombre = nombre;
        Alumno::apellido = apellido;
        Alumno::codigoAlumno = codigoAlumno;
    }
    ~Alumno(){ //destructor
        cout << "Alumno eliminado con exito" << endl;
    }
    string imprimirAlumno(){ //devuelve un string con los datos del alumno
        string devolucion;
        devolucion=to_string(codigoAlumno) + "-" + nombre + "-" + apellido;
        return devolucion;
    }

    int getCodigoAlumno() const { //devuelve el codigo del alumno
        return codigoAlumno;
    }

};


#endif //EJERCICIO_6_ALUMNO_H<<