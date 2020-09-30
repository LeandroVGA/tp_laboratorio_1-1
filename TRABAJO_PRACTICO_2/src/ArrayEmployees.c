/*
 * ArrayEmployees.c
 *
 *  Created on: 25 sep. 2020
 *      Author: nico
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn_input.h"


int initEmployees(Employee list[], int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
		    list[i].isEmpty = TRUE;
		    list[i].id = 0;
		    strcpy(list[i].name, "");
		    strcpy(list[i].lastName,"");
		    list[i].salary = 0.00;
		    list[i].sector = 0;
		}
		retorno = 0;
	}
	return retorno;
}




int printEmployees(Employee* list, int length)
{
	int retorno = -1;
	if(list != NULL && length > 0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("%-6d %-6d %-12s %-13s %-12.2f %d \n"
				    ,list[i].isEmpty
				    ,list[i].id
				    ,list[i].name
				    ,list[i].lastName
				    ,list[i].salary
				    ,list[i].sector);
			}
		}
		retorno = 0;
	}
	return retorno;
}


void headerEmployee(void)
{
    printf("%*s%*s%*s%*s%*s",
	   -7, " ID",
	   -13," NOMBRE",
	   -14," APELLIDO",
	   -12," SALARIO",
	    0," SECTOR"
	   "\n-----------------------------------------------------\n");
}



int utn_searchFree (Employee *list, int len)
{
  int i;
  int retorno = FALSE;

  if (list != NULL && list > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (isEmpty (list, len, i) == 1)
	    {
	      retorno = TRUE;
	      break;
	    }
	}
    }
  return retorno;
}


int isEmpty(Employee* list, int limit, int index)
{
  int retorno = FALSE;
  if (list != NULL && list > 0 && index < list)
    {
      if (list[index].isEmpty == TRUE)
	{
	  retorno = TRUE;
	}
    }
  return retorno;
}


static int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector)
{
  int i;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (isEmpty (list, len, i) == 1)
	    {
	      list[i].id = id;
	      strcpy (list[i].name, name);
	      strcpy (list[i].lastName, lastName);
	      list[i].salary = salary;
	      list[i].sector = sector;
	      list[i].isEmpty = FALSE;
	      return 0;
	    }
	}
    }
  return -1;
}


int idIncremental(void)
{
    static int id = 0;
    id++;
    return id;
}





int chargeEmployee (Employee *list, int len)
{
  Employee auxEmployee;

  if (list != NULL && len > 0)
    {
      if (utn_getNombre ("Ingrese nombre del empleado: ",  "\nError al ingresar.\n", &auxEmployee.name, LONG_NAME_EMPLOYE, 5) != 0)
	{
	  return -1;
	}
     if (utn_getNombre ("Ingrese apellido del empleado: ", "\nError al ingresar.\n", &auxEmployee.lastName, LONG_NAME_EMPLOYE, 5) != 0)
	{
	  return -1;
	}
      if (utn_getNumeroFloat (&auxEmployee.salary, "Ingrese salario del empleado: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
	{
	  return -1;
	}
      if (utn_getNumero ("Ingrese el sector: ", "\nError al ingresar. Por favor ", &auxEmployee.sector, 0, 100, 5)!= 0)
	{
	  return -1;
	}

      switch (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n'))
	{
	case -1:
	  return -1;
	  break;

	case 1:
	  auxEmployee.id = idIncremental ();
	  addEmployee (list, len, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);
	  return 0;
	  break;

	case 0:
	  return 0;
	  break;

	default:
	  break;
	}
    }

  return -1;
}




int findEmployeeById (Employee *list, int len, int id)
{
  int i;
  int retorno = -1;

  if (list != NULL && len > 0 && id != 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == id)
	    {
	      retorno = id;
	      break;
	    }
	}

    }
return retorno;
}

int printForId  (Employee *list, int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{
  	    headerEmployee();
  		for( i=0;i<len;i++)
  		{
  			if(list[i].id == id && list[i].isEmpty == FALSE && list[i].sector != FALSE )
  			{
  				printf("%-6d %-6d %-12s %-13s %-12.2f %d \n"
  				    ,list[i].isEmpty
  				    ,list[i].id
  				    ,list[i].name
  				    ,list[i].lastName
  				    ,list[i].salary
  				    ,list[i].sector);
  			}
  		}
  		retorno = 0;
  	}
 return retorno;
}




int arrayToBuffer(Employee *list,Employee *listBuffer, int len, int id)
{
 // Employee buffer;
  int retorno = -1;
    int i;
    	if(list != NULL && len > 0)
    	{
    	      for( i=0;i<len;i++)
    		{
    			//if(list[i].id == id && list[i].isEmpty == FALSE && list[i].sector != FALSE)
    			if(list[i].id == id)
    			{
    			*listBuffer=list[i];

    			}
    		}
    		retorno = 0;
    	}
return retorno;
}


int bufferToArray(Employee *list, Employee *listBuffer, int len, int id)
{
  int i;
  int retorno = -1;
  if (list != NULL && listBuffer != NULL && len > 0)
    {

	for (i = 0; i < len; i++)
	  {
	    if (list[i].id == id)
	      {
		list[i] = *listBuffer;
		retorno = 0;
	      }
	  }
    }
  return retorno;
}




int updateEmployee (Employee *list, int len)
{
  int bufferID;
  int retorno = -1;
  int opcion;
  Employee auxEmployee;



  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del empleado: ", "\nError al ingresar. ", &bufferID, 1, QTY_EMPLOYE, 5);
      printf ("\nEl ID seleccionado es: %d\n", bufferID);
      if (findEmployeeById (list, len, bufferID) != -1)
	{
	  retorno = 0;
	/*  for(i=0; i<len; i++)
	    {
	      if(list[i].isEmpty==FALSE && list[i].id==bufferID )
		{
		  auxEmployee=list[i];
		}
	  }
*/
	  arrayToBuffer(list, &auxEmployee,  len,  bufferID);
	  do
	     {
	      printForId  (&auxEmployee,len,  bufferID);
	      printf ("\n1-Nombre\n"
		      "2-Apellido\n"
	      	      "3-Salario\n"
	      	      "4-Sector\n"
	      	      "5-Aceptar Cambios\n"
	      	      "6-Salir\n");

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 6, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	    case 1:
	 	      printf ("\NOMBRE\n******\n");

	 	     if (utn_getNombre ("Ingrese nombre del empleado: ",  "\nError al ingresar.\n", &auxEmployee.name, LONG_NAME_EMPLOYE, 5) != 0)
	 	    	{
	 	    	  return -1;
	 	    	}
	 	      break;
	 	    case 2:
	 	      printf ("\APELLIDO\n********\n");
	 	     if (utn_getNombre ("Ingrese apellido del empleado: ", "\nError al ingresar.\n", &auxEmployee.lastName, LONG_NAME_EMPLOYE, 5) != 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	    case 3:
	 	      printf ("\SALARIO\n**********\n");
	 	     if (utn_getNumeroFloat (&auxEmployee.salary, "Ingrese salario del empleado: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
	 	     	{
	 	     	  return -1;
	 	     	}
	 	      break;
	 	    case 4:
	 	      printf ("\SECTOR\n**********\n");
	 	     if (utn_getNumero ("Ingrese el sector: ", "\nError al ingresar. Por favor ", &auxEmployee.sector, 1, 100, 5)!= 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	   case 5:
	 		  printf ("\Grabar cambios\n**********\n");
	 		 switch (utn_getAceptaRechaza ("\nGrabar cambios? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n'))
	 			{
	 			case -1:
	 			  return -1;
	 			  break;

	 			case 1:
	 			  //  addEmployee (list, len, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);
	 			 bufferToArray (list, &auxEmployee,  len, bufferID);
	 			/* for(i=0; i<len; i++)
	 				    {
	 				      if(auxEmployee.id==bufferID && list[i].id==bufferID)
	 					{
	 					 list[i]= auxEmployee;
	 					}
	 				  }*/
	 			  return 0;
	 			  break;

	 			case 0:
	 			  return 0;
	 			  break;

	 			default:
	 			  break;
	 			}
	 	      break;
	 	    case 6:
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
	   while (opcion != 6);

	  if(opcion == 6)
	    {
	      return EXIT_SUCCESS;
	    }
	}//FINAL DEL IF findEmployeeById
      else
	{
	  printf ("\nEl ID NO existe\n");
	}
    }//FINAL DEL IF VALIDACION DE NULL PRINCIPAL
  return retorno;
}


int removeEmployee(Employee* list, int len, int id)
{
  int i;
  int retorno;

  if (list != NULL && len > 0 && id > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == id)
	    {
	      list[i].isEmpty = TRUE;
	      retorno = 0;
	    }
	}
    }
 return retorno;
}


int prepareForDelete (Employee *list, int len)
{
  int retorno = -1;
  int bufferID;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del empleado: ", "\nError al ingresar. ", &bufferID, 1, QTY_EMPLOYE, 5);
      if (findEmployeeById (list, len, bufferID) != -1)
	{
	  printForId (list, len, bufferID);
	  retorno = utn_getAceptaRechaza ("\nAcepta eliminar empleado? s/n: ", "ERROR al ingresar opcion. \n", 's','n');
	  if (retorno == 1)
	    {
	      removeEmployee (list, len, bufferID);
	      retorno = 1;
	    }
	}
    }
  return retorno;
}


/*
int sortEmployees(Employee* list, int len, int order)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  Employee buffer;
  int nuevoLimite;

  if (list != NULL && len >= 0)
    {
      nuevoLimite = len - 1;
      do
	{
	  flagSwap = 0;
	  for (i = 0; i < nuevoLimite; i++)//for(i=0; i<tam-1; i++)
	    {
			  contador++;
			//  if (miArray[i] < miArray[i + 1])
			 if(strcmp(list[i].name,list[i+1].name)==order)
			{
			  flagSwap = 1;
			  buffer = list[i];
			  list[i] = list[i + 1];
			  list[i + 1] = buffer;
			}
	    }
	  nuevoLimite--;
	}
      while (flagSwap);
      retorno = contador;
    }
  return retorno;
}
*/

int sortEmployees(Employee* list, int len, int order)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  Employee buffer;
  int nuevoLimite;

  if (list != NULL && len >= 0)
    {
      nuevoLimite = len - 1;
      do
	{
	  flagSwap = 0;
	  ///////////////////////////////////////////////////////////
	  for (i = 0; i < nuevoLimite; i++) //for(i=0; i<tam-1; i++)
	    {
	      contador++;
	      //  if (miArray[i] < miArray[i + 1])
	      if (strcmp (list[i].lastName, list[i + 1].lastName) < order)
		{
		  flagSwap = 1;
		  buffer = list[i];
		  list[i] = list[i + 1];
		  list[i + 1] = buffer;
		}
	      else
		{
		  if (strcmp (list[i].lastName, list[i + 1].lastName) == 0)
		    {
		      if (list[i].sector > list[i + 1].sector)
			{
			  flagSwap = 1;
			  buffer = list[i];
			  list[i] = list[i + 1];
			  list[i + 1] = buffer;
			}
		    }
		}
	    }///////////////////////////////////////////////////////////
	  nuevoLimite--;
	}
      while (flagSwap);
      retorno = contador;
    }
  return retorno;
}




float sumaTotal (Employee *list, int len)
{
  int i;
  float retorno = -1;
  float aux = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE && list[i].salary != FALSE)
	    {
	      aux = aux + list[i].salary;
	    }
	}
      retorno = aux;
    }
  return retorno;
}



float promedio(Employee* list, int len)
{
  int i;
  float retorno = -1;
  int contador = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE && list[i].salary != FALSE)
	    {
	      contador++;
	    }
	}
      retorno = sumaTotal (list, len) / contador;
    }
  return retorno;
}


int cantidadSuperiorAlPronedio(Employee* list, int len)
{

  int i;
  int retorno = -1;
  int contador = 0;
  float aux;

  aux = promedio (list, len);
  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE && list[i].salary > aux)
	    {
	      contador++;
	    }
	}
      retorno = contador;
    }
  return retorno;
}







