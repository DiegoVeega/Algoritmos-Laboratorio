/* 
 * File:   main.cpp
 * Author: 00148816.
 *
 * Created on August 25, 2019, 2:51 PM
 */
#include <iostream>

using namespace std;

void fibonacci(int limite, int num1, int num2, int temp){
    if(num2<=limite){
        cout<<", ";
        cout<<num2; //Imprime el valor de num2 
    }
    if(num2!=limite && num2<limite){ //Verifica si num2 no sobrepasa el limite
        temp=num1;
        num1=num2;
        num2=temp+num1;
        fibonacci(limite, num1, num2, temp); //Llamada  a la funcion
    }
};

int main(int argc, char** argv) {
    int limite, num1=0, num2=1, temp;
    cout<<"Ingrese el numero limite para la serie: ";
    cin>>limite;
    
    if(limite==0){
        cout<<"Serie: "<<num1;
    }
    else{
        temp=0;
        cout<<"Serie: "<<num1;
        fibonacci(limite, num1, num2, temp);
        cout<<".";
    }
    
    return 0;
}