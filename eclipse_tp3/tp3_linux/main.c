#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


/*
int f1(int *a, int b,int (*foo)(int,int)) {
	*a = *a * 2;
	*a = foo(*a,b);
	return (*a);
}

int f2(int a, int b) {
	 a = b*b;
	 return a;
}


enum colors {lets,find,course};
int main()
{
	printf("%d %d %d",course,lets,find);
	return 0;
}
*/



int main() {

int option;
int optionCarga;
int modoBinario=0;
int modoTexto=0;
char seguir='S';
char guardar;
LinkedList *listaEmpleados = ll_newLinkedList();

do {
	printf("----------------------------------------------------------------------------------\n");
	printf("\tTrabajo Practico n3. Uso LinkedList || Juan Martin Dorso\n\n");
	printf("01. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("02. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("03. Alta de empleado.\n");
	printf("04. Modificar datos de empleado.\n");
	printf("05. Baja de empleado.\n");
	printf("06. Listar Empleados.\n");
	printf("07. Ordenar Empleados.\n");
	printf("08. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("09. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("10. Salir.\n\n");


	if (getInt(&option, "\tIngrese opcion: ", "\nError", 1, 10,CANT_REINTENTOS) == 0)
	{
		switch (option)
		{
		case 1:
			if(modoBinario != 1)
			{
				getInt(&optionCarga, "\t\nIngrese opcion: [1]dataOriginal [2]dataModificado: ", "\nError", 1, 2,CANT_REINTENTOS);
				if(optionCarga==1)
				{
					controller_loadFromText("dataORIGINAL.csv", listaEmpleados);
				}
				if(optionCarga==2)
				{
					controller_loadFromText("data.csv", listaEmpleados);
				}
				modoTexto=1;
			}
			else
			{
				printf("\n\nYa cargo lista en el otro modo\n\n");
			}
			break;
		case 2:
			controller_loadFromBinary("data.bin",listaEmpleados);
			modoBinario=1;
			break;
		case 3:
			controller_addEmployee(listaEmpleados);
			break;
		case 4:
			controller_editEmployee(listaEmpleados);
			break;
		case 5:
			controller_removeEmployee(listaEmpleados);
			break;
		case 6:
			controller_ListEmployee(listaEmpleados);
			break;
		case 7:
			controller_sortEmployee(listaEmpleados);
			break;
		case 8:
			if(modoTexto==1 && modoBinario==0)
			{
				controller_saveAsText("data.csv",listaEmpleados);
			}
			else
			{
				printf("\n\nCargo lista en el otro modo\n\n");
			}
			break;
		case 9:
			controller_saveAsBinary("data.bin",listaEmpleados);
			break;
		case 10:
			getChar(&guardar,
			"\nDesea guardar antes de salir? Ingrese s o n (o cualquier tecla para seguir en el programa): ",
			"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
			'a',
			'z',
			CANT_REINTENTOS);
           	if(guardar == 's' || guardar == 'S')
           	{
    			if(modoBinario==1 && modoTexto==0)
    			{
    				controller_saveAsBinary("data.bin",listaEmpleados);
               		ll_deleteLinkedList(listaEmpleados);
               		printf("\n\n\tDatos guardados. El programa se cerrara...");
               		seguir = 'n';
    			}
    			if(modoTexto==1 && modoBinario==1)
    			{
    				controller_saveAsText("data.csv",listaEmpleados);
    				controller_saveAsBinary("data.bin",listaEmpleados);
               		ll_deleteLinkedList(listaEmpleados);
               		printf("\n\n\tDatos guardados. El programa se cerrara...");
               		seguir = 'n';
    			}
    			if(modoTexto==1 && modoBinario==0)
    			{
    				controller_saveAsText("data.csv",listaEmpleados);
               		ll_deleteLinkedList(listaEmpleados);
               		printf("\n\n\tDatos guardados. El programa se cerrara...");
               		seguir = 'n';
    			}

           	}
           	else if(guardar == 'n' || guardar == 'N')
           	{
           		ll_deleteLinkedList(listaEmpleados);
    			printf("\n\n\tNo se guardaran los datos. El programa se cerrara...\n");
    			seguir='n';
           	}
           	else
           	{
           		printf("\n\n\tContinuar con el programa..\n");
           	}
			break;
		}
	}
} while (seguir == 'S');
return 0;
}

