/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00148816.
 *
 * Created on August 28, 2019, 9:34 AM
 */

#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
    Nodo *prev;
}*inicio, *fin;


class ListaDoblementeEnlazada{
public:
    Nodo* crearNodo(int valor){
        Nodo *n =new Nodo;
        n->dato =valor;
        n->sig = nullptr;
        n->prev =nullptr;
        return n;
    }
    
    void agregarElemento(int valor){
        Nodo *n = crearNodo(valor);
        if(!inicio){
            inicio = n;
            fin = n;
        }
        else{
            fin->sig=n;
            n->prev=fin;
            fin=n;
        }
    }
    
    void mostrartListaAdelante(){
        Nodo *temp = inicio;
        if(!inicio){
            cout<<"La lista no posee elementos"<<endl;
        }
        else{
            while(temp){
                cout<<temp->dato<<", ";
                temp = temp->sig;
            }
        }
    }
    
    void mostratListaAtras(){
        Nodo *temp = fin;
        if(!inicio){
            cout<<"La lista no posee elementos"<<endl;
        }
        else{
            while(temp){
                cout<<temp->dato<<", ";
                temp = temp->prev;
            }
        }
    }
    
    void eliminarElementoAnterior(int valor){
	Nodo *temp = inicio;
	Nodo *aux=NULL;
	Nodo *aux1;
	while(temp!=NULL &&  temp->dato!=valor){ //Pasar al siguiente
		aux=temp;
		temp=temp->sig;
	}
	if(temp->dato==valor){
		//SI REF ESTA EN EL PRIMER DATO
		if(aux==NULL){
			aux=temp;
			temp=temp->sig;
			aux->sig=NULL;
			inicio=temp;
			delete(aux);
		}
		//SI REF ESTA EN OTRO LADO
		else{
                    aux->sig=temp;
                    temp->prev = aux->prev;
                    delete(aux);
			/*aux->sig=temp->sig;
			temp->sig=NULL;
			delete(temp);*/
		}
    	}
    }
};

int main(int argc, char** argv) {
    
    ListaDoblementeEnlazada lista1;
    
    lista1.agregarElemento(1);
    lista1.agregarElemento(2);
    lista1.agregarElemento(3);
    lista1.agregarElemento(4);
    lista1.agregarElemento(5);
    
    int valor=2;
    
    lista1.eliminarElementoAnterior(valor);
    lista1.mostrartListaAdelante();

    return 0;
}

