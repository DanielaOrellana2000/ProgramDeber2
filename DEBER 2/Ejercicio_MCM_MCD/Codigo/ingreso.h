/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
*		PROGRAMA PARA FUNCIONES BASICAS							  *
* CARRERA: Ingenieria de Software                                 *
* NOMBRE: Daniela Orellana                                        *
* FECHA DE CREACIÓN: 29/05/2020                                   *
* NRC: 6396                                                       *
******************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Ingreso{

public:
    char* ingresar(char*);
    string ingresarSoloTexto(char*);
    int ingresarEntero(char *);
    float ingresarFlotante(char *);

};

char* Ingreso::ingresar(char* msg){
    char* texto;
    cout<<msg<<endl;
    cin>>texto;
    return texto;
}

string Ingreso::ingresarSoloTexto(char *msg){
    float valor;
    string texto;
    string res;

    while (1)
    {
        bool is_valid = true;
        cout << msg << endl;
        getline(cin,texto);
        try{
            for (size_t i = 0; i < texto.length(); i++) {

                if (!isalpha(texto[i])) {
                    if(texto[i] == ' '){
                        continue;
                    }else{
                        cout << "Se debe ingresar solo letras\n";
                        is_valid = false;
                        break;
                    }

                }


            }
        }catch(exception e){
            cout<<"error";
        }

        if (is_valid){
            res = texto.c_str();
            break;
        }
    }
    return res;
}

float Ingreso::ingresarFlotante(char *msg){
    float valor;
    string numero;

    while (1)
    {
        bool is_valid = true;
        cout << msg << endl;
        cin >> numero;
        try{
            for (size_t i = 0; i < numero.length(); i++) {

                if (!isdigit(numero[i])) {
                    if(!(numero[i]=='.')){
                        cout << "Se debe ingresar numeros\n";
                        is_valid = false;
                        break;
                    }
                }
            }
        }catch(exception e){
            cout<<"error";
        }

        if (is_valid){
            stringstream geek(numero);
            geek>>valor;
            break;
        }
    }
    return valor;
}

int Ingreso::ingresarEntero(char *msg){
    int valor;
    string numero;
    char *res;

    while (1)
    {
        bool is_valid = true;
        cout << msg << endl;
        cin >> numero;
        try{
            for (size_t i = 0; i < numero.length(); i++) {

                if (!isdigit(numero[i])) {

                    cout << "Se debe ingresar numeros\n";
                    is_valid = false;
                    break;

                }
            }
        }catch(exception e){
            cout<<"error";
        }

        if (is_valid){
            res = (char *)numero.c_str();
            valor=atoi(res);
            break;
        }
    }
    return valor;
}

