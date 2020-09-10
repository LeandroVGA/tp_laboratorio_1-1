#include <stdio.h>
#include <stdlib.h>

int menu (int *opcion, char *titulo, char *opciones,int cantidadOpciones);
int getInt (char *mensaje, char *mensajeError, int *pResultado, int reintentos,
	int maximo, int minimo);

int
main (void)
{
  setbuf (stdout, NULL);


int pMenu;
int resultado;



resultado = menu (&pMenu,
	"Titulo\n"
	"***********\n",
	"1.Ingresar 1er operando (A=x)\n"
	"2.Ingresar 2do operando (B=y)\n"
	"3.Calcular todas las operaciones\n"
	"4.Informar resultados\n"
	"5.Salir\n",
	5);

if(resultado != -1){

printf("La opcion ingresada es %d", pMenu);
}else{

    system("cls");
    printf("Se terminaron los reinentos");
}








  return EXIT_SUCCESS;
}








int getInt (char *mensaje, char *mensajeError, int *pResultado, int reintentos,
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


int menu (int *opcion,char *titulo, char *opciones,int cantidadOpciones)
{

  int retorno = -1;

  if (titulo != NULL && opciones != NULL)
    {
      printf ("%s\n", titulo);
      printf ("%s\n", opciones);
      retorno =  getInt ("Ingrese opcion: ","\nOpcion invalida. Por favor ",
      			opcion, 10, cantidadOpciones, 1);
      if (retorno == 0)
	{
	  retorno = *opcion;
	}
    }

  return retorno;
}

