/* 
 * File:   main.cpp
 * Author: 00148816.
 *
 * Created on August 29, 2019, 6:24 PM
 */
/*
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
        int recorer(int tam){
            Nodo *temp =inicio;
            if(!inicio){
                tam=0;
                return tam;
            }
            else{
                while(temp){
                    temp = temp ->sig;
                    tam++;
                }
                return tam;
            }
        }
        
};

struct NodoP{
    int dato;
    NodoP *sig;
}*ini;

class Pila2{
    public:
        NodoP* crearNodo(int valor){
            NodoP *n =new NodoP;
            n->dato =valor;
            n->sig = nullptr;
            return n;
        }
        
        void push(int valor){
            NodoP *n=crearNodo(valor);
            n->sig = ini;
            ini=n;
        }
        void mostrarPila(){
            NodoP *temp = ini;
            if(!ini){
                cout<<"La pila esta vacia"<<endl;
            }
            else{
                while(temp){
                    cout<<temp->dato<<", ";
                    temp = temp ->sig;
                }
            }
        }
        int recorer(int tam){
            NodoP *temp =ini;
            if(!ini){
                tam=0;
                return tam;
            }
            else{
                while(temp){
                    temp = temp ->sig;
                    tam++;
                }
                return tam;
            }
        }
};

int main(int argc, char** argv) {
    
    //--------------------Pilas
    Pila par;
    Pila2 impar;
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
        if(numeros[i]==0){
            //Insertar en pila par
            par.push(numeros[i]);
            
        }
        else if(numeros[i]%2==0){
            //Insertar en pila par
            par.push(numeros[i]);
        }
        else{
            //Insertar en pila impar
            impar.push(numeros[i]);
        }
    }
    int tampar=0;
    int tamimpar=0;
    
    tampar=par.recorer(tampar);
    cout<<"Hay "<<tampar<<" elementos en la pila de pares: ";
    par.mostrarPila();
    
    tamimpar=impar.recorer(tamimpar);
    cout<<"\n"<<"Hay "<<tamimpar<<" elementos en la pila de impares: ";
    impar.mostrarPila();
    cout<<"\n";
    
    if(tampar==tamimpar){
        cout<<endl<<endl<<"La pila de pares y la pila de impares tienen el mismo tamaño."<<endl;
    }
    else{
        cout<<"La pila de pares y la pila de impares no tienen el mismo tamaño.";
    }
    
    return 0;
}
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
        Nodo *n = new Nodo;
        n-> dato = valor;
        n->sig = nullptr;
        return n;
    }
    
    void push(int valor){
        Nodo *n = crearNodo(valor);
        n-> sig = inicio;
        inicio = n;
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
        
        Pila(){
            inicio =nullptr;
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
    int tampar=0;
    int tamimpar=0;

    //Determinar si un numero es par o impar
    for (int i = 0; i < elementos; i++) {
        if(numeros[i]==0){
            //Insertar en pila par
            tampar++;
            par.push(numeros[i]);
            
        }
        else if(numeros[i]%2==0){
            //Insertar en pila par
            tampar++;
            par.push(numeros[i]);
        }
        else{
            //Insertar en pila impar
            tamimpar++;
            impar.push(numeros[i]);
        }
    }
    
    cout<<"Hay "<<tampar<<" elementos en la pila de pares: ";
    par.mostrarPila();
    
    cout<<"\n"<<"Hay "<<tamimpar<<" elementos en la pila de impares: ";
    impar.mostrarPila();
    cout<<"\n";
    
    if(tampar==tamimpar){
        cout<<endl<<endl<<"La pila de pares y la pila de impares tienen el mismo tamaño."<<endl;
    }
    else{
        cout<<"La pila de pares y la pila de impares no tienen el mismo tamaño.";
    }
    
    return 0;
}
