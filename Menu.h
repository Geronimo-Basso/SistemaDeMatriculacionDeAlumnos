#include <iostream>
#include "Profesor.h"
#include "Alumno.h"
#include "Asignatura.h"
using namespace std;

#ifndef EJERCICIO_6_MENU_H
#define EJERCICIO_6_MENU_H


class Menu {
private:
    char seleccion;
    int banderaSalida = 0;
    vector<Profesor*> * profesores = new std::vector<Profesor*>;
    vector<Alumno*> * alumnos = new std::vector<Alumno*>;
    vector<Asignatura*> * asignaturas = new std::vector<Asignatura*>;
public:
    Menu(){
        cout << "----- Bienvenido a nuestro sistema de matriculacion de alumnos! -------" << endl;
        while (banderaSalida == 0){ // se muestra al usuario las operaciones
            cout << "Selecione una opcion: ";
            std::cout << "\n1 Crear Profesor \n2 Crear Alumno \n3 Crear Asignatura  \n4 Agregar alumnos a una asignatura  \n5 Mostrar la informacion de una asignatura \n6 Mostrar las asignaturas de un alumno \n7 Borrar profesor \n8 Borrar Alumno \n9 Borrar Asignatura \n0 Finalizar programa" << endl;
            std::cin >> seleccion;
            switch (seleccion) {
                case '1': { // crear profesor
                    cout << "Indique el nombre del profesor: " << endl;
                    string nombre;
                    cin >> nombre;
                    cout << "Indique el apellido del profesor: " << endl;
                    string apellido;
                    cin >> apellido;
                    cout << "Indique el codigo de empleado del profesor: " << endl;
                    int codigoDeEmpleado;
                    cin >> codigoDeEmpleado;
                    Profesor *profesorAAgreagr = new Profesor(nombre, apellido, codigoDeEmpleado);
                    profesores->push_back(profesorAAgreagr);
                    break;
                }
                case '2': { // crear alumno
                    cout << "Indica el nombre del alumno: " << endl;
                    string nombre;
                    cin >> nombre;
                    cout << "Indique el apellido del alumno: " << endl;
                    string apellido;
                    cin >> apellido;
                    cout << "Indique el numero de expediente: " << endl;
                    int codigoDeEmpleado;
                    cin >> codigoDeEmpleado;
                    Alumno *alumnoAAgregar = new Alumno(nombre, apellido, codigoDeEmpleado);
                    alumnos->push_back(alumnoAAgregar);
                    break;
                }
                case '3': { //crear asignatura
                    if (profesores->size()>=1){
                        for (int i = 0; i < profesores->size(); ++i) {
                            cout << "----Profesores----"<< "\n" << i << "-" <<profesores->at(i)->imprimirProfesor() << endl; //Presentamos un listado de los profesores disponibles
                        }
                        string datoProfesor;
                        cout << "Indique la posicon dentro del vector del profesor que dara la asignatura: " << endl;
                        cin >> datoProfesor;
                        int prof1;
                        try{
                            prof1=stoi(datoProfesor);
                            cout << "Indique el nombre de la asignatura: " << endl;
                            string nombre;
                            cin.ignore();
                            getline(cin, nombre);
                            cout << "Indique el codigo de la asignatura: " << endl;
                            string codigo;
                            cin >> codigo;
                            cout << "Indique el anio de la asignatura: " << endl;
                            string stringAnio;
                            cin >> stringAnio;
                            int anio=stoi(stringAnio);
                            asignaturas->push_back(new Asignatura(codigo, nombre, anio, profesores->at(prof1))); //Se agrega a la lista de asginaturas la asginatura creada
                            cout << "Se creo la asignatura con exito !" << endl;
                            asignaturas->at(asignaturas->size()-1)->imprimirAsignatura();
                        }catch(...){
                            cout << "-----Error, no se ingreso un numero ------" << endl;
                        }
                    }else{
                        cout << "Deben de existir al menos un profesor" << endl;
                    }
                    break;
                }

                case '4': { // Agregar alumnos a la asignatura
                    if (alumnos->size()>=1 && asignaturas->size()>=1){
                        for (int i = 0; i < alumnos->size(); ++i)
                            cout << "----Alumnos----" << "\n"<< i << "-" << alumnos->at(i)->imprimirAlumno() << endl; //Presentamos un listado de los alumnos disponibles
                        for (int j = 0; j < asignaturas->size(); ++j)
                            cout << "----Asignatura----" << "\n"<< j << "-" << asignaturas->at(j)->imprimirAsignaturaLite() << endl; //Presentamos un listado de las asignaturas disponibles
                        cout << "Indique el codigo del alumno: " << endl;
                        string stringCodigoAlumno,stringCodigoAsignatura;
                        cin >> stringCodigoAlumno;
                        int intCodigoAlumno;
                        cout << "Indique el codigo de la asignatura: : " << endl;
                        cin >> stringCodigoAsignatura;
                        try{
                            Alumno* alumnoAAgregar = new Alumno();
                            Asignatura* asignaturaAEnlazar = new Asignatura();
                            intCodigoAlumno=stoi(stringCodigoAlumno);
                            for(int i=0;i<alumnos->size();i++){
                                if(intCodigoAlumno==(alumnos->at(i)->getCodigoAlumno())) {
                                    alumnoAAgregar=alumnos->at(i);
                                }else{
                                    cout << "---- Error, el codigo de alumno ingresado no existe ------" << endl;
                                }
                            };

                            for(int i=0;i<asignaturas->size();i++){
                                if(stringCodigoAsignatura==(asignaturas->at(i)->getCodigo())) {
                                    asignaturaAEnlazar=asignaturas->at(i);
                                }else{
                                    cout << "---- Error, el codigo de la asginatura ingresado no existe ------" << endl;
                                }
                            };
                            asignaturaAEnlazar->getAlumnosAsignados()->push_back(alumnoAAgregar);
                        }catch(...){
                            cout << "-----Error, no se ingreso un numero ------" << endl;
                        }
                    }else{
                        cout << "---- Error,debe de existir al menos un alumno y una asginatura" << endl;
                    }
                    break;
                }

                case '5': { // listar la informacion de una asignatura
                    if (asignaturas->size()>=1){
                        for (int i = 0; i < asignaturas->size(); ++i) {
                            cout << "Asignatura: " << i << "-" << asignaturas->at(i)->imprimirAsignaturaLite() << endl; // se listan las matrices creadas en el vector listas para operar
                        }
                        cout << "indique la asignatura de la que desea ver la informacion " << endl;
                        int asig1;
                        cin >> asig1;
                        asignaturas->at(asig1)->imprimirAsignatura();

                    }else{
                        cout << "Deben de existir al menos una asignatura" << endl;
                    }
                    break;

                }
                case '6': { //listar las asignaturas de un alumno
                    if (alumnos->size()>=1){
                        for (int i = 0; i < alumnos->size(); ++i) {
                            cout << "Alumno: " << i << "-" << alumnos->at(i)->imprimirAlumno() << endl; // se listan las matrices creadas en el vector listas para operar
                        }
                        cout << "indique el alumno del que desea ver las asignaturas " << endl;
                        int alumn1;
                        cin >> alumn1;
                        vector<Asignatura*> * asignaturasmatriculadas = new vector<Asignatura*>;
                        for (int i=0; i<asignaturas->size(); i++){
                            if (asignaturas->at(i)->contieneAlumno(alumnos->at(alumn1))){
                                asignaturasmatriculadas->push_back(asignaturas->at(i));
                            }
                        }
                        for (int i=0; i<asignaturasmatriculadas->size();i++){
                            cout << asignaturasmatriculadas->at(i)->imprimirAsignaturaLite() << endl;
                        }
                        delete asignaturasmatriculadas;

                    }else{
                        cout << "Deben de existir al menos una asignatura" << endl;
                    }
                    break;
                }
                case '7':{  //Borrar profesor
                    if (profesores->size()>=1){
                        for (int i = 0; i < profesores->size(); ++i) {
                            cout << "Profesor " << i << "-" << profesores->at(i)->imprimirProfesor() << endl; //Presentamos un listado de los profesores disponibles
                        }
                        cout << "Indique el profesor que desea borrar: " << endl;
                        int prof1;
                        cin >> prof1;
                        delete profesores->at(prof1);
                        }else{
                        cout << "Deben de existir al menos un profesor" << endl;
                    }
                    break;

                }
                    case '8':{  //Borrar Alumno
                        if (alumnos->size()>=1){
                            for (int i = 0; i < alumnos->size(); ++i) {
                                cout << "Alumno " << i << "-" << alumnos->at(i)->imprimirAlumno() << endl; //Presentamos un listado de los profesores disponibles
                            }
                            cout << "Indique el alumno que desea borrar: " << endl;
                            int alumn1;
                            cin >> alumn1;
                            delete alumnos->at(alumn1);
                        }else{
                            cout << "Deben de existir al menos un alumno" << endl;
                        }
                    break;
                }case '9':{  //Borrar Asignatura
                    if (asignaturas->size()>=1){
                        for (int i = 0; i < asignaturas->size(); ++i) {
                            cout << "Asignatura " << i << "-" << asignaturas->at(i)->imprimirAsignaturaLite() << endl; //Presentamos un listado de los profesores disponibles
                        }
                        cout << "Indique la asignatura que desea borrar: " << endl;
                        int asig1;
                        cin >> asig1;
                        delete asignaturas->at(asig1);
                    }else{
                        cout << "Deben de existir al menos una asignatura" << endl;
                    }
                    break;
                }case '0':{  //Finalizar programa
                    banderaSalida++;
                    try{
                        delete profesores;
                        delete alumnos;
                        delete asignaturas;
                    }catch(...) {
                    }
                    break;
                }
                default:{
                    cout << "Seleccione una opcion disponible" << endl;
                }
            }
        }
    }
};
#endif //EJERCICIO_6_MENU_H