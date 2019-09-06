#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"
#include "matematica.h"

/** \brief Suma los valores ingresados
 * \param *pResultado apunta a la direccion de memoria donde se va a alojar el resultado de la operacion
 * \param *pMensajeError muestra un mensaje en caso de no poder realizarse la operacion
 * \param num1 es el primer numero a sumar
 * \param num2 es el segundo numero a sumar
 * \return el resultado de la suma.
 *
 */

int sumaAyB(float *pResultado,char *pMensajeError, float num1,float num2)
{
	int retorno = EXIT_ERROR;
	double buffer;

	if(pResultado != NULL)
	{
		buffer=num1+num2;
		if(buffer < LONG_MAX && buffer > LONG_MIN)
		{
			*pResultado=(float)buffer;
			retorno=EXIT_SUCCESS;
		}
		else
		{
			printf("%s",pMensajeError);
		}
	}
	else if(pResultado == NULL)
	{
		printf("%s",pMensajeError);
	}

	return retorno;
}
