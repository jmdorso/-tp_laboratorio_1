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

/** \brief le damos de alta a un empleado a traves de interaccion con el usuario
 * \param *employee una variable del tipo Employee
 * \return -1 si hay algun error o 0 si esta bien
 *
 */

int altaUnSoloEmployeePorUI(Employee *employee)
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

/** \brief imprime el array completo sin exepciones de campos
 * \param *aArray es el array de empleados
 * \param cantidad es la cantidad de elementos del array
 * \return -1 si hay algun error o 0 si esta bien
 *
 */

int imprimirArrayEmployees(Employee *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	char sectorEmpleado[3][25] = {"Compras","Manufactura","Ventas"};

	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		printf("\n--------------------------------LISTA DE EMPLEADOS--------------------------------\n");
		printf("%6s | %3s | %15s | %15s | %12s | %11s\n","STATUS","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
		for(i=0;i<cantidad;i++)
		{
			printf("%6d | %3d | %15s | %15s | $ %10.2f | %11s\n",
			aArray[i].status,aArray[i].idEmployee,aArray[i].name,aArray[i].lastName,aArray[i].salary,sectorEmpleado[aArray[i].sector-1]);
		}
	}
	return retorno;
}

/** \brief imprime elementos del array con el campo stado NOT EMPTY(es decir elementos cargados)
 * \param *aArray es el array de empleados
 * \param cantidad es la cantidad de elementos del array
 * \return -1 si hay algun error o 0 si esta bien
 *
 */

int imprimirArrayEmployeesStatusOk(Employee *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	char sectorEmpleado[3][25] = {"Compras","Manufactura","Ventas"};

	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		printf("\n--------------------------------LISTA DE EMPLEADOS--------------------------------\n");
		printf("%3s | %15s | %15s | %12s | %11s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
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

/** \brief busca un empleado por ID y lo da de baja mediante el campo status (dejandolo EMPTY)
 * \param *aArray es el array de empleados
 * \param cantidad es la cantidad de elementos del array
 * \param id es el ID a buscar
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

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

/** \brief ordena el array de empleados primero por apellido y luego por sector
 * \param *aArray es el array de empleados
 * \param cantidad es la cantidad de elementos del array
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */


int ordenarArrayEmployeesPorApellidoYSector(Employee *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	Employee buffer;
	int fSwap;

	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aArray[i].lastName,aArray[i+1].lastName,CANT_CARACTERES)>0 && aArray[i].status == STATUS_NOT_EMPTY)
				{
					fSwap = 1;
					buffer = aArray[i];
					aArray[i]=aArray[i+1];
					aArray[i+1]=buffer;
				}
				else if(strncmp(aArray[i].lastName,aArray[i+1].lastName,CANT_CARACTERES)==0 && aArray[i].status == STATUS_NOT_EMPTY)
				{
					if(aArray[i].sector > aArray[i+1].sector && aArray[i].status == STATUS_NOT_EMPTY)
						{
						fSwap = 1;
						buffer = aArray[i];
						aArray[i]=aArray[i+1];
						aArray[i+1]=buffer;
					}
				}
			}
		}while(fSwap==1);
	}
	return retorno;
}

/** \brief busca un empleado por ID y te da la opcion de modificar algunos campos
 * \param *aArray es el array de empleados
 * \param cantidad es la cantidad de elementos del array
 * \param id es el ID a buscar
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

int modificaEmployeePorId(Employee *aArray,int cantidad,int id)
{

	int retorno = EXIT_ERROR;
	int posArray;
	int opcion;
	char bufferName[CANT_CARACTERES];
	char bufferLastName[CANT_CARACTERES];
	float bufferSalary;
	int bufferSector;
	Employee auxEmployee;

	if(aArray != NULL && cantidad>0 && id>=0)
	{
		posArray = buscarEmployeePorId(aArray,cantidad,id);
		if(posArray != -1)
		{
			auxEmployee = aArray[posArray];
			getInt(&opcion,"\nQue desea modificar: [1]Nombre [2]Apellido [3]Salario [4]Sector\n",
					"\nError!",1,4,CANT_REINTENTOS);
			switch(opcion)
			{
			case 1:
				getString(bufferName,"\nIngrese Nombre: ","\nError",1,CANT_CARACTERES,CANT_REINTENTOS);
				retorno = esNombreOApellido(bufferName,"No es un nombre valido");
				if(retorno == EXIT_SUCCESS)
				{
					strncpy(auxEmployee.name,bufferName,CANT_CARACTERES);
				}
				break;
			case 2:
				getString(bufferLastName,"\nIngrese Apellido: ","\nError",1,CANT_CARACTERES,CANT_REINTENTOS);
				retorno = esNombreOApellido(bufferLastName,"No es un Apellido valido");
				if(retorno == EXIT_SUCCESS)
				{
					strncpy(auxEmployee.lastName,bufferLastName,CANT_CARACTERES);
				}
				break;
			case 3:
				retorno = getFloat(&bufferSalary,"\nIngrese Salario: ","\nError",1,MAX_SUELDO,CANT_REINTENTOS);
				if(retorno == EXIT_SUCCESS)
				{
					auxEmployee.salary=bufferSalary;
				}
				break;
			case 4:
				retorno = getInt(&bufferSector,"\nIngrese Sector: 1[Compras] - 2[Manufactura] - 3[Ventas]: ",
						"\nError",1,3,CANT_REINTENTOS);
				if(retorno == EXIT_SUCCESS)
				{
					auxEmployee.sector=bufferSector;
				}
				break;
			}
			aArray[posArray]=auxEmployee;
		}
	}
	return retorno;
}

/** \brief hace calculos con el campo salario del array
 * \param *aArray es el array de empleados
 * \param cantidad es la cantidad de elementos del array
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

int calculosConSalarios(Employee *aArray, int cantidad)
{
	int i;
	int retorno = EXIT_ERROR;
	float acumSalary = 0;
	float acumEmp = 0;
	float promedio;

	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY)
			{
				acumSalary = acumSalary + aArray[i].salary;
				acumEmp=acumEmp+1;
			}
		}
		promedio = acumSalary/acumEmp;
		printf("\n\nEl TOTAL de los salarios es: $%.2f\nEl PROMEDIO de los salarios es: $%.2f\n\n",acumSalary,promedio);
		imprimirArrayEmployeesPromedioSalario(aArray,cantidad,promedio);

	}
	return retorno;
}

/** \brief imprime el array con los elementos cargados y con el salario mayor o igual al promedio
 * \param *aArray es el array de empleados
 * \param cantidad es la cantidad de elementos del array
 * \param promedio es la variable donde esta calculado el promedio de los salarios
 * \return -1 si hay algun error o 0 si esta bien.
 *
 */

int imprimirArrayEmployeesPromedioSalario(Employee *aArray, int cantidad,float promedio)
{
	int i;
	int cantEmp = 0;
	int retorno = EXIT_ERROR;
	char sectorEmpleado[3][25] = {"Compras","Manufactura","Ventas"};

	if(aArray != NULL && cantidad>0)
	{
		retorno = EXIT_SUCCESS;
		printf("\n-----------------------EMPLEADOS QUE SUPERAN EL PROMEDIO--------------------------\n");
		printf("%3s | %15s | %15s | %12s | %11s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status==1 && aArray[i].salary >= promedio)
			{
			cantEmp++;
			printf("%3d | %15s | %15s | $ %10.2f | %11s\n",
			aArray[i].idEmployee,aArray[i].name,aArray[i].lastName,aArray[i].salary,sectorEmpleado[aArray[i].sector-1]);
			}
		}
		printf("\nCANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO: %d\n\n",cantEmp);
	}
	return retorno;
}
