/* 
 * File:   main.cpp
 * Author: 00148816.
 *
 * Created on August 29, 2019, 6:24 PM
 */

#include <iostream>


using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*inicio;

class Pila{
    public:
        Nodo* crearNodo(int valor){
            Nodo *n =new Nodo;
            n->dato =valor;
            n->sig = nullptr;
            return n;
        }
        
        void push(int valor){
            Nodo *n=crearNodo(valor);
            n->sig = inicio;
            inicio=n;
        }
        void mostrarPila(){
            Nodo *temp = inicio;
            if(!inicio){
                cout<<"La pila esta vacia"<<endl;
            }
            else{
                while(temp){
                    cout<<temp->dato<<", ";
                    temp = temp ->sig;
                }
            }
        }
};

int main(int argc, char** argv) {
    
    //--------------------Pilas
    Pila par;
    Pila impar;
    //--------------------Pilas
    
    int numeros[100];
    int elementos;
    
    cout<<"Cuantos numeros quiere agregar? ";
    cin>>elementos;
    
    for (int i = 0; i < elementos; i++) {
        cout<<i+1<<". ";
        cin>>numeros[i];
    }

    //Determinar si un numero es par o impar
    for (int i = 0; i < elementos; i++) {
        
        switch(numeros[i]%2){
            case 0:
                cout<<numeros[i]<<"Es par";
                par.push(numeros[i]);
                break;
                
            case 1:
                cout<<numeros[i]<<"Es impar";
                impar.push(numeros[i]);
                break;
        }
        /*
        if(numeros[i]==0){
            //Insertar en pila par
            cout<<numeros[i]<<"Es par";
            par.push(numeros[i]);
            
        }
        else if(numeros[i]%2==0){
            //Insertar en pila par
            cout<<numeros[i]<<"Es par";
            par.push(numeros[i]);
        }
        else{
            //Insertar en pila impar
            cout<<numeros[i]<<"Es impar";
            impar.push(numeros[i]);
        }
        */
        cout<<"FOR PAR";
        par.mostrarPila();
        cout<<"\n";
        cout<<"FOR IMPAR";
        impar.mostrarPila();
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"Pares: ";
    par.mostrarPila();
    cout<<"\n"<<"impares"<<endl;
    impar.mostrarPila();
    
    return 0;
}

