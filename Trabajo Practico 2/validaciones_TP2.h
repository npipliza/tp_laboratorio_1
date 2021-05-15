#ifndef VALIDACIONES_TP2_H_
#define VALIDACIONES_TP2_H_
#ifndef VALIDACIONES_TP2_H_INCLUDED
#define VALIDACIONES_TP2_H_INCLUDED

/** \brief Asks for a number and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a non validated number
 * \return The number validated
 *
 */
int getIntNew(char message[],char errorMessage[]);


int ValidarNumero(float caracteres[],char message[],char errorMessage[]);

/** \brief Asks for a float and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a non validated float number
 * \return The float number validated
 *
 */
float getFloatNew(char message[],char errorMessage[]);

/** \brief Asks for a string and returns it validated
 *
 * \param str The string to write on
  * \param message Message for the user
 * \param errorMessage A message in case the user enters a string that isn't only letters
 *
 */
void getString(char str[],int len,char message[],char errorMessage[]);

/** \brief Asks for a character,validates it and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a character that isn't a letter
  * \return The character validated
 *
 */
char getChar(char message[],char errorMessage[]);

/** \brief Asks the user to choose an option between two characters, validates it's one of the options and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a character that isn't one of the options
 * \return  The character validated
 *
 */
char getCharTwoOptions(char message[],char errorMessage[],char option1,char option2);


/** \brief Asks for a string and returns it validated
 *
 * \param str The string to write on
 * \param len The length of the string
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a string that isn't only letters and/or numbers
 *
 */
void getStringWithNumbers(char string[],int len,char message[],char errorMessage[]);

/*
 * \brief pide un número entero
 * \param puntero para guardar el número entero
 * \param mensaje del menu para pedir el numero
 * \param mensaje de error si no es valido
 * \param  numero minimo aceptado
 * \param  numero maximo aceptado
 * \param cantidad de reintentos

 * \return 0 si ha salido ok. -1 si no lo logro
 */
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/*
 * \brief solicita una cadena de caracteres.
 * \param puntero con la cadena.
 * \param mensaje para pedir la cadena..
 * \param mensaje de error si no es valida.
 * \param cantidad de reintentos para introducir un valor válido.
 * \return 0 si ha salido ok. -1 si no.
 */
int utn_getCadena(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos);
/*
 * \brief Valida que la cadena recibida sea un nombre valido
 * \param puntero con el string validado.
 * \param longitud del string.
 * \return 1 (verdadero) si solo tiene letras y espacios. 0 (falso) si no.
 */
int esNombreValido(char* string, int len);

/*
 * \brief valida que la cadena recibida es un número entero valido
 * \param puntero del string validado.
 * \param longitud del string.
 * \return 1 (verdadero) si es un número entero. 0 (falso) si no lo es.
 */

int esNumericaInt(char* cadena, int len);

int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

int validarFecha(int dia,int mes, int anio);


#endif // VALIDACIONES_H_INCLUDED
#endif /* VALIDACIONES_H_ */
