/* 
 * File:   main.cpp
 * Author: 00148816
 *
 * Created on August 25, 2019, 9:24 PM
 */

#include <iostream>
#include <math.h>

using namespace std;

int potencia(int x,int in, int n, int paso){
    if(paso!=n){
        x=x*in;
        paso++;
        potencia(x,in, n, paso);
    }
    else{
        return x;
    }
}

int main(int argc, char** argv) {
    int x, n, in;
    
    cout<<"Ingrese el numero que desea elevar: ";
    cin>>x;
    cout<<"Ingrese la potencia: ";
    cin>>n;
    
    int paso=1;
    in=x;
    int respuesta=potencia(x, in, n, paso);
    
    cout<<x<<" elevado a la potencia "<<n<<" es igual a: "<<respuesta;
    
    return 0;
}

