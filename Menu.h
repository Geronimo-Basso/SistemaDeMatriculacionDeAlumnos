//
// Created by Geronimo Basso on 6/11/22.
//
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
    std::vector<Profesor*> * profesores = new std::vector<Profesor*>;
    std::vector<Alumno*> * alumnos = new std::vector<Alumno*>;
    std::vector<Asignatura*> * asignaturas = new std::vector<Asignatura*>;
public:
    Menu(){
        while (banderaSalida == 0){ // se muestra al usuario las operaciones
            cout << "Selecione una opcion: ";
            std::cout << "\n1 Crear Matriz, \n2 Sumar Matrices, \n3 restar matrices, \n4 multiplicar matriz, \n5 matriz traspuesta, \n6 determinante de la matriz(solo en los casos 1x1,2x2 y3x3), \n7 salir" << endl;
            std::cin >> seleccion;
            switch (seleccion) {
                case '1': { // crear profesor
                    cout << "indique el nombre " << endl;
                    string nombre;
                    cin >> nombre;
                    cout << "indique el apellido " << endl;
                    string apellido;
                    cin >> apellido;
                    cout << "indique el codigo de empleado " << endl;
                    int codigoDeEmpleado;
                    cin >> codigoDeEmpleado;
                    Profesor *prof1 = new Profesor(nombre, apellido, codigoDeEmpleado);
                    profesores->push_back(prof1);
                    break;

                }

                case '2': { // crear alumno
                    cout << "indique el nombre " << endl;
                    string nombre;
                    cin >> nombre;
                    cout << "indique el apellido " << endl;
                    string apellido;
                    cin >> apellido;
                    cout << "indique el numero de expediente" << endl;
                    int codigoDeEmpleado;
                    cin >> codigoDeEmpleado;
                    Alumno *alumn1 = new Alumno(nombre, apellido, codigoDeEmpleado);
                    alumnos->push_back(alumn1);
                    break;
                }

                case '3': { // crear asignatura
                    if (profesores->size()>=1){
                        for (int i = 0; i < profesores->size(); ++i) {
                            cout << "Profesor " << i << profesores->at(i)->imprimirProfesor << endl; // se listan las matrices creadas en el vector listas para operar
                        }
                        cout << "indique la matriz a sumar 1 " << endl;
                        int matrizAlpha;
                        cin >> matrizAlpha;
                        operacionesMatriciales * op1 = new operacionesMatriciales; // se crea un objeto operacion en el free store
                        matrices->push_back(op1->sumarMatrices(matrices->at(matrizAlpha), matrices->at(matrizBravo))); // se crea la nueva matriz creada al vector
                        delete op1; // se borra el objeto operacion
                        matrices->at(matrices->size()-1)->imprimirMatriz();
                    }else{
                        cout << "Deben de existir al menos dos matrices" << endl;
                    }
                    break;
                }

                case '4': { // anadir alumnos a la asignatura

                }

                case '5': { // listar la informacion de una asignatura
                    // codigo de asignatura + nombre + ano
                    //________________________________________________
                    // en otra fila profesor
                    //________________________________________________
                    // mas abajo aun listado de alumnos con for

                }
                case '6': { //listar las asignaturas de un alumno

                }
                case '7':{  // salida

                }
                default:{
                    cout << "Seleccione una opcion disponible" << endl;
                }


            }
        }
    }


};


#endif //EJERCICIO_6_MENU_H
