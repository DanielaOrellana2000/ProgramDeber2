/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
*	          PROGRAMA PARA MULTIPLICAR UNA MATRIZ				  *
* CARRERA: Ingenieria de Software                                 *
* NOMBRE: Daniela Orellana                                        *
* FECHA DE CREACIÓN: 1/06/2020                                    *
* NRC: 6396                                                       *
******************************************************************/
#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include "conio.h"

void ingreso(int **matriz, int t);
void imprimir(int **matriz, int t);
void proceso(int **matriz1, int **matrizr, int t);
void encerar(int ** matriz,int dimension);
int **incializarMatriz(int dimension);

////////////////////////////////////////////////////////////////////////
// Name:       Ingreso
// Purpose:    Implementacion del metodo Ingreso
// return: 	   void
////////////////////////////////////////////////////////////////////////
void ingreso(int **matriz, int t)
{
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			printf("Ingrese los datos de la posicion [%d][%d]: ",i+1,j+1);
			scanf("%d",&(*(*(matriz+i)+j)));
		}
		
	}
		
}

////////////////////////////////////////////////////////////////////////
// Name:       proceso
// Purpose:    Implementacion dimensionel metodo proceso
// return: 	   void 
// En este metodo se realiza la multiplicacion
////////////////////////////////////////////////////////////////////////
void multiplicacion(int **matriz1, int **matrizr, int t)
{
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			for(int h=0;h<t;h++){
				*(*(matrizr+i)+j)=*(*(matrizr+i)+j)+(*(*(matriz1+i)+h))*(*(*(matriz1+h)+j));
			}

		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       imprimir
// Purpose:    Implementacion del metodo imprimir
// return: 	   void 
////////////////////////////////////////////////////////////////////////
void imprimir(int **matriz, int t)
{
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++)
		{
			printf("%d",*(*(matriz+i)+j));
			printf("%*s",j+5,"");
		}
	printf("\n");
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       imprimir
// Purpose:    Implementacion del metodo imprimir
// return: 	   int**
////////////////////////////////////////////////////////////////////////
int **incializarMatriz(int dimension)
{
    int **m , j;
    m =(int **)malloc(dimension*sizeof(int *));
    for(j=0;j<dimension;j++)
        *(m+j)=(int *)malloc(dimension*sizeof(int));
    return m;
}

////////////////////////////////////////////////////////////////////////
// Name:       encerar
// Purpose:    Implementacion del metodo encerar
// return: 	   void 
////////////////////////////////////////////////////////////////////////
void encerar(int ** matriz,int dimension)
{
    int i, j;
    for(i=0;i<dimension;i++)
        for(j=0;j<dimension;j++)
            *(*(matriz+i)+j)=0;
    return;
}



int main()
{
	int dimension, exp;
	int **matriz1, **matrizr;
	
	printf("\nIngrese la dimension de la matriz: ");
	scanf("%d",&dimension);
	printf("\nIngrese el exponente: ");
	scanf("%d",&exp);
	matriz1=incializarMatriz(dimension);
	matrizr=incializarMatriz(dimension);
	encerar(matrizr,dimension);

	ingreso(matriz1, dimension);
	imprimir(matriz1, dimension);
	printf("\n");
	for(int i=0;i<exp;i++){
		multiplicacion(matriz1,matrizr,dimension);
	}
	
	imprimir(matrizr,dimension);
	system("pause");
   return 0;
}
