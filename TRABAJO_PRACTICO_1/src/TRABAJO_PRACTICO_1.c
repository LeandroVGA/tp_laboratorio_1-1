/*
 * Alumno: Nicolas Letticugna
 * Comision: 1F
 * Turno: Noche
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int
main (void)
{
  setbuf (stdout, NULL);

  int pOpcion;
  int salidaDivision;
  int salidaFActorialA;
  int salidaFActorialB;
  int flagA = 0;
  int flagB = 0;
  float operandoA;
  float operandoB;
  float resultadoResta;
  float resultadoSuma;
  float resultadoMultiplicar;
  float resultadoDivision;
  float resultadoFactorialA;
  float resultadoFactorialB;

  do
    {

      printf ("\nTitulo\n"
	      "***********\n"
	      "1.Ingresar 1er operando (A=x)\n"
	      "2.Ingresar 2do operando (B=y)\n"
	      "3.Calcular todas las operaciones\n"
	      "4.Informar resultados\n"
	      "5.Salir\n\n");

	  if(flagA == 1)
	{
          printf("Operador A: %.2f\n", operandoA);
	}
            if(flagB == 1)
	{
	  printf("Operador B: %.2f\n\n", operandoB);
	}

      utn_getInt ("Ingrese opcion: ", "\nOpcion invalida. Por favor ", &pOpcion, 5,
	      5, 1);
      switch (pOpcion)
	{
	case 1:
	  utn_getFloat("Ingresar el primer operando A: ", "\nNumero invalido. Por favor ", &operandoA, 5,1000000, -1000000);
	  flagA = 1;
	  break;
	case 2:
	  utn_getFloat("Ingresar el primer operando B: ", "\nNumero invalido. Por favor ", &operandoB, 5,1000000, -1000000);
	  flagB = 1;
	  break;
	case 3:
	 printf("\nCalcular todas las operaciones\n""******************************\n");
	 utn_suma(operandoA, operandoB, &resultadoSuma);
	 utn_resta(operandoA, operandoB, &resultadoResta);
	 utn_multiplicacion(operandoA, operandoB, &resultadoMultiplicar);
	 salidaDivision = utn_division(operandoA, operandoB, &resultadoDivision);
	 salidaFActorialA = utn_factorialF(operandoA, &resultadoFactorialA);
	 salidaFActorialB = utn_factorialF(operandoB, &resultadoFactorialB);
	 printf ("\nLOS CALCULOS SE REALIZARON EXITOSAMENTE!\n");
	 system ("pause");

	  break;
	case 4:
	  printf("\nInformar resultados\n""******************\n");
	  printf ("\nEl resultado de A+B es: %.2f\n", resultadoSuma);
	  printf ("\nEl resultado de A-B es: %.2f\n", resultadoResta);
	  printf ("\nEl resultado de A*B es: %.2f\n", resultadoMultiplicar);
	  if (salidaDivision != -1)
	    {
	      printf ("\nEl resultado de A/B es: %.2f\n", resultadoDivision);
	    }
	  else
	    {
	      printf ("\nNo es posible dividir por cero");
	    }
	  mensajeFactorial(salidaFActorialA, &resultadoFactorialA, "El factorial de A es: ");
	  mensajeFactorial(salidaFActorialB, &resultadoFactorialB, "El factorial de B es: ");
	  flagA = 0;
	  flagB = 0;
	  break;
	default:
	  break;
	}

    }
  while (pOpcion != 5);

  return EXIT_SUCCESS;
}



