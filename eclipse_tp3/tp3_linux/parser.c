#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = EXIT_ERROR;
	int contVar;
	char id[256];
	char nombre[256];
	char horasTrabajadas[256];
	char sueldo[256];
	int flag=0;
	Employee* empleado;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			contVar = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
			if(flag==0)
			{
				flag=1;
			}
			else if(contVar == 4 && flag == 1)
			{
				printf("%s %s %s %s \n",id,nombre,horasTrabajadas,sueldo);
				empleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				if(empleado != NULL)
				{
					ll_add(pArrayListEmployee,empleado);
					printf("\nCARGA EXITOSA\n");
					retorno = EXIT_SUCCESS;
				}

			}
		}
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
