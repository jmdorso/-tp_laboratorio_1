#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define CANT_CARACTERES 128

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setIdString(Employee *this,char *id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setHorasTrabajadasString(Employee *this,char *horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_setSueldoString(Employee *this,char *sueldo);


#endif // employee_H_INCLUDED
