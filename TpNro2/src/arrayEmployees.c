/*
 * arrayEmployees.c
 *
 *  Created on: Sep 27, 2019
 *      Author: mati
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"



/** \brief va generando un ID secuencial cada vez que es llamada
 * \param void, no recibe ningun paramentro.
 * \return el id incrementado cada vez que es llamada(debido a que esta declarada como static
 * no pierde el valor anterior)
 *
 */

static int generarId(void)
{
	static int idIncremental=0;
	idIncremental++;

	return idIncremental;
}

/** \brief Inicializa un array de Empleados con el estado libre(es decir, un array vacio y listo para cargar)
 * \param *aArray es el array de empleados
 * \param cantidad es la cantidad de elementos del array
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */


int initLugarLibreEmployees(Employee *aArray, int cantidad)
{
	int retorno = EXIT_ERROR;
	int i;

	if(aArray != NULL && cantidad >0)
	{
		for(i=0;i<cantidad;i++)
		{
			aArray[i].status = STATUS_EMPTY;
		}
	retorno = EXIT_SUCCESS;
	}
	return retorno;
}

/** \brief Da de alta un empleado previamente cargado en el array (en la primer posicion libre que encuentra)
 * \param *aArray es el array de empleados
 * \param cantidad es la cantidad de elementos del array
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

int altaEmployeePorId(Employee *aArray, int cantidad,Employee employee)
{
	int retorno = EXIT_ERROR;
	int posArray;

	if(aArray != NULL && cantidad >0)
	{
		posArray = buscarLugarLibreEmployee(aArray,cantidad);
		if(posArray >= 0 && buscarEmployeePorId(aArray,cantidad,employee.idEmployee) == -1)
			{
				employee.status=STATUS_NOT_EMPTY;
				employee.idEmployee=generarId();
				aArray[posArray] = employee;
				retorno = EXIT_SUCCESS;
			}
	}
	return retorno;
}

/** \brief busca el primer lugar libre en el array
 * \param *aArray es el array de empleados
 * \param cantidad es la cantidad de elementos del array
 * \return -1 si hay algun error o la POSICION EN EL ARRAY del primer elemento libre
 *
 */

int buscarLugarLibreEmployee(Employee *aArray, int cantidad)
{
	int retorno = EXIT_ERROR;
	int posArray;

	if(aArray != NULL && cantidad >0)
	{
		for(posArray=0;posArray<cantidad;posArray++)
		{
			if(aArray[posArray].status == STATUS_EMPTY)
			{
				retorno = posArray;
				break;
			}
		}
	}
	return retorno;
}

/** \brief busca el elemento con el ID indicado en el array
 * \param *aArray es el array de empleados
 * \param cantidad es la cantidad de elementos del array
 * \param id es el ID a buscar
 * \return -1 si hay algun error o la POSICION EN EL ARRAY del elemento con dicho ID
 *
 */

int buscarEmployeePorId(Employee *aArray, int cantidad,int id)
{
	int retorno = EXIT_ERROR;
	int posArray;

	if(aArray != NULL && cantidad >0 && id >= 0)
	{
		for(posArray=0;posArray<cantidad;posArray++)
		{
			if(aArray[posArray].status == 1)
			{
				if(aArray[posArray].idEmployee == id)
				{
				retorno = posArray;
				break;
				}
			}
		}
	}
	return retorno;
}

int altaUnSoloEmployee(Employee *employee)
{
	int retorno = EXIT_ERROR;
	char bufferName[CANT_CARACTERES];
	char bufferLastName[CANT_CARACTERES];
	float bufferSalary;
	int bufferSector;

	getString(bufferName,"\nIngrese Nombre: ","\nError",1,CANT_CARACTERES,CANT_REINTENTOS);
	retorno = esNombreOApellido(bufferName,"No es un nombre valido");
	if(retorno == EXIT_SUCCESS)
	{
		getString(bufferLastName,"\nIngrese Apellido: ","\nError",1,CANT_CARACTERES,CANT_REINTENTOS);
		retorno = esNombreOApellido(bufferLastName,"No es un apellido valido");
		if(retorno == EXIT_SUCCESS)
		{
			retorno = getFloat(&bufferSalary,"\nIngrese Salario: ","\nError",1,MAX_SUELDO,CANT_REINTENTOS);
			if(retorno == EXIT_SUCCESS)
			{
				retorno = getInt(&bufferSector,"\nIngrese Sector: 1[Compras] - 2[Manufactura] - 3[Ventas]: ",
						"\nError",1,3,CANT_REINTENTOS);
				if(retorno == EXIT_SUCCESS)
				{
					strncpy(employee->name,bufferName,CANT_CARACTERES);
					strncpy(employee->lastName,bufferLastName,CANT_CARACTERES);
					employee->salary=bufferSalary;
					employee->sector=bufferSector;
				}
			}
		}
	}
	return retorno;
}

int imprimirArrayEmployees(Employee *aArray, int cantidad)
{
	int i;
	int retorno = -1;
	char sectorEmpleado[3][25] = {"COMPRAS","MANUFACTURA","VENTAS"};

	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		printf("\n--------------------------------LISTA DE EMPLEADOS--------------------------------\n");
		printf("%6s | %3s | %15s | %15s | %12s | %11s\n","Status","ID","Nombre","Apellido","Salario","Sector");
		for(i=0;i<cantidad;i++)
		{
			printf("%6d | %3d | %15s | %15s | $ %10.2f | %11s\n",
			aArray[i].status,aArray[i].idEmployee,aArray[i].name,aArray[i].lastName,aArray[i].salary,sectorEmpleado[aArray[i].sector-1]);
		}
	}
	return retorno;
}

int imprimirArrayEmployeesStatusOk(Employee *aArray, int cantidad)
{
	int i;
	int retorno = -1;
	char sectorEmpleado[3][25] = {"COMPRAS","MANUFACTURA","VENTAS"};

	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		printf("\n--------------------------------LISTA DE EMPLEADOS--------------------------------\n");
		printf("%3s | %15s | %15s | %12s | %11s\n","ID","Nombre","Apellido","Salario","Sector");
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==1)
			{
			printf("%3d | %15s | %15s | $ %10.2f | %11s\n",
			aArray[i].idEmployee,aArray[i].name,aArray[i].lastName,aArray[i].salary,sectorEmpleado[aArray[i].sector-1]);
			}
		}
	}
	return retorno;
}

int bajaEmployeePorId(Employee *aArray, int cantidad,int id)
{

	int retorno = EXIT_ERROR;
	int posArray;
	if(aArray != NULL && cantidad>0 && id>=0)
	{
		posArray = buscarEmployeePorId(aArray,cantidad,id);
		if(posArray != -1)
		{
			aArray[posArray].status = STATUS_EMPTY;
			retorno = EXIT_SUCCESS;
		}
	}
	return retorno;
}

