/*
 * ****************************************************************************************
 * Alumno: Nicolas Letticugna
 * Comision: 1F
 * Turno: Noche
 * ****************************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * utn_getFloat : Pide al usuario un numero
 * pNumero: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * min: valor minimo valido (inclusive)
 * max: valor maximo valido (inclusive)
 * reintentos: cantidad de ingresos fallidos
 * mensaje: El mensaje que imprime para pedir un valor
 * mensajeError: mensaje que imprime si el rango no es valido
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */

int utn_getFloat(char *mensaje, char *mensajeError, float *pResultado, int reintentos,int max, int min)
{

  int retorno = -1;
  float bufferFloat;
  int resultadoScanf;

  if (mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && max >= min)
    {
      do
	{
	  printf ("%s", mensaje);
	  fflush (stdin);
	  resultadoScanf = scanf ("%f", &bufferFloat);
	  if (resultadoScanf == 1 && bufferFloat >= min && bufferFloat <= max)
	    {
	      retorno = 0;
	      *pResultado = bufferFloat;
	      break;
	    }
	  else
	    {
	      printf ("%s", mensajeError);
	      reintentos--;
	    }
	}
      while (reintentos >= 0);
    }
  return retorno;
}




/*
 * utn_getInt : Pide al usuario un numero
 * pNumero: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * min: valor minimo valido (inclusive)
 * max: valor maximo valido (inclusive)
 * reintentos: cantidad de ingresos fallidos
 * mensaje: El mensaje que imprime para pedir un valor
 * mensajeError: mensaje que imprime si el rango no es valido
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_getInt (char *mensaje, char *mensajeError, int *pResultado, int reintentos,
	int maximo, int minimo)
{
  int retorno = -1;
  int bufferInt;
  int resultadoScanf;
  if (mensaje != NULL && mensajeError != NULL && pResultado != NULL
      && reintentos >= 0 && maximo >= minimo)
    {
      do
	{
	  printf ("%s", mensaje);
	  fflush (stdin);
	  resultadoScanf = scanf ("%d", &bufferInt);
	  if (resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
	    {
	      retorno = 0;
	      *pResultado = bufferInt;
	      break;
	    }
	  else
	    {
	      printf ("%s", mensajeError);
	      reintentos--;
	    }
	}
      while (reintentos >= 0);
    }
  return retorno;
}




/*
 * utn_factorialF : Ingresa por referencia variable "pNumero"  y por valor "numero". Procesa si es negativo y decimal
 * pNumero: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * numero: Se ingresa por valor
 * Retorno: 0: si esta todo OK. 1: Si es  decimal y negativo. -1: Si es negativo. -2: Si es decimal
 */
int utn_factorialF (float numero, float *pNumero)
{
  int entero;
  int constante = 1;
  int contador;
  int retorno;

  entero = numero;
  if(numero - entero && numero<0)
          {
              return 1;
          }
      else if (numero < 0)
          {
              return -1;
          }
      else if(numero - entero)
          {
              return -2;
          }
      else
          {
	  for (contador = 1; contador <= numero; contador++)
	 	{
	 	  constante = constante * contador;
	 	}
	       *pNumero = constante;
	       retorno = 0;
          }
  return retorno;
}



/*
 * mensajeFactorial : Ingresa por referencia variable "factorial",  por valor "salidaFactorail" y el mensaje que imprime segun valor
 * de la variable de salidaFactorail
 * factorial: Direccion de memoria de la variable donde escribe el valor
 * salidaFactorail: Se ingresa  valor
 * mensaje: El mensaje que imprime imprime segun valor de la variable de salidaFactorail
 * Retorno: -
 */
void mensajeFactorial(int salidaFactorail,float *factorial, char *mensaje)
{

  switch (salidaFactorail) {
    case 1:
      printf("\n%s No se puede calcular factorial con numeros decimales y negativos.\n", mensaje);
      break;
    case -1:
      printf("\n%sNo se puede calcular factorial con numeros negativos\n", mensaje);
      break;
    case -2:
      printf("\n%sNo se puede calcular factorial con numeros decimales.\n", mensaje);
      break;
    default:
      printf("\n%s %.f \n", mensaje, *factorial);
      break;
  }
}


/*
 * utn_suma : Ingresa por valor  operandoA, operandoB y se suman, el resultado se escribe  en la direccion de memoria de la variable pNumero
 * operandoA: Se ingresa por valor
 * operandoB: Se ingresa por valor
 * pNumero: Direccion de memoria de la variable
 * Retorno: -
 */
void utn_suma(float operandoA, float operandoB, float *pNumero){
  int resultado;

    resultado = operandoA + operandoB;
  if(resultado == -0)
      {
	resultado = resultado + 0;
      }
    *pNumero = resultado;
}




/*
 * utn_resta : Ingresa por valor  operandoA, operandoB y se restan, el resultado se escribe  en la direccion de memoria de la variable pNumero
 * operandoA: Se ingresa por valor
 * operandoB: Se ingresa por valor
 * pNumero: Direccion de memoria de la variable
 * Retorno: -
 */
void utn_resta(float operandoA, float operandoB, float *pNumero){
  *pNumero = operandoA - operandoB;
}


/*
 * utn_multiplicacion : Ingresa por valor  operandoA, operandoB y se multiplican, el resultado se escribe  en la direccion de memoria de la variable pNumero
 * operandoA: Se ingresa por valor
 * operandoB: Se ingresa por valor
 * pNumero: Direccion de memoria de la variable
 * Retorno: -
 */
void utn_multiplicacion(float operandoA, float operandoB, float *pNumero){
  float resultado;

    resultado = operandoA * operandoB;

    if(resultado == -0)
      {
	resultado = resultado + 0;
      }
    *pNumero = resultado;
}


/*
 * utn_multiplicacion : Ingresa por valor  operandoA, operandoB y se dividen, el resultado se escribe  en la direccion de memoria de la variable pNumero
 * operandoA: Se ingresa por valor
 * operandoB: Se ingresa por valor
 * pNumero: Direccion de memoria de la variable
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */
int utn_division(float operandoA, float operandoB, float *pNumero){
int retorno = -1;

  if(operandoB != 0)
    {
      *pNumero = operandoA / operandoB;
      retorno = 0;
    }
return retorno;
}

