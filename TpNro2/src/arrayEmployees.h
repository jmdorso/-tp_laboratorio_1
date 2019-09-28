/*
 * arrayEmployees.h
 *
 *  Created on: Sep 27, 2019
 *      Author: mati
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define CANT_CARACTERES 51
#define CANT_REINTENTOS 2
#define CANT_EMPLEADOS 1000
#define MAX_SUELDO 1000000

typedef struct
{
	int idEmployee;
	int status;
	//***************
	char name[51];
	char lastName[51];
	float salary;
	int sector;

}Employee;

static int generarId(void);

int initLugarLibreEmployees(Employee *aArray, int cantidad);
int altaEmployeePorId(Employee *aArray, int cantidad,Employee employee);
int buscarLugarLibreEmployee(Employee *aArray, int cantidad);
int buscarEmployeePorId(Employee *aArray, int cantidad,int id);
int altaUnSoloEmployee(Employee *employee);
int imprimirArrayEmployees(Employee *aArray, int cantidad);
int imprimirArrayEmployeesStatusOk(Employee *aArray, int cantidad);
int bajaEmployeePorId(Employee *aArray, int cantidad,int id);
int ordenarArrayEmployees(Employee *aArray, int cantidad);


#endif /* ARRAYEMPLOYEES_H_ */
