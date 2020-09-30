/*
 * ArrayEmployees.h
 *
 *  Created on: 25 sep. 2020
 *      Author: nico
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define TRUE 1
#define FALSE 0
#define LONG_NAME_EMPLOYE 51
#define QTY_EMPLOYE 1000
#define MAX_EMPLOYE 100

struct
{
int id;
char name[LONG_NAME_EMPLOYE];
char lastName[LONG_NAME_EMPLOYE];
float salary;
int sector;
int isEmpty;
}typedef Employee;



int initEmployees(Employee* list, int len);
int printEmployees(Employee* list, int length);
void headerEmployee(void);
int idIncremental(void);
static int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector);
int chargeEmployee (Employee* list, int len);
int utn_searchFree (Employee* list, int len);
int findEmployeeById (Employee *list, int len, int id);
int updateEmployee (Employee *list, int len);
int  bufferToArray (Employee *list, Employee *auxEmployee, int len, int id);
int printForId  (Employee *list, int len, int id);
int arrayToBuffer(Employee *list,Employee *listBuffer, int len, int id);
void printForId2  (Employee  auxEmployee);
int prepareForDelete (Employee *list, int len);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
float sumaTotal(Employee* list, int len);
float promedio(Employee* list, int len);
int cantidadSuperiorAlPronedio(Employee* list, int len);
/*
int alumno_alta(Alumno arrayAlumnos[],int limite,int indice);
int alumno_imprimir(Alumno* pArrayAlumnos, int limite);
int alumno_initArray(Alumno* pArrayAlumnos, int limite);
int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice);
int isEmpty(Alumno* pArray, int limit, int index);
int idIncremental(void);
*/



#endif /* ARRAYEMPLOYEES_H_ */
