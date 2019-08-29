/* 
 * File:   main.cpp
 * Author: 00148816
 *
 * Created on August 25, 2019, 9:59 PM
 */

#include <iostream>

using namespace std;

//arreglo, paso, posicion inicial del arreglo y tamanio
int Menor(int numeros[], int paso, int numeroI, int tam){
    if(tam==paso){
        return numeroI; //
    }
    else{
        if(numeros[paso]<numeroI){
            numeroI=numeros[paso];
            numeroI=Menor(numeros,paso+1, numeroI, tam);
        }
        else{
            numeroI=Menor(numeros,paso+1, numeroI, tam);
        }
        return numeroI;
    }
}

int main(int argc, char** argv) {
    int numeros[100];
    
    cout<<"Ingrese el tamanio del array: ";
    int tam;
    cin>>tam;
    
    for(int i=0;i<tam;i++){
        cout<<i+1<<". Ingrese un numero numero: ";
        cin>>numeros[i];
    }
    
    int respuesta = Menor(numeros,0,numeros[0],tam);
    cout<<"El menor elemento es: "<<respuesta;
    return 0;
}

