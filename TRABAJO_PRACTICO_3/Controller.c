#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_input.h"
#include "Controller.h"
#include <string.h>
#define LEN_AUX 128

static int idMaximoEncontrado(LinkedList* pArrayListEmployee, int* idMaximo);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pArch;
	if(path != NULL && pArrayListEmployee != NULL)
	{

		pArch = fopen(path, "rw");
		if(pArch != NULL && parser_EmployeeFromText(pArch,pArrayListEmployee)==0)
		{
			printf("El archivo se cargo exitosamente\n");
			retorno = 0;
			fclose(pArch);
		}
		else

			printf("El archivo no puede abrirse\n");
	}
	return retorno;
}







/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pArch;
	if(path != NULL && pArrayListEmployee != NULL)
	{

		pArch = fopen(path, "rb");
		if(pArch != NULL && parser_EmployeeFromBinary(pArch,pArrayListEmployee)==0)
		{
			printf("El archivo se cargo con exito\n");
			retorno = 0;
			fclose(pArch);
		}
		else

			printf("El archivo no puede abrirse\n");
	}

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* pAuxiliarEmpleado;
	char auxNombre[LEN_AUX];
	int auxHsTrabajadas;
	int sueldo;
	int idAux;

	if(pArrayListEmployee != NULL)
	{
		if(!(utn_getNombre(auxNombre, LEN_AUX,"Ingrese nombre: \n", "Valor incorrecto\n",2)) &&
		   !(utn_getNumero(&auxHsTrabajadas,"Ingrese horas trabajadas: \n", "Valor incorrecto\n",1, 1000,2)) &&
		   !(utn_getNumero(&sueldo,"Ingrese sueldo: \n", "Valor incorrecto\n",1, 1000000,2)))
		{
			if(ll_len(pArrayListEmployee) == 0)
			{
				idAux = 0;
			}
			else
			{
				idMaximoEncontrado(pArrayListEmployee, &idAux);
				idAux = idAux + 1;
			}
			if(employee_newParametros(idAux,auxNombre,auxHsTrabajadas,sueldo) >= 0)
			{

				ll_add(pArrayListEmployee,pAuxiliarEmpleado);

				retorno = 0;
				printf("Empleado creado correctamente en la ubicación %d\n", idAux);
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}


/**
 * \brief Busca un empleado por ID
 * \param pArrayListEmployee LinkedList* Puntero a la lista que será evaluada
 * \return int Devuelve la ubicacion donde se encuentra el ID(OK), (-1)ERROR, (-2)ID NO ENCONTRADO
 */

static int idMaximoEncontrado(LinkedList* pArrayListEmployee, int* idMaximo)
{
	int retorno = -1;
	int i;
	int flag = 0;
	int idAuxMaximo;
	int idAuxiliar;
	Employee* auxiliarEmployee;
	Employee* auxEmplo;

	if(pArrayListEmployee != NULL && idMaximo != NULL)
	{
		retorno=0;
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmplo = ll_get(pArrayListEmployee,i);
			employee_getId(auxEmplo,&idAuxiliar);
			if(!flag)
			{
				auxiliarEmployee = ll_get(pArrayListEmployee,i);
				employee_getId(auxiliarEmployee,&idAuxMaximo);
				flag = 1;
			}
			else if(idAuxiliar > idAuxMaximo)
			{
				idAuxMaximo = idAuxiliar;
			}

		}
		*idMaximo = idAuxMaximo;

	}
	return retorno;
}
