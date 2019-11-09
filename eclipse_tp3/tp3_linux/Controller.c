#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"

#define CRITERIO_ASCENDENTE 1
#define CRITERIO_DESCENDENTE 0

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = EXIT_ERROR;

	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		if(ll_len(pArrayListEmployee) == 0)
		{
			if(parser_EmployeeFromText(pFile,pArrayListEmployee)==EXIT_SUCCESS)
			{
				printf("\nCarga Exitosa. Tamaño linkedList %d\n",ll_len(pArrayListEmployee));
				retorno=EXIT_SUCCESS;
			}
			else
			{
				printf("\nNo se pudo cargar el archivo.\n");
			}
		}
		else
		{
			printf("\nLa Lista ya se encuentra cargada.\n");
		}
	}

	fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = EXIT_ERROR;
	int id;
	char nombre[1000];
	int horasTrabajadas;
	int sueldo;
	Employee* this;

	if(pArrayListEmployee != NULL)
	{
		id=buscarUltimoIdGenerandoSiguiente(pArrayListEmployee);
		getString(nombre,"\nIngrese Nombre: ","\nError",1,CANT_CARACTERES,CANT_REINTENTOS);
		retorno = esNombreOApellido(nombre,"No es un nombre valido");
		if(retorno==EXIT_SUCCESS)
		{
			if(getValidIntFromString(&horasTrabajadas,"\nIngrese Cant. Horas Trabajadas: ","\nError",1,CANT_HORAS,CANT_REINTENTOS)==EXIT_SUCCESS)
			{
				if(getValidIntFromString(&sueldo,"\nIngrese Sueldo: ","\nError",1,CANT_SUELDO,CANT_REINTENTOS)==EXIT_SUCCESS)
				{
					this = employee_new();
					if(this != NULL)
					{
						employee_setId(this,id);
						employee_setNombre(this,nombre);
						employee_setHorasTrabajadas(this,horasTrabajadas);
						employee_setSueldo(this,sueldo);
						ll_add(pArrayListEmployee,this);
						retorno = EXIT_SUCCESS;
					}
					else
					{
						employee_delete(this);
						printf("\nNo fue posible agregar empleado\n");
					}
				}
			}
		}

	}

    return retorno;
}

/** \brief Busca el ultimo ID y genera el siguiente
 *
 * \param pArrayListEmployee LinkedList*
 * \return int EXIT_ERROR (-1) si el llist es NULL o el siguiente ID a utilizar
 *
 */

int buscarUltimoIdGenerandoSiguiente(LinkedList* pArrayListEmployee)
{
	int retorno = EXIT_ERROR;
	int i;
	int ultId = 0;
	Employee* this;

	if(pArrayListEmployee != NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			this = ll_get(pArrayListEmployee,i);
			if(this->id > ultId)
			{
				ultId=this->id;
			}
		}
		retorno = ultId+1;
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = EXIT_ERROR;
	int opcion;
	int id;
	int horasTrabajadas;
	int sueldo;
	char nombre[1000];
	char confirmarModif;
	Employee* this;

	if(pArrayListEmployee!=NULL)
	{
		getValidIntFromString(&id,"\nIngrese ID a modificar: ","\nError",1,buscarUltimoIdGenerandoSiguiente(pArrayListEmployee)-1,CANT_REINTENTOS);
		this = employee_buscaPorId(pArrayListEmployee,id);
		if(this != NULL)
		{
			printf("Quiere Modificar el siguiente empleado: \n");
			printf("\nID: %d\n",this->id);
			printf("Nombre: %s\n",this->nombre);
			printf("Horas Trabajadas: %d\n",this->horasTrabajadas);
			printf("Sueldo: %d\n",this->sueldo);
			getChar(&confirmarModif,
			"\nSeguro desea Modificar? Ingrese s (o cualquier tecla para continuar sin modificar): ",
			"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
			'a',
			'z',
			CANT_REINTENTOS);
			if(confirmarModif == 's')
			{
				if(getInt(&opcion, "\n\nQue desea modificar: [1]Nombre [2]HorasTrabajadas [3]Sueldo: ", "\nError", 1, 3,CANT_REINTENTOS) == 0)
				{
					switch(opcion)
					{
					case 1:
						getString(nombre,"\nIngrese Nombre: ","\nError",1,CANT_CARACTERES,CANT_REINTENTOS);
						retorno = esNombreOApellido(nombre,"No es un nombre valido");
						if(retorno==EXIT_SUCCESS)
						{
							employee_setNombre(this,nombre);
							printf("\n\nModificacion Realizada con Exito\n\n");
						}
						break;
					case 2:
						if(getValidIntFromString(&horasTrabajadas,"\nIngrese Cant. Horas Trabajadas: ","\nError",1,CANT_HORAS,CANT_REINTENTOS)==EXIT_SUCCESS)
						{
							employee_setHorasTrabajadas(this,horasTrabajadas);
							printf("\n\nModificacion Realizada con Exito\n\n");
						}
						break;
					case 3:
						if(getValidIntFromString(&sueldo,"\nIngrese Sueldo: ","\nError",1,CANT_SUELDO,CANT_REINTENTOS)==EXIT_SUCCESS)
						{
							employee_setSueldo(this,sueldo);
							printf("\n\nModificacion Realizada con Exito\n\n");
						}
						break;
					}
				}
			}
			else
			{
				printf("\n\nMODIFICACION CANCELADA\n\n");
			}
		}
		else
		{
			printf("\nNo hay datos en el empleado\n\n");
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = EXIT_ERROR;
	int id;
	int indice;
	char confirmarBaja;
	Employee* this;

	if(pArrayListEmployee!=NULL)
	{
		getValidIntFromString(&id,"\nIngrese ID a dar de baja: ","\nError",1,buscarUltimoIdGenerandoSiguiente(pArrayListEmployee)-1,CANT_REINTENTOS);
		this = employee_buscaPorId(pArrayListEmployee,id);
		if(this != NULL)
		{
			printf("Quiere Modificar el siguiente empleado: \n");
			printf("\nID: %d\n",this->id);
			printf("Nombre: %s\n",this->nombre);
			printf("Horas Trabajadas: %d\n",this->horasTrabajadas);
			printf("Sueldo: %d\n",this->sueldo);
			getChar(&confirmarBaja,
			"\nSeguro desea dar de Baja? Ingrese s (o cualquier tecla para continuar sin eliminar): ",
			"\nERROR. Verifique si ingreso una letra y/o desactive mayuscula\n",
			'a',
			'z',
			CANT_REINTENTOS);
			if(confirmarBaja == 's')
			{
				indice = ll_indexOf(pArrayListEmployee,this);
				ll_remove(pArrayListEmployee,indice);
				retorno = EXIT_SUCCESS;
				printf("\n\nBaja exitosa\n\n");
			}
			else
			{
				printf("\n\nBAJA CANCELADA\n\n");
			}
		}
		else
		{
			printf("\nNo hay datos en el empleado\n\n");
		}
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	Employee* aux;

	if(pArrayListEmployee!=NULL)
	{
		printf("\n%4s %15s %20s %10s\n","ID","NOMBRE","HORAS TRABAJADAS","SUELDO");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			aux = ll_get(pArrayListEmployee,i);
			printf("%4d %15s %17d Hs %8d $\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
		}
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = EXIT_ERROR;
	int opcion;
	int criterio;

	if(pArrayListEmployee != NULL)
	{
		if(getInt(&opcion, "\n\nComo desea ordenar: [1]Id [2]Nombre [3]HorasTrabajadas [4]Sueldo: ", "\nError", 1, 4,CANT_REINTENTOS) == 0)
		{
			switch(opcion)
			{
			case 1:
				getInt(&criterio, "\n\nComo desea ordenar: [0]Descendente [1]Ascendente: ", "\nError", CRITERIO_DESCENDENTE, CRITERIO_ASCENDENTE,CANT_REINTENTOS);
				if(criterio == CRITERIO_ASCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListEmployee,employee_ordenoPorId,CRITERIO_ASCENDENTE);
					printf("\nProceso Terminado\n");
				}
				if(criterio == CRITERIO_DESCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListEmployee,employee_ordenoPorId,CRITERIO_DESCENDENTE);
					printf("\nProceso Terminado\n");
				}
				break;
			case 2:
				getInt(&criterio, "\n\nComo desea ordenar: [0]Descendente [1]Ascendente: ", "\nError", CRITERIO_DESCENDENTE, CRITERIO_ASCENDENTE,CANT_REINTENTOS);
				if(criterio == CRITERIO_ASCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListEmployee,employee_ordenoPorNombre,CRITERIO_ASCENDENTE);
					printf("\nProceso Terminado\n");
				}
				if(criterio == CRITERIO_DESCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListEmployee,employee_ordenoPorNombre,CRITERIO_DESCENDENTE);
					printf("\nProceso Terminado\n");
				}
				break;
			case 3:
				getInt(&criterio, "\n\nComo desea ordenar: [0]Descendente [1]Ascendente: ", "\nError", CRITERIO_DESCENDENTE, CRITERIO_ASCENDENTE,CANT_REINTENTOS);
				if(criterio == CRITERIO_ASCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListEmployee,employee_ordenoPorHorasTrabajadas,CRITERIO_ASCENDENTE);
					printf("\nProceso Terminado\n");
				}
				if(criterio == CRITERIO_DESCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListEmployee,employee_ordenoPorHorasTrabajadas,CRITERIO_DESCENDENTE);
					printf("\nProceso Terminado\n");
				}
				break;
			case 4:
				getInt(&criterio, "\n\nComo desea ordenar: [0]Descendente [1]Ascendente: ", "\nError", CRITERIO_DESCENDENTE, CRITERIO_ASCENDENTE,CANT_REINTENTOS);
				if(criterio == CRITERIO_ASCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListEmployee,employee_ordenoPorSueldo,CRITERIO_ASCENDENTE);
					printf("\nProceso Terminado\n");
				}
				if(criterio == CRITERIO_DESCENDENTE)
				{
					printf("\nEl proceso puede demorar unos segundos...\n");
					ll_sort(pArrayListEmployee,employee_ordenoPorSueldo,CRITERIO_DESCENDENTE);
					printf("\nProceso Terminado\n");
				}
				break;
			retorno = EXIT_SUCCESS;
			}
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = EXIT_ERROR;
	int i;
	Employee* this;
	FILE* pFile = NULL;

	pFile = fopen(path,"w");
	if(pFile != NULL && pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0)
	{
		fprintf(pFile,"Id,Nombre,Horas Trabajadas,Sueldo\n");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			this = ll_get(pArrayListEmployee,i);
			if(this != NULL)
			{
				fprintf(pFile,"%d,%s,%d,%d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
			}
		}
		printf("\nEl archivo se guardo correctamente\n");
		retorno=EXIT_SUCCESS;
	}
	fclose(pFile);


    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

