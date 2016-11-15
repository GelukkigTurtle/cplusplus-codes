#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;
int main()
{
	//variables
	char cadenaDeTexto[50];
    char sentenciaOriginal [50];
	char tipoDeDatos [5][10] ={"entero", "flotante" ,"cadena","fecha","booleano"};
	char *ptr;
    bool error = true;
    int longitudDeCadena =0;
	cout<<"--------------------------------------------------------\n";
	cout<<"Introducir una cadena de texto:\n\n";
	gets(cadenaDeTexto);
	strcpy(sentenciaOriginal, cadenaDeTexto);
	cout<<"--------------------------------------------------------\n";
	cout<<"Verificando errores de Sintaxis...\n";
    ptr = strtok(cadenaDeTexto, " ");
	int cantidadDeTipoDeDatos = 4;
    puts(sentenciaOriginal);
    cout<<endl;
    cout<<"Tipo de dato introducido :  ";
    cout<<cadenaDeTexto<<endl;
	for (int i=0; i<cantidadDeTipoDeDatos; i++)
	{
		if (strcmp(cadenaDeTexto, tipoDeDatos[i]) == 0)
         error= false;
		
	}
	
	cout<<"--------------------------------------------------------\n";
	cout<<endl;
	
	if(!error){
	cout<<"~~FELICIDADES SINTAXIS SIN ERRORES~~\n";
	cout<<endl;
	cout<<endl;
	cout<<"Presione una tecla para salir...\n\n";
	return 1;
	
	}else{
	cout<<endl;
	cout<<endl;
  cout<<"Tipo de dato no valido\n";
	cout<<"Vuelva a intentarlo ...\n\n";
	main();
	}	

}