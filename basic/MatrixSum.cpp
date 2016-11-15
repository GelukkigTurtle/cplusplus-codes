// Compiladores. Programa que valida una sentencia para declarar variables

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>

using namespace std;
using std::cout;
using std::endl;


void main () //INICIO
  {
	//declaramos la matriz 2x2
	float matriz [2][2];
	
	// variable media donde guardaremos la media aritmetica de todos los elementos
	float  media = 0; 
	//variabel suma donde acumularemos todos los valores de la matriz
	float suma = 0;
	cout<<"Llenar la matriz\n";
	//creamos el  primer bucle FOR para controlar las filas de la matriz
	for(int i=0; i<2;i++){
			//creamos el  segundo bucle FOR para controlar las columnas de la matriz
		for (int j = 0; j<2;j++){
		   //leemos cada elemento de la matriz
	       cout<<"elemento["<<i+1<<"]["<<j+1<<"]: ";
		   cin>>matriz[i][j];
		   cout<<"\n";

		   // acumulamos cada numero ingresado en la variable 'suma'
		   suma = suma + matriz[i][j];
		  
		}
	}// se saldra media vez se hayan ingresado los 4 elementos de la matriz 2x2
	
	//ya que tenemos la suma de todos los elementos en la variable 'suma' podemos caluclar la media aritmetica
	media = suma / 4; // la media es el total entre el numero de elementos que son 4 ya que es una matriz 2x2

	//imprimimos en pantalla los resultados
	cout<<"\nSUMA DE LA MATRIZ: "<<suma;
	cout<<"\nMEDIA DE LA MATRIZ: "<<media;


  }//FIN