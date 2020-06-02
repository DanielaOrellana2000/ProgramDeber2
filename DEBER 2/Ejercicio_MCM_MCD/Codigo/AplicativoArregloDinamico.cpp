/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
*					PROGRAMA MCM Y MCD							  *
* CARRERA: Ingenieria de Software                                 *
* NOMBRE: Daniela Orellana                                        *
* FECHA DE CREACIÓN: 1/06/2020                                    *
* NRC: 6396                                                       *
******************************************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Valores
// Purpose:    Implementacion de la clase Valores
// Atributos: vector, nElementos 
// Metodos: pedirDatos, incializar, encerar, ingresarValores, calcularMinComMul
//			calcularMxComDiv
////////////////////////////////////////////////////////////////////////
class Valores{
	private: 
		int *vector;
		int nElementos;
	public: 
		int pedirDatos();
		int* incializar(int);
		int* encerar(int, int*);
		int* ingresarValores(int, int*);
		void calcularMinComMul(int*, int);
		void calcularMaxComDiv(int*, int);
};

////////////////////////////////////////////////////////////////////////
// Name:       Valores::pedirDatos()
// Purpose:    Implementacion de Valores::pedirDatos()
// Return:     int
////////////////////////////////////////////////////////////////////////
int Valores::pedirDatos(){
	Valores val;
	cout<<"Ingrese el numero de elementos: ";
	cin>>nElementos;
	return nElementos;
}

////////////////////////////////////////////////////////////////////////
// Name:       Valores::incializar()
// Purpose:    Implementacion de Valores::incializar()
// Return:     int* (Retorna un vector)
////////////////////////////////////////////////////////////////////////

int* Valores::incializar(int tamanio){
	vector = (int*)malloc(tamanio*sizeof(int));
	return vector;
}

////////////////////////////////////////////////////////////////////////
// Name:       Valores::enecerar()
// Purpose:    Implementacion de Valores::encerar()
// Return:     int* (Retorna un vector)
////////////////////////////////////////////////////////////////////////

int* Valores::encerar(int tamanio, int *vector){
	for(int i=0; i<tamanio; i++){
		*(vector+i) = 0;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Valores::ingresarValores()
// Purpose:    Implementacion de Valores::ingresarValores()
// Return:     int* (Retorna un vector)
////////////////////////////////////////////////////////////////////////

int* Valores::ingresarValores(int dimension, int *vector){
	//vector = incializar(dimension);
	//vector = encerar(dimension, vector);
	for(int i=0;i<nElementos;i++){
		cout<<"Ingrese el elemento ["<<i+1<<"]: ";
		cin>>*(vector+i);
	}
	return vector;
}

////////////////////////////////////////////////////////////////////////
// Name:       Valores::calcularMaxComDiv()
// Purpose:    Implementacion de Valores::calcularMaxComDiv()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Valores::calcularMaxComDiv(int *vector, int dimension){
	int mcd,flag,num;
	for(int i=0;i<dimension;i++){
	 num=*(vector+i);
 	 if(i==0){
  		 mcd=num;
  	}
  	do{
    	flag=mcd%num;
   		mcd=num;
   		num=flag;
 	}while(flag!=0);
	 }
 cout<<"\nEl Maximo Comun Divisor es: "<<mcd;

}

////////////////////////////////////////////////////////////////////////
// Name:       Valores::calcularMinComMul()
// Purpose:    Implementacion de Valores::calcularMinComMul()
// Return:     void 
////////////////////////////////////////////////////////////////////////

void Valores::calcularMinComMul(int *vector,int dimension)
{
   int limit_multiplos = 999,i,j;
    int matriz_multiplos[dimension][limit_multiplos];
    int x, y, z=1;
    for(i=0;i<dimension;i++)
    {
         for(j=0;j<limit_multiplos;j++)
         {
             x = *(vector+i);
             y = x * z;
             z++;
             matriz_multiplos[i][j] = y;
         }
         z=1;
    }
    int h=0, w, p;
    int multiplo_por_defecto=1, aaa;
    int primer_multiplo = matriz_multiplos[0][h];
    for(i=1;i<dimension;)
    {
        for(j=0;j<limit_multiplos;)
        {
            if(primer_multiplo == matriz_multiplos[i][j])
            {
                w = primer_multiplo;
                i++;
                j=0;
            }
            else
            {
                j++;
                p = j;
            }
            if((j == limit_multiplos)  &&  (h != limit_multiplos))
            {
                h++;
                primer_multiplo = matriz_multiplos[0][h];
                i=1;
                j=0;
            }
            if((i == dimension) && (primer_multiplo == w))
            {
                printf("\nEl Minimo Comun Multiplo es: %d", primer_multiplo);
                exit(0);
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Funcion main
// Purpose:    Implementacion de la funcion principal
// Return:     0
////////////////////////////////////////////////////////////////////////

int main() {
	Valores val;
	int dimension, *vector;
	dimension = val.pedirDatos();
	vector = val.ingresarValores(dimension, vector);
	val.calcularMaxComDiv(vector, dimension);
	val.calcularMinComMul(vector, dimension);
	delete[] vector;
	return 0;
}




