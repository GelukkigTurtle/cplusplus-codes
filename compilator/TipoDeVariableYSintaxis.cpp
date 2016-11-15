// Compiladores. Programa que valida una sentencia para declarar variables

#include <iostream>
#include <cstring>
#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>

using namespace std;
using std::cout;
using std::endl;

//variable global
int longitudDeTipo = 0;
int mostrarLeyenda = 1;

bool validaTipo(char cadenaDeTexto[1000]) {
    //variables
    char sentenciaOriginal [1000];
    char tipoDeDatos [5][10] = {"entero", "flotante", "cadena", "fecha", "booleano"};

    char *ptr;
    bool error = true;
    strcpy(sentenciaOriginal, cadenaDeTexto);
    cout << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Verificando errores de Sintaxis...\n";
    ptr = strtok(cadenaDeTexto, " ");
    int cantidadDeTipoDeDatos = 4;
    longitudDeTipo = strlen(cadenaDeTexto);
    for (int i = 0; i < cantidadDeTipoDeDatos; i++) {
        if (strcmp(cadenaDeTexto, tipoDeDatos[i]) == 0)
            error = false;

    }

    cout << "--------------------------------------------------------\n";
    cout << endl;

    return error;
}

int main() {
    //variables
    char arregloNumeros [10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    char arregloCaracEspecial [50] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '/', '[', ']', '<', '>'};
    char cadenaDeTexto[50];
    char cadena [50];
    char *token;
    char tokenAux [50];
    char salir[30];
    char cadenaEnMinuscula [50];
    bool error = false;
    bool existePuntoyComa = false;
    bool mayuscula = true;
    bool todasMayusculas = false;
    bool numAlFinal = false;
    bool caracterEspecial = false;
    bool existePuntoFinal = false;
    bool minusculaDetected = false;
    int longitudDeCadena = 0;
    int longitudDeCaracEspeciales = 0;
    longitudDeCaracEspeciales = strlen(arregloCaracEspecial);
    if (mostrarLeyenda == 1) // validamos la leyenda para que solo la muestra 1 vez en toda la ejecucion del programa.
    {
        cout << "---------------------------------------------------------------\n";
        cout << "\tDECLARACION DE VARIABLES EN LENGUAJE TURTLE\n";
        cout << "---------------------------------------------------------------\n";
        cout << endl;
        cout << "CONDICIONES:\n";
        cout << "a) La sentencia debe terminar con '.' (Punto)\n";
        cout << "b) Las variables deben ser escritas en MAYUSCULA \n";
        cout << "c) Las variables deben contener un numero al final \n";
        cout << "d) Las variables NO deben contener caracteres especiales \n";
        cout << endl;
        cout << "TIPOS DE DATOS DISPONIBLES: \n";
        cout << "- entero\n";
        cout << "- flotante\n";
        cout << "- cadena\n";
        cout << "- fecha\n";
        cout << "- booleano\n";
    }
    cout << endl;
    mostrarLeyenda++;
    cout << "Introducir la sentencia:\n\n";
    gets(cadenaDeTexto);
    strcpy(cadena, cadenaDeTexto);
    error = validaTipo(cadenaDeTexto); //llamamos la funcion para validar el tipo de dato
    if (!error) {
        longitudDeCadena = strlen(cadena);
        longitudDeTipo = longitudDeTipo + 2;
        for (int i = longitudDeTipo; i < longitudDeCadena; i++) {
            if (cadena[i] == ';') {
                existePuntoyComa = true;
            }
            if (cadena[longitudDeCadena - 1] == '.') {
                existePuntoFinal = true;
            } else {
                if (cadena[longitudDeCadena - 1] == arregloNumeros[i])
                    numAlFinal = true;

            }

            if (isalpha(cadena[i])) {
                if (!isupper(cadena[i]))
                    minusculaDetected = true;
            }
            for (int w = 0; w < longitudDeCaracEspeciales; w++) {
                if (cadena[i] == arregloCaracEspecial[w]) {
                    caracterEspecial = true;
                }
            }

        }
        if (existePuntoFinal) {
            if (existePuntoyComa) {

                token = strtok(cadena, ";");
                while (token != NULL) {
                    strcpy(tokenAux, token);
                    longitudDeCadena = 0;
                    longitudDeCadena = strlen(tokenAux);

                    for (int x = longitudDeTipo; x < longitudDeCadena; x++) {
                        if (isalpha(tokenAux[x])) {
                            if (isupper(tokenAux[x])) {
                                if (mayuscula == true) {
                                    mayuscula = true;
                                }
                            } else {
                                mayuscula = false;

                            }
                        }
                        for (int z = 0; z < longitudDeCadena; z++) {
                            if (tokenAux[longitudDeCadena - 1] == arregloNumeros[z]) {
                                numAlFinal = true;
                            }
                            if (tokenAux[longitudDeCadena - 1] == '.') {
                                if (tokenAux[longitudDeCadena - 2] == arregloNumeros[z]) {
                                    numAlFinal = true;
                                }
                            }
                        }
                        for (int w = 0; w < longitudDeCaracEspeciales; w++) {
                            if (tokenAux[x] == arregloCaracEspecial[w]) {
                                caracterEspecial = true;
                            }
                        }

                    }

                    token = strtok(NULL, ";");
                    longitudDeTipo = 0;
                }//fin del recorrido del token
            } else {
                token = strtok(cadena, ".");


                while (token != NULL) {

                    strcpy(tokenAux, token);
                    longitudDeCadena = 0;
                    longitudDeCadena = strlen(tokenAux);
                    for (int x = longitudDeTipo; x < longitudDeCadena; x++) {
                        if (isalpha(tokenAux[x])) {
                            if (isupper(tokenAux[x])) {
                                if (mayuscula == true) {
                                    mayuscula = true;
                                }
                            } else {
                                mayuscula = false;
                            }
                        }
                        for (int z = 0; z < longitudDeCadena; z++) {
                            if (tokenAux[longitudDeCadena - 1] == arregloNumeros[z]) {
                                numAlFinal = true;
                            }
                        }
                        for (int w = 0; w < longitudDeCaracEspeciales; w++) {
                            if (tokenAux[x] == arregloCaracEspecial[w]) {
                                caracterEspecial = true;
                            }
                        }
                    }
                    token = strtok(NULL, " ");
                    longitudDeTipo = 0;
                }//fin del recorrido del token

            }
        }

        if (mayuscula == true && numAlFinal == true && caracterEspecial == false && existePuntoFinal == true && minusculaDetected == false) {
            cout << endl;
            cout << endl;
            cout << "FELICIDADES SENTENCIA SIN ERRORES\n";
        }
        if (!existePuntoFinal) {
            cout << "ERROR: La sentencia debe terminar con '.'\n";
        }
        if (mayuscula == false || minusculaDetected == true) {
            cout << "ERROR: Las variables deben ser MAYUSCULAS\n";
        }
        if (!numAlFinal) {
            cout << "ERROR: las variables deben tener un numero al final\n";
        }
        if (caracterEspecial) {
            cout << "ERROR: las variables no deben contener caracteres especiales\n";
        }
        gets(salir);
        return 0;
    } else {

        cout << "ERROR: Tipo de dato no valido\n";
        cout << endl;
        gets(salir);
        return 0;
    }

}