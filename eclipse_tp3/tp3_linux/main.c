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
char seguir='S';
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
			controller_loadFromText("data.csv", listaEmpleados);
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
		case 10:
			printf("\n\nEl programa se cerrara...\n");
			seguir='n';
			break;
		}
	}
} while (seguir == 'S');
return 0;
}

