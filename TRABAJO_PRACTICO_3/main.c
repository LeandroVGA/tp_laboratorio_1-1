#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn_input.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
  setbuf(stdout,NULL);
    int opcion = 0;
    int fileCahrge = 0;


  LinkedList* listaEmpleados = ll_newLinkedList();




    do{
	printf ("\n*********"
		"\n   MENU   "
	        "\n*********"
	        "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
	        "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
	        "\n3. Alta de empleado"
	        "\n4. Modificar datos de empleado"
	        "\n5. Baja de empleado"
	        "\n6. Listar empleados"
	        "\n7. Ordenar empleados"
	        "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
	        "\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
	       "\n10. Salir\n\n");

	if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 10, 3) != -1)
	  {
	      switch(opcion)
	      {
		  case 1:
		    printf("*****Cargar archivo texto*****");
		      controller_loadFromText("data.csv",listaEmpleados);
		      fileCahrge = 1;
		      break;
		  case 2:
		      printf("\n*****Cargar archivo binario*****");
		      break;
		  case 3:
		      printf("\n*****Alta de Empleado*****");
		      break;
		  case 4:
		      printf("\n*****Modificacion datos de Empleado*****");
		      break;
		  case 5:
		      printf("\n*****Baja de Empleado*****");
		      break;
		  case 6:
		      printf("\n*****Listar Empleados*****");
		      break;
		  case 7:
		      printf("\n*****Ordenar Empleados*****");
		      break;
		  case 8:
		      printf("\n***** Guardar datos de empleados en el archivo data.csv (modo texto)*****");
		      break;
		  case 9:
		      printf("\n***** Guardar datos de empleados en el archivo data.csv (modo binario)*****");
		      break;
		  case 10:
		    printf ("\nEL RPOGRAMA SE CERRO CON EXITO!\n");
		    system ("pause");
		    return EXIT_SUCCESS;
		    break;
		    default:
		    break;
	      }
	  }
    }while(opcion != 10);
    return 0;
}

