#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;
int main()
{
	//variables
	char cadenaDeTexto[50];
	int longitudDeCadena =0;
	int contParentesisAbrir =0;
	int contParentesisCerrar =0;
	int contCorcheteAbrir = 0;
	int contCorcheteCerrar = 0;
	int contLlaveAbrir = 0;
	int contLlaveCerrar = 0;
	
	int totalParentesis = 0;
	int totalCorchete = 0;
	int totalLlave = 0;
	cout<<"--------------------------------------------------------\n";
	cout<<endl;
	cout<<endl;
	cout<<"Introducir una cadena de texto:\n\n";
	gets(cadenaDeTexto);
	
	cout<<"--------------------------------------------------------\n";
	cout<<"Verificando errores de Sintaxis...\n";
	longitudDeCadena = strlen(cadenaDeTexto);
	for (int i=0; i<longitudDeCadena; i++)
	{
		char valor;
		valor = cadenaDeTexto[i];
		//Parentesis
		if (valor == '(')
		contParentesisAbrir++;
		if (valor == ')')
		contParentesisCerrar++;
		//Corechete
		if (valor=='[')
		contCorcheteAbrir++;
		if (valor==']')
		contCorcheteCerrar++;
		//Llave
		if (valor=='{')
		contLlaveAbrir++;
		if (valor=='}')
		contLlaveCerrar++;
	}
	totalParentesis =  contParentesisAbrir - contParentesisCerrar;
	totalCorchete = contCorcheteAbrir - contCorcheteCerrar;
	totalLlave = contLlaveAbrir - contLlaveCerrar;
	bool error = false;
	//ERRORES DE SINTAXIS
	cout<<"--------------------------------------------------------\n";
	puts(cadenaDeTexto);
	cout<<endl;
	//Parentesis
	if(totalParentesis > 0){
	cout<<"ERROR SINTAXIS: faltan "<<totalParentesis<<" , ')' para cerrar la expresion\n";
	error = true;
	}else if (totalParentesis < 0){
	cout<<"ERROR SINTAXIS: faltan "<<totalParentesis*-1<<" , '(' para cerrar la expresion\n";
	error = true;
	}
	//Corchetes
	if(totalCorchete > 0){
	cout<<"ERROR SINTAXIS: faltan "<<totalCorchete<<" , ']' para cerrar la expresion\n";
	error = true;
	}else if (totalCorchete < 0){
	cout<<"ERROR SINTAXIS: faltan "<<totalCorchete*-1<<" , '[' para cerrar la expresion\n";
	error = true;
	}
	//Llaves
	if(totalLlave > 0){
	cout<<"ERROR SINTAXIS: faltan "<<totalLlave<<" , '}' para cerrar la expresion\n";
	error = true;
	}else if (totalCorchete < 0){
	cout<<"ERROR SINTAXIS: faltan "<<totalLlave*-1<<" , '{' para cerrar la expresion\n";
	error = true;
	}
	if(!error){
	cout<<"~~FELICIDADES SINTAXIS SIN ERRORES~~\n";
	cout<<endl;
	cout<<endl;
	cout<<"Presione una tecla para salir...\n\n";
	return 1;
	
	}else{
	cout<<endl;
	cout<<endl;
	cout<<"Vuelva a intentarlo ...\n\n";
	main();
	}	

}