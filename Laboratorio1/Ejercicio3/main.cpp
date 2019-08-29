/* 
 * File:   main.cpp
 * Author: 00148816
 *
 * Created on August 25, 2019, 9:59 PM
 */

#include <iostream>

using namespace std;

int Menor(int numeros[], int tam, int index, int paso){
    if(tam==1){
        return numeros[0];
    }
    else{
        if(numeros[index]<numeros[paso]){
            paso=index;
            paso=Menor(numeros, tam,index+1, paso);
        }
        else{
            paso=Menor(numeros, tam,index+1, paso);
        }
        
    }
}

int main(int argc, char** argv) {
    int numeros[100];
    int index=0;
    int paso=0;
    
    cout<<"Ingrese el tamanio del array: ";
    int tam;
    cin>>tam;
    
    for(int i=0;i<tam;i++){
        cout<<i+1<<". Ingrese un numero numero: ";
        cin>>numeros[i];
    }

    int respuesta = Menor(numeros,tam, index, paso);
    cout<<"El menor elemento es: "<<respuesta;
    return 0;
}

