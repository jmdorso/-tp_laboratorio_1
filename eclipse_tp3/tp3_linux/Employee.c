#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

static int isValidId(int *id);
static int isValidIdString(char *id);
static int isValidNombre(char *nombre);
static int isValidHorasTrabajadas(int *horasTrabajadas);
static int isValidHorasTrabajadasString(char *horasTrabajadas);
static int isValidSueldo(int *sueldo);
static int isValidSueldoString(char *sueldo);



Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

void employee_delete(Employee *this)
{
	free(this);
}

Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
	Employee *retorno = NULL;
	Employee *this;
	this = employee_new();

	if(this != NULL)
	{
		if(		employee_setNombre(this,nombre) == EXIT_SUCCESS &&
				employee_setHorasTrabajadasString(this,horasTrabajadas) == EXIT_SUCCESS &&
				employee_setSueldoString(this,sueldo) == EXIT_SUCCESS &&
				employee_setIdString(this,id) == EXIT_SUCCESS )
		{
				retorno = this;
		}
		else
		{
			employee_delete(this);
		}
	}

	return retorno;
}

int employee_setId(Employee* this,int id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidId(&id))
	{
		this->id=id;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && id != NULL)
	{
		*id=this->id;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidId(int *id)
{
	int retorno = EXIT_ERROR;

	if(id != NULL)
	{
		if(id > 0)
		{
			retorno = EXIT_SUCCESS;
		}
	}
	return retorno;
}

int employee_setIdString(Employee *this,char *id)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidIdString(id))
	{
		this->id=atoi(id);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidIdString(char *id)
{
	int retorno = EXIT_ERROR;

	if(id != NULL)
	{
		//if(esSoloNumerosPositivos(id,"\nERROR"))
		//{
			retorno = EXIT_SUCCESS;
		//}
	}

	return retorno;
}

int employee_setNombre(Employee *this,char *nombre)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_getNombre(Employee *this,char *nombre)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidNombre(char *nombre)
{
	int retorno = EXIT_ERROR;

	if(nombre != NULL)
	{
		//esNombreOApellido(nombre,"\nERROR");
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidHorasTrabajadas(&horasTrabajadas))
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidHorasTrabajadas(int *horasTrabajadas)
{
	int retorno = EXIT_ERROR;

	if(horasTrabajadas != NULL)
	{
		if(horasTrabajadas >= 0)
		{
			retorno = EXIT_SUCCESS;
		}
	}
	return retorno;
}

int employee_setHorasTrabajadasString(Employee *this,char *horasTrabajadas)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidHorasTrabajadasString(horasTrabajadas))
	{
		this->horasTrabajadas=atoi(horasTrabajadas);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidHorasTrabajadasString(char *horasTrabajadas)
{
	int retorno = EXIT_ERROR;

	if(horasTrabajadas != NULL)
	{
		//if(esSoloNumerosPositivos(horasTrabajadas,"\nERROR"))
		//{
			retorno = EXIT_SUCCESS;
			//}
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidSueldo(&sueldo))
	{
		this->sueldo=sueldo;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo=this->sueldo;
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidSueldo(int *sueldo)
{
	int retorno = EXIT_ERROR;

	if(sueldo != NULL)
	{
		if(sueldo > 0)
		{
			retorno = EXIT_SUCCESS;
		}
	}
	return retorno;
}

int employee_setSueldoString(Employee *this,char *sueldo)
{
	int retorno = EXIT_ERROR;

	if(this != NULL && isValidSueldoString(sueldo))
	{
		this->sueldo=atoi(sueldo);
		retorno = EXIT_SUCCESS;
	}

	return retorno;
}

static int isValidSueldoString(char *sueldo)
{
	int retorno = EXIT_ERROR;

	if(sueldo != NULL)
	{
		//	if(esSoloNumerosFlotantes(sueldo,"\nERROR"))
		//{
			retorno = EXIT_SUCCESS;
			//}
	}

	return retorno;
}
