#define EXIT_ERROR -1

int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos);

int getFloat(	float *pResultado,
				char *pMensaje,
				char *pMensajeError,
				float minimo,
				float maximo,
				int reintentos);

int getChar(char *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos);
