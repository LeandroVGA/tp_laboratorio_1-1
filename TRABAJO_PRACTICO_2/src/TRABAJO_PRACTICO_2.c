/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utn_input.h"
#include "ArrayEmployees.h"
#include "hardcodDataEmploye.h"


int main(void) {

setbuf(stdout,NULL);

int opcion;
int retorno;

Employee employeeList[QTY_EMPLOYE];
initEmployees(employeeList, QTY_EMPLOYE);
hardcodDatosEmpleado(employeeList, QTY_EMPLOYE_TEST);


  do
    {
      printf ("\n1-Alta\n"
	      "2-Modificacion\n"
	      "3-Baja\n"
	      "4-Informar\n"
	      "5-Salir\n");

      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 5, 3) != -1)
	{
	  switch (opcion)
	    {
	    case 1:
	      printf ("\nALTA\n**********\n");

	      //addEmployee(employeeList, QTY_EMPLOYE, 6, "NICOLAS","LETTICGUGNA",90000,8);

	      if (utn_searchFree(employeeList, QTY_EMPLOYE) == TRUE)
		{

		  if(chargeEmployee (employeeList, QTY_EMPLOYE) != 0)
		    {
		      printf ("\nSE TERMINARON LOS REINTENTOS\n");
		      system ("pause");
		      return EXIT_SUCCESS;
		    }

		}
	    // system ("pause");
	      break;
	    case 2:
	      printf ("\MODIFICACION\n**********\n");
	      updateEmployee (&employeeList, QTY_EMPLOYE);
	      break;
	    case 3:
	      printf ("\nBAJA\n**********\n");
	      prepareForDelete (&employeeList,QTY_EMPLOYE);
	      break;
	    case 4:
	      printf ("\nINFORMAR\n**********\n");
	      sortEmployees(employeeList, QTY_EMPLOYE, 1);
	      printEmployees(employeeList, QTY_EMPLOYE);


	      break;
	    case 5:
	      printf ("\nSALIR\n**********\n");
	      break;
	    default:
	      break;
	    }
	}
      else
	{
	  printf ("\nSE TERMINARON LOS REINTENTOS\n");
	  system ("pause");
	  return EXIT_SUCCESS;
	}
    }
  while (opcion != 5);

	return EXIT_SUCCESS;
}
