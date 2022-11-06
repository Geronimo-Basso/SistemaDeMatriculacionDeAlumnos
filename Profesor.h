#include <iostream>
using namespace std;
#ifndef EJERCICIO_6_PROFESOR_H
#define EJERCICIO_6_PROFESOR_H

//Clase Profesor, es un clase creada para representar a la entidad Profesor.
class Profesor {
    //Atributos de la clase profesor
private:
    string nombre;
    string apellido;
    int codigoEmpleado;
public:
    Profesor(){ // constructor por defecto
        Profesor::nombre = "Jorge";
        Profesor::apellido = "Garcia";
        Profesor::codigoEmpleado = 1234;
    }
    Profesor(string nombre, string apellido, int codigoEmpleado){ // constructor de profesor con parametros
        Profesor::nombre = nombre;
        Profesor::apellido = apellido;
        Profesor::codigoEmpleado = codigoEmpleado;
    }
    ~Profesor(){ // destructor
        cout << "Profesor eliminado con exito" << endl;
    }
    string imprimirProfesor(){ //devuelve por consola la informacion del profesor
        string devolucion;
        devolucion=to_string(codigoEmpleado) + "-" + nombre + "-" + apellido;
        return devolucion;
    }


};


#endif //EJERCICIO_6_PROFESOR_H
