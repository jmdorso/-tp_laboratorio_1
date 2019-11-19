/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

int main(void)
{
	int option;
	int optionCarga;
	char seguir='S';
	char guardar;
	LinkedList *listaEmpleados = ll_newLinkedList();


	startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort

	do {
		printf("----------------------------------------------------------------------------------\n");
		printf("\tTrabajo Practico n3. Uso LinkedList || Juan Martin Dorso\n\n");
		printf("01. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
		printf("02. Alta de empleado.\n");
		printf("03. Modificar datos de empleado.\n");
		printf("04. Baja de empleado.\n");
		printf("05. Listar Empleados.\n");
		printf("06. Ordenar Empleados.\n");
		printf("07. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
		printf("08. Salir.\n\n");


		if (getInt(&option, "\tIngrese opcion: ", "\nError", 1, 8,CANT_REINTENTOS) == 0)
		{
			switch (option)
			{
			case 1:
				getInt(&optionCarga, "\t\nIngrese opcion: [1]dataOriginal [2]dataModificado: ", "\nError", 1, 2,CANT_REINTENTOS);
				if(optionCarga==1)
				{
					controller_loadFromText("dataORIGINAL.csv", listaEmpleados);
				}
				if(optionCarga==2)
				{
					controller_loadFromText("data.csv", listaEmpleados);
				}
				break;
			case 2:
				controller_addEmployee(listaEmpleados);
				break;
			case 3:
				controller_editEmployee(listaEmpleados);
				break;
			case 4:
				controller_removeEmployee(listaEmpleados);
				break;
			case 5:
				controller_ListEmployee(listaEmpleados);
				break;
			case 6:
				controller_sortEmployee(listaEmpleados);
				break;
			case 7:
				controller_saveAsText("data.csv",listaEmpleados);
				break;
			case 8:
				getChar(&guardar,
				"\nDesea guardar antes de salir? Ingrese s o n (o cualquier tecla para seguir en el programa): ",
				"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
				'a',
				'z',
				CANT_REINTENTOS);
	           	if(guardar == 's' || guardar == 'S')
	           	{
	    			controller_saveAsText("data.csv",listaEmpleados);
	               	ll_deleteLinkedList(listaEmpleados);
	               	printf("\n\n\tDatos guardados. El programa se cerrara...");
	               	seguir = 'n';
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

































