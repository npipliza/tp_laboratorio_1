
#include "validaciones_TP2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/** \brief Validates that a string has only numbers
 *
 * \param number The string to validate
 * \return 1 in case the string is only numbers and 0 if it's not
 *
 */
static int validatePositiveInteger(char number[]);

/** \brief Validates that a string has only numbers and one '.'
 *
 * \param numberFloat The string to validate
 * \return 1 in case the string is only numbers or number and one '.' and 0 if it's not
 *
 */
static int validatePositiveFloat(char numberFloat[]);

/** \brief Validates that a string has only letters
 *
 * \param string The string to validate
 * \return 1 in case the string is only letters and 0 if it's not
 *
 */
static int isOnlyLetters(char string[]);

/** \brief Validates that a string has only letters and numbers
 *
 * \param string The string to validate
 * \return 1 in case the string is only letters and numbers and 0 if it's not
 *
 */
static int isNumberAndLetters(char string[]);


int getIntNew(char message[],char errorMessage[])
{
    char strNumber[32];
    int number;

    puts(message);
    fflush(stdin);
    fgets(strNumber,sizeof(strNumber),stdin);
    strNumber[strlen(strNumber)-1]='\0';

    while(!validatePositiveInteger(strNumber))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(strNumber,sizeof(strNumber),stdin);
        strNumber[strlen(strNumber)-1]='\0';
    }

    number=atoi(strNumber);

    return number;
}

int ValidarNumero(float caracteres[],char message[],char errorMessage[])
{
    int i;
    int tienePunto = 0;
    char strFloat[32];

    puts(message);
    fflush(stdin);
    fgets(strFloat,sizeof(strFloat),stdin);

    for (i = 0; i < strlen(caracteres); i++)
    {
        if (caracteres[i] == '.')
            tienePunto++;

        if ((!isdigit(caracteres[i]) && caracteres[i] != '.') || tienePunto > 1)
        {
            puts(errorMessage);
            fflush(stdin);
            //printf("\nError. Ingrese solo numeros:\n");
            return 0;
        }
    }
    return 1;
}


float getFloatNew(float strF[],char message[],char errorMessage[])
{
    char strFloat[32];
    float number;

    puts(message);
    fflush(stdin);
    fgets(strFloat,sizeof(strFloat),stdin);
    strFloat[strlen(strFloat)-1]='\0';

    while(!validatePositiveFloat(strFloat))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(strFloat,sizeof(strFloat),stdin);
        strFloat[strlen(strFloat)-1]='\0';
    }

    number=atof(strFloat);

    return number;

}

static int validatePositiveInteger(char number[])
{
    int returnValue=1;

    for(int i=0;number[i]!='\0';i++)
    {
        if(number[i]<'0'||number[i]>'9')
        {
            returnValue=0;
            break;
        }
    }

    return returnValue;
}

static int validatePositiveFloat(char numberFloat[])
{
    int returnValue=1;
    int pointCounter=0;

    for(int i=0;numberFloat[i]!='\0';i++)
    {
        if(numberFloat[i]<'0'||numberFloat[i]>'9')
        {
            if(numberFloat[i]=='.'&&pointCounter==0)
            {
                pointCounter++;
            }else
            {
                returnValue=0;
                break;
            }
        }
    }

    return returnValue;
}

void getString(char string[],int len,char message[],char errorMessage[])
{
    puts(message);
    fflush(stdin);
    fgets(string,len,stdin);
    string[strlen(string)-1]='\0';

    while(!isOnlyLetters(string))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(string,len,stdin);
        string[strlen(string)-1]='\0';
    }
}

static int isOnlyLetters(char string[])
{
    int returnValue=1;

    for(int i=0;string[i]!='\0';i++)
    {
        if((string[i]<'a'||string[i]>'z')&&(string[i]<'A'||string[i]>'Z'))
        {
            returnValue=0;
        }
    }

    return returnValue;
}

char getChar(char message[],char errorMessage[])
{
    char aux;

    puts(message);
    fflush(stdin);
    scanf("%c",&aux);

    while((aux<'a'||aux>'z')&&(aux<'A'||aux>'Z'))
    {
        puts(errorMessage);
        fflush(stdin);
        scanf("%c",&aux);
    }

    return aux;
}

char getCharTwoOptions(char message[],char errorMessage[],char option1,char option2)
{
    char aux;

    puts(message);
    fflush(stdin);
    scanf("%c",&aux);
    aux=tolower(aux);//lo paso a toLower para no tener que pasarlo en el main

    while(aux!=option1&&aux!=option2)
    {
        puts(errorMessage);
        fflush(stdin);
        scanf("%c",&aux);
        aux=tolower(aux);
    }

    return aux;
}

static int isNumberAndLetters(char string[])
{
    int returnValue=1;

    for(int i=0;string[i]!='\0';i++)
    {
        if((string[i]<'a'||string[i]>'z')&&(string[i]<'A'||string[i]>'Z')&&(string[i]<'0'||string[i]>'9'))
        {
            returnValue=0;
        }
    }

    return returnValue;
}

void getStringWithNumbers(char string[],int len,char message[],char errorMessage[])
{
    puts(message);
    fflush(stdin);
    fgets(string,len,stdin);
    string[strlen(string)-1]='\0';

    while(!isNumberAndLetters(string))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(string,len,stdin);
        string[strlen(string)-1]='\0';
    }
}


//////////////////////utn


static int myGets(char* cadena, int len);
static int esNumericaFloat(char* cadena, int len);
static int getInt(int *pResultado);
static int getFloat(float *pResultado);
static int getFloat(float *pResultado);
/*
 * \brief valida que la cadena recibida no excede la memoria del array y hace obligatoria la entrada de datos.
 * \param puntero con el string validado.
 * \param longitud del string.
 * \return 0 si ha salido ok. -1 si no.
 */
static int myGets(char* cadena, int len)
{
	int retorno = -1;
	char buffer[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(cadena !=NULL && len>0 &&
            (fgets(buffer, sizeof(buffer), stdin) != NULL) &&
            buffer[0] !='\n')
		{
			if(buffer[strnlen(buffer, sizeof(buffer))-1] == '\n')
			{
				(buffer[strnlen(buffer, sizeof(buffer))-1] = '\0');
			}

			if(strnlen(buffer, sizeof(buffer)) <= len)
			{
				strncpy(cadena, buffer, len);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int esNumericaInt(char* cadena, int len)
{
	int retorno=1;

	for(int i=0; i<len && cadena[i]!='\0'; i++)
	{
		if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
		{
			continue;
		}
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno=0;
				break;
		}
	}
	return retorno;
}

/*
 * \brief valida que la cadena recibida es un número flotante.
 * \param puntero con el string validado.
 * \param longitud del string.
 * \return 1 (verdadero) si es un número entero. 0 (falso) si no lo es.
 */

static int esNumericaFloat(char* cadena, int len)
{
	int retorno=1;
	int contadorPuntos = 0;

	for(int i = 0; i<len && cadena[i]!='\0'; i++)
	{
		if(cadena[i]=='.')
		{
			contadorPuntos++;
		}
		if((i==0 && (cadena[i]=='+' || cadena[i]=='-')) || (i>0 && cadena[i]=='.'))
		{
			continue;
		}
		if(contadorPuntos>1 || cadena[i]>'9' || cadena[i]<'0')
		{
			retorno=0;
				break;
		}
	}
	return retorno;
}



int esNombreValido(char* cadena, int len)
{
	int retorno = 1;

	if( cadena!= NULL && len > 0)
	{
		for(int i=0; i<=len && cadena[i] != '\0';i++)
		{
			if(	(cadena[i] < 'A' || cadena[i] > 'Z') &&
				(cadena[i] < 'a' || cadena[i] > 'z') &&
				cadena[i] != ' ' && cadena[i] != '-')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*
 * \brief convierte la cadena recibida en un número entero con la función atoi.
 * \param puntero con el string validado.
 * \return 0 si ha salido ok. -1 si no.
 */

static int getInt(int *pResultado)
{
	int retorno=-1;
	char buffer[50];
	if(pResultado != NULL &&
			myGets(buffer, sizeof(buffer))==0 &&
			esNumericaInt(buffer, sizeof(buffer))==1)
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}
	return retorno;
}
/*
 * \brief convierte la cadena recibida en un número flotante con la función atof.
 * \param puntero con el string validado.
 * \return 0 si ha salido ok. -1 si no.
 */



static int getFloat(float *pResultado)
{
	int retorno=-1;
	char buffer[50];
	if(pResultado != NULL &&
		myGets(buffer, sizeof(buffer))==0 &&
		esNumericaFloat(buffer, sizeof(buffer))==1)
	{
		retorno=0;
		*pResultado=atof(buffer);
	}
	return retorno;
}



int utn_getNumeroInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)

{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL &&
        mensajeError != NULL && minimo <= maximo &&
		reintentos > 0)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			if(getInt(&buffer) == 0 &&
                buffer >= minimo &&
                buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}
/*
 * \brief solicita un número flotante por pantalla y lo valida.
 * \param puntero con el número.
 * \param mensaje para solicitar el número flotante..
 * \param mensaje de error si no cumple las condiciones preestablecidas.
 * \param cifra mínima que se puede introducir.
 * \param cifra máxima que se puede introducir.
 * \param cantidad de reintentos para introducir un valor válido.
 * \return return 0 si ha salido ok. -1 si no (punteros nulos, mínimo mayor al máximo, reintentos menor a 0)
 */

int utn_getCadena(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos)
{

	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && len>0 && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		do{
			printf("%s",mensaje);

			if(myGets(buffer,sizeof(buffer))==0 && strlen(buffer) < len)
			{
				strncpy(pResultado,buffer,len-1);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/*
 * \brief solicita un número flotante por pantalla y lo valida.
 * \param puntero con el número.
 * \param mensaje para solicitar el número flotante..
 * \param mensaje de error si no cumple las condiciones preestablecidas.
 * \param cifra mínima que se puede introducir.
 * \param cifra máxima que se puede introducir.
 * \param cantidad de reintentos para introducir un valor válido.
 * \return return 0 si ha salido ok. -1 si no (punteros nulos, mínimo mayor al máximo, reintentos menor a 0)
 */
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			if(getFloat(&buffer) == 0 &&
					buffer >= minimo &&
					buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}


int validarFecha(int dia,int mes, int anio)
{
    int retorno=1;
    if(dia <1 || dia >31 || mes<1 || mes >12 || anio <1990 || anio >2020 )
    {
        system("cls");
        printf("\n\nERROR EN EL INGRESO DE DATOS DE LA FECHA\n");
        printf("- Ingrese dias entre 1 y 31\n\n");
        printf("- Ingresar mes entre 1 y 12\n");
        printf("- Ingresar año entre 1990 y 2020\n\n");
        printf("PROCURE DIGITAR CORRECTAMENTE");
    }
     else
    {
        retorno = 0;
    }
    return retorno;
}
