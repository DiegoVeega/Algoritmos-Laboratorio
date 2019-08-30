/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00148816.
 *
 * Created on August 29, 2019, 4:47 PM
 */

#include <iostream>

using namespace std;

int SumaMatriz(int A[][3], int B[][3], int C[][3], int fila, int columna){
    if(fila<3){
        if(columna<3){
            C[fila][columna]=A[fila][columna]+B[fila][columna];
            columna++;
            SumaMatriz(A,B,C,fila, columna);
        }
    }
}

int main(int argc, char** argv) {

    int A[][3] = {{1,3,5},{7,9,1},{3,5,7}};
    int B[][3] = {{9,1,3},{5,7,9},{1,3,5}};
    int C[][3] = {{0,0,0},{0,0,0},{0,0,0}};
    
    int fila=0, columna=0;
    
    SumaMatriz(A,B,C,fila, columna);
    return 0;
}

