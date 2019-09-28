/*
 ============================================================================
 Name        : TpNro2.c
 Author      : J.M.Dorso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"
#include "arrayEmployees.h"

#define ALTA_OK 1
#define ALTA_DNS 0

int main(void)
{
	char seguir = 's';
	char salir;
	char confirmarBaja;
	char nombre[50];
	Employee unEmpleado;
	Employee aEmployee[CANT_EMPLEADOS];
	int opcion;
	int flagAlta=ALTA_DNS;
	int auxId;

	initLugarLibreEmployees(aEmployee,CANT_EMPLEADOS);
	imprimirArrayEmployees(aEmployee,10);

	do
	{
		printf("----------------------------------------------------------------------------------\n");
	    printf("\tTrabajo Practico n2. Nomina de Empleados || Juan Martin Dorso\n\n");
	    printf("1. Altas\n");
	    printf("2. Modificar\n");
	    printf("3. Baja\n");
	    printf("4. Informar\n");
	    printf("5. Salir\n\n");

	    if(getInt(&opcion,"\tIngrese opcion: ","\nError",1,5,CANT_REINTENTOS)==0)
	    {
	    	switch(opcion)
	    	{
	    		case 1:
	    				if(altaUnSoloEmployee(&unEmpleado)==EXIT_SUCCESS)
	    				{
	    					altaEmployeePorId(aEmployee,CANT_EMPLEADOS,unEmpleado);
		    				imprimirArrayEmployeesStatusOk(aEmployee,10);
		    				flagAlta=ALTA_OK;
	    				}
	    				break;
	    		case 2:
	    				break;
	    		case 3:
	    				if(flagAlta == ALTA_DNS)
	    				{
	    					printf("\nERROR. Falta ingresar al menos un empleado.\n\n");
	    					break;
	    				}
	    				getInt(&auxId,"\nIngrese el ID: ","\nError\n",1,CANT_EMPLEADOS,CANT_REINTENTOS);
	    				unEmpleado.idEmployee = auxId;
	    				auxId = buscarEmployeePorId(aEmployee,CANT_EMPLEADOS,unEmpleado.idEmployee);
	    				printf("Quiere Eliminar el siguiente empleado: \n");
	    				printf("Nombre: %s - Apellido: %s - ID: %d",aEmployee[auxId].name,aEmployee[auxId].lastName,aEmployee[auxId].idEmployee);
	    				getChar(&confirmarBaja,
	    						"\nSeguro desea dar de baja? Ingrese s (o cualquier tecla para continuar): ",
								"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
								'a',
								'z',
								CANT_REINTENTOS);
                    	if(confirmarBaja == 's' || confirmarBaja == 'S')
                    	{
    	    				bajaEmployeePorId(aEmployee,CANT_EMPLEADOS,unEmpleado.idEmployee);
                    	}
	    				break;
	    		case 4:
	    				break;
	    		case 5:
	    				getChar(&salir,
	    						"\nSeguro desea salir? Ingrese s (o cualquier tecla para continuar): ",
								"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
								'a',
								'z',
								CANT_REINTENTOS);
                    	if(salir == 's' || salir == 'S')
                    	{
                    		printf("\n\n\tEl programa se cerrara.");
                    		seguir = 'n';
                    	}
	    				break;
	    	}
	    }
	}while(seguir=='s' || seguir=='S');
	return EXIT_SUCCESS;
}
