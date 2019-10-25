/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00148816
 *
 * Created on October 22, 2019, 10:03 PM
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * 
  Pseudocodigo:
 * 
    FASTEST-WAY(a, t, e, x, n)
    1 f1[1] ← e1 + a1,1
    2 f2[1] ←e2 + a2,1
    3 for j ← 2 to n
    4 do if f1[j - 1] + a[1][j] ≤ f2[j - 1] + t[2][j-1] + a[1][j]
    5 then f1[j] ← f1[j - 1] + a[1][j]
    6 else f1[j] ← f2[j - 1] + t[2][j-1] + a[1][j]
    7 if f2[j - 1] + a[2][j] ≤ f1[j - 1] + t[1][j-1] + a[2][j]
    8 then f2[j] ← f2[j - 1] + a[2][j]
    9 else f2[j] ← f1[j - 1] + t[1][j-1] + a[2][j]
    10 if f1[n] + x1 ≤ f2[n] + x2
    11 then f* = f1[n] + x1
    12 else f* = f2[n] + x2
 * 
 */

int FASTESTWAY(int a[][2], int t[][2], int* e, int* x, int n){
    
    int f1[n];
    int f2[n];
    f1[0] = e[0]+a[0][0];
    f2[0] = e[1]+a[0][1];
    
    string elemento=to_string(e[0])+to_string(a[0][0]); //
    string elemento2=to_string(e[0])+to_string(a[0][1]); //


    for(int j = 1; j < n; j++){
        string telemento = elemento;
        string telemento2 = elemento2;

        if(f1[j-1]+a[j][0] <= f2[j-1]+t[j-1][1]+a[j][0]){
            f1[j] = f1[j-1]+a[j][0];
            elemento=telemento+", "+to_string(a[j][0]);
        }else{
            f1[j] = f2[j-1]+t[j-1][1]+a[j][0];
            elemento2=telemento2+", "+to_string(a[j][0]);
        }

        if(f2[j-1]+a[j][1] <= f1[j-1]+t[j-1][0]+a[j][1]){
            f2[j] = f2[j-1]+a[j][1];
            elemento2=telemento2+", "+to_string(a[j][1]);
        }else{
            f2[j] = f1[j-1]+t[j-1][0]+a[j][1];
            elemento2=telemento+", "+to_string(a[j][1]);
        }
        
    }

    if(f1[n-1]+x[0] <= f2[n-1]+x[1]){
        
        cout << elemento << ", " << x[0];
        printf("\n");
        printf("Tiempo: ");
        return f1[n-1]+x[0];
        
    }else{
        
        cout << elemento2 << ", " << x[1];
        printf("\n");
        printf("Tiempo: ");
        return f2[n-1]+x[1];
    }
}

int main(int argc, char** argv) {
    
    int campo[][2] = {{1,2}, {3,4}, {5,6}};
    int tiempo[][2] = {{1,2}, {3,4}};
    
    int estacionE[] = {1, 5}; //entrando a e ?
    int tiempox[] = {2, 6}; //al salir de n
    
    printf("%d",FASTESTWAY(campo, tiempo, estacionE, tiempox, 3));
    cout << endl;
    return 0;
}