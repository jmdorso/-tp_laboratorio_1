/*
 ============================================================================
 Name        : TpNro1.c
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
#include "matematica.h"

#define CANT_REINTENTOS 2

int main(void)
{
    int opcion;
    int flagA=0;
    int flagB=0;
    float rdoSuma;
    float rdoResta;
    float rdoMultiplicaion;
    float rdoDivision;
    float rdoFactorial;
    float num1=0;
    float num2=0;
    char seguir = 's';
   	int opcionOperadores;

    do
     {
    	 printf("---------------------------------------------------------------\n");
         printf("\tTrabajo Practico n1. Calculadora || Juan Martin Dorso\n\n");
         printf("1. Ingrese Primer Numero(A=%.2f): \n",num1);
         printf("2. Ingrese Segundo Numero(B=%.2f): \n",num2);
         printf("3. Calcular Operaciones: \n");
         printf("4. Listar Resultados: \n");
         printf("5. Salir\n\n");

         if(getInt(&opcion,"\tIngrese opcion: ","\nError",1,5,CANT_REINTENTOS)==0)
         {
        	 switch(opcion)
        	 {
				 case 1:
						 if(getFloat(&num1,"\nIngrese 1er Numero: ","\nError.",LONG_MIN,LONG_MAX,CANT_REINTENTOS)==0)
						 {
							 flagA=1;
						 }
						 printf("\n");
						 break;
				 case 2:
						 if(getFloat(&num2,"\nIngrese 2do Numero: ","\nError.",LONG_MIN,LONG_MAX,CANT_REINTENTOS)==0)
						 {
							 flagB=1;
						 }
						 printf("\n");
						 break;
				 case 3:
					 	 printf("\n3.1. Suma(A+B): \n");
					     printf("3.2. Resta(A-B): \n");
					     printf("3.3. Division(A/B): \n");
					     printf("3.4. Multiplicacion(A*B): \n");
					     printf("3.5. Calcular el Factorial(A!)\n");
					 	 printf("3.6. Atras\n\n");
					     if(getInt(&opcionOperadores,"\tIngrese opcion: ","\nError.",1,6,CANT_REINTENTOS)==0)
					     {
					    	 switch(opcionOperadores)
					    	 {
					    	 case 1:
					    		 	 if(flagA==0||flagB==0)
					    		     {
					    		 		 printf("\nFalta Ingresar algun numero\n\n");
					    		     }
					    		 	 else
					    		 	 {
					    		 		 sumaAyB(&rdoSuma,"\nError",num1,num2);
					    		 		 printf("\nEl resultado de la suma es: %.2f\n\n",rdoSuma);
					    		 	 }
					    	 case 2:
					    		 	 break;
					    	 case 3:
					    		 	 break;
					    	 case 4:
					    		 	 break;
					    	 case 5:
					    		 	 break;
					    	 case 6:
					    		 	 break;
					    	 }
					     }
					     printf("\n");
					 	 break;
				 case 4:
					 	 break;
				 case 5:
	                    seguir='n';
	                    break;
        	 }
         }
     }while(seguir=='s');
	return EXIT_SUCCESS;
}
