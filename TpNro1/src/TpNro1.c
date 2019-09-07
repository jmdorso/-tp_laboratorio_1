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
    int saleBienSuma = 0;
    int saleBienResta = 0;
    int saleBienDiv = 0;
    int saleBienMult = 0;
    int saleBienFactA = 0;
    int saleBienFactB = 0;
    int opcionOperadores;
    int opcionInformar;
    float rdoSuma;
    float rdoResta;
    float rdoMultiplicacion;
    float rdoDivision;
    float rdoFactorialA;
    float rdoFactorialB;
    float num1=0;
    float num2=0;
    char seguir = 's';


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
							 flagA=OK;
						 }
						 printf("\n");
						 break;
				 case 2:
						 if(getFloat(&num2,"\nIngrese 2do Numero: ","\nError.",LONG_MIN,LONG_MAX,CANT_REINTENTOS)==0)
						 {
							 flagB=OK;
						 }
						 printf("\n");
						 break;
				 case 3:
						 if(flagA==0||flagB==0)
						 {
							 printf("\nFalta Ingresar algun numero\n\n");
							 break;
						 }
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
					    		 	 if(sumaAyB(&rdoSuma,"\nError",num1,num2)==0)
					    		 	 {
					    		 		 saleBienSuma = OK;
						    		 	 printf("\n\tFuncion ejecutada. Listar para ver resultados.");
					    		 	 }
									 else
									 {
										 saleBienSuma= EXIT_ERROR;
									 }
					    		 	 break;
					    	 case 2:
					    		 	 if(restaAyB(&rdoResta,"\nError",num1,num2)==0)
					    		 	 {
					    		 		 saleBienResta = OK;
						    		 	 printf("\n\tFuncion ejecutada. Listar para ver resultados.");
					    		 	 }
									 else
									 {
										 saleBienResta= EXIT_ERROR;
									 }
					    		 	 break;
					    	 case 3:
					    		 	 if(divisionAyB(&rdoDivision,"\nError",num1,num2)==0)
									 {
										 saleBienDiv = OK;
						    		 	 printf("\n\tFuncion ejecutada. Listar para ver resultados.");
									 }
									 else
									 {
										 saleBienDiv= EXIT_ERROR;
									 }
					    		 	 break;
					    	 case 4:
									 if(multiplicacionAyB(&rdoMultiplicacion,"\nError",num1,num2)==0)
									 {
										 saleBienMult = OK;
										 printf("\n\tFuncion ejecutada. Listar para ver resultados.");
									 }
									 else
									 {
										 saleBienMult= EXIT_ERROR;
									 }
					    		 	 break;
					    	 case 5:
					    		 	 if(factorialAoB(&rdoFactorialA,"\nError",num1)==0)
					    		 	 {
					    		 		saleBienFactA = OK;
						    		 	printf("\n\tFuncion ejecutada. Listar para ver resultados.");
					    		 	 }
					    		 	 else
					    		 	 {
					    		 		 saleBienFactA = EXIT_ERROR;
					    		 	 }
					    		 	 if(factorialAoB(&rdoFactorialB,"\nError",num2)==0)
					    		 	 {
					    		 		saleBienFactB = OK;
					    		 		printf("\n\tFuncion ejecutada. Listar para ver resultados.");
					    		 	 }
					    		 	 else
					    		 	 {
					    		 		 saleBienFactB=EXIT_ERROR;
					    		 	 }
					    		 	 break;
					    	 case 6:
					    		 	 break;
					    	 }
					     }
					     printf("\n");
					 	 break;
				 case 4:
					 	 if(flagA==0||flagB==0)
					 	 {
					 		 printf("\nFalta Ingresar algun numero\n\n");
					 		 break;
					 	 }
						 printf("\n4.1. Informar Suma(A+B): \n");
						 printf("4.2. Informar Resta(A-B): \n");
						 printf("4.3. Informar Division(A/B): \n");
						 printf("4.4. Informar Multiplicacion(A*B): \n");
						 printf("4.5. Informar el Factorial(A!)\n");
						 printf("4.6. Atras\n\n");
						 if(getInt(&opcionInformar,"\tIngrese opcion: ","\nError.",1,6,CANT_REINTENTOS)==0)
						 {
							 switch(opcionInformar)
							 {
							 case 1:
									 if(saleBienSuma==OK)
									 {
										 printf("\nEl resultado de la suma es: %.2f\n\n",rdoSuma);
									 }
									 else if(saleBienSuma==0)
									 {
										 printf("\nFalta realizar la operacion\n\n");
									 }
									 else
									 {
										 printf("\nHay un error!!!");
									 }
									 break;
							 case 2:
								 	 if(saleBienResta==OK)
									 {
								 		printf("\nEl resultado de la resta es: %.2f\n\n",rdoResta);
									 }
									 else if(saleBienResta==0)
									 {
										 printf("\nFalta realizar la operacion\n\n");
									 }
									 else
									 {
										 printf("\nHay un error!!!");
									 }
								 	 break;
							 case 3:
									 if(saleBienDiv==OK)
									 {
										 printf("\nEl resultado de la division es: %.2f\n\n",rdoDivision);
									 }
									 else if(saleBienDiv==0)
									 {
										 printf("\nFalta realizar la operacion\n\n");
									 }
									 else
									 {
										 printf("\nHay un error!!!");
									 }
									 break;
							 case 4:
									 if(saleBienMult==OK)
									 {
										 printf("\nEl resultado de la multiplicacion es: %.2f\n\n",rdoMultiplicacion);
									 }
									 else if(saleBienMult==0)
									 {
										 printf("\nFalta realizar la operacion\n\n");
									 }
									 else
									 {
										 printf("\nHay un error!!!");
									 }
									 break;
							 case 5:
									 if(saleBienFactA==OK)
									 {
										printf("\nEl Factorial de %.f! tiene como resultado: %.2f\n\n",num1,rdoFactorialA);
									 }
									 else if(saleBienFactA==0)
									 {
										 printf("\nFalta realizar la operacion\n\n");
									 }
									 else
									 {
										 printf("\nHay un error en el A! !!!");
									 }
									 if(saleBienFactB==OK)
									 {
										printf("\nEl Factorial de %.f! tiene como resultado: %.f\n\n",num2,rdoFactorialB);
									 }
									 else if(saleBienFactB==00)
									 {
										 printf("\nFalta realizar la operacion\n\n");
									 }
									 else
									 {
										 printf("\nHay un error en el B! !!!");
									 }
									 break;
							 case 6:
									 break;
							 }
						 }
						 printf("\n");
					 	 break;
				 case 5:
	                    seguir='n';
	                    break;
        	 }
         }
     }while(seguir=='s');
	return EXIT_SUCCESS;
}
