/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00148816.
 *
 * Created on August 28, 2019, 9:12 AM
 */

#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*inicio;

class ListaEnlazada{
public:
    Nodo* crearNodo(int valor){
        Nodo *n = new Nodo;
        n->dato =valor;
        n->sig = nullptr;
        return n;
    }
    void mostrarLista(){
        Nodo *temp = inicio;
        if(!inicio)
            cout<<"La lista no posee elementos"<<endl;
        else{
            while(temp){
                cout<<temp->dato<<", ";
                temp = temp->sig;
            }
        }
    }
    void agregarElemento(int valor){
        Nodo *n = crearNodo(valor), *temp;
        if(!inicio){
            inicio = n;
        }
        else{
            for(temp=inicio; temp->sig; temp=temp->sig);
            temp->sig =n;
        }
    }
    
    ListaEnlazada(){
        inicio=nullptr;
    }
};

int main(int argc, char** argv) {
    
    ListaEnlazada lista1;
    
    lista1.agregarElemento(1);
    lista1.agregarElemento(2);
    
    lista1.mostrarLista();
    return 0;
}

