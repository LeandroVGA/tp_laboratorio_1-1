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
#include <windows.h>
#include "utn_input.h"
#include "ArrayEmployees.h"
#include "hardcodDataEmploye.h"



int main(void) {
setbuf(stdout,NULL);
int opcion;

Employee employeeList[QTY_EMPLOYE];
initEmployees(employeeList, QTY_EMPLOYE);
//hardcodDatosEmpleado(employeeList, QTY_EMPLOYE_TEST);

  do
    {
      printf ("\n*********"
	      "\n* MENU  *"
	      "\n*********"
	      "\n1-Alta\n"
	      "2-Modificacion\n"
	      "3-Baja\n"
	      "4-Informar\n"
	      "5-Salir\n\n");


      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 5, 3) != -1)
	{
	  switch (opcion)
	    {
	    case 1:

	      if (flagLimite (employeeList, QTY_EMPLOYE) != -1)
		{
		  if (utn_searchFree (employeeList, QTY_EMPLOYE) == TRUE)
		    {
		      printf ("\nALTA\n**********\n");
		      if (chargeEmployee (employeeList, QTY_EMPLOYE) != 0)
			{
			  printf ("\n*****************************\n");
			  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
			  printf ("\n*****************************\n");
			}
		    }
		}
	      else
		{
		  printf ("\n*******************************************\n");
		  printf ("\nLA CANTIDAD DE EMPLEADOS LLEGO A SU LIMITE!\n");
		  printf ("\n*******************************************\n");
		}

	      break;
	    case 2:
	      if (flagLimite (employeeList, QTY_EMPLOYE) != 0)
		{
	      printf ("\MODIFICACION\n**********\n");
	      updateEmployee (&employeeList, QTY_EMPLOYE);
		}
	      else
		{
		  printf ("\n*****************************************\n");
		  printf ("\nNO HAY EMPLEADOS CARGADOS PARA MODIFICAR!\n");
		  printf ("\n*****************************************\n");

		}

	      break;
	    case 3:
	      if (flagLimite (employeeList, QTY_EMPLOYE) != 0)
	      	{
	      printf ("\nBAJA\n**********\n");
	      prepareForDelete (&employeeList,QTY_EMPLOYE);
	      	}
	      else
	      		{
		  printf ("\n****************************************\n");
		  printf ("\nNO HAY EMPLEADOS CARGADOS PARA ELIMINAR!\n");
		  printf ("\n****************************************\n");
	      		}
	      break;
	    case 4:
	      if (flagLimite (employeeList, QTY_EMPLOYE) != 0)
	        {
	      printf ("\nINFORMAR\n**********\n");
	      sortEmployees(employeeList, QTY_EMPLOYE, 1);
	      headerEmployee();
	      printEmployees(employeeList, QTY_EMPLOYE);
	      printf ("\n*****************************************************\n");
	      printf ("TOTAL DE LOS SALARIOS: ");
	      printf ("%.2f",sumaTotal(employeeList, QTY_EMPLOYE));
	      printf ("\nPROMEDIO DE LOS SALARIOS: ");
	      printf ("%.2f",promedio(employeeList, QTY_EMPLOYE));
      	      printf ("\nCANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO: ");
	      printf ("%d",cantidadSuperiorAlPronedio(employeeList, QTY_EMPLOYE));
	      printf ("\n*****************************************************\n");
	     	}
	      else
			{
		  printf ("\n***************************************\n");
		  printf ("\nNO HAY EMPLEADOS CARGADOS PARA MOSTRAR!\n");
		  printf ("\n***************************************\n");
			}
	      break;
	    case 5:
	      printf("\nEL RPOGRAMA SE CERRO CON EXITO!\n");
	      system ("pause");
	      return EXIT_SUCCESS;
	      break;
	    default:
	      break;
	    }
	}
      else
	{
	  printf ("\n*****************************\n");
	  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
	  printf ("\n*****************************\n");

	  //return EXIT_SUCCESS;
	}
    }
  while (opcion != 5);

	return EXIT_SUCCESS;
}
