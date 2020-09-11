#include <stdio.h>
#include <stdlib.h>




int

getInt (char *mensaje, char *mensajeError, int *pResultado, int reintentos,
	int maximo, int minimo);

int
main (void)
{
  setbuf (stdout, NULL);

//  int operandoA;
//  int operandoB;
  int pOpcion;

  do
    {

      printf ("\nTitulo\n"
	      "***********\n"
	      "1.Ingresar 1er operando (A=x)\n"
	      "2.Ingresar 2do operando (B=y)\n"
	      "3.Calcular todas las operaciones\n"
	      "4.Informar resultados\n"
	      "5.Salir\n\n");

      getInt ("Ingrese opcion: ", "\nOpcion invalida. Por favor ", &pOpcion, 5,
	      5, 1);
      switch (pOpcion)
	{
	case 1:
	  system("cls");
	  printf ("\nOpcion 1 \n");
	  //Ingrese operador A
	  break;
	case 2:
	  printf ("\nOpcion 2 \n");
	  //Ingrese operador B
	  break;
	case 3:
	  printf ("\nOpcion 3 \n");
	  //Funciones de calculo
	  break;
	case 4:
	  printf ("\nOpcion 4 \n");
	  //Funcion de imprimir
	  break;
	default:
	  break;
	}

    }
  while (pOpcion != 5);





  return EXIT_SUCCESS;
}

int
getInt (char *mensaje, char *mensajeError, int *pResultado, int reintentos,
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

