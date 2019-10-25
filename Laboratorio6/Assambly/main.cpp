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

#include <string>
#include <iostream>

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

    for(int j = 1; j < n; j++){

        if(f1[j-1]+a[j][0] <= f2[j-1]+t[j-1][1]+a[j][0]){
            f1[j] = f1[j-1]+a[j][0];
        }else{
            f1[j] = f2[j-1]+t[j-1][1]+a[j][0];
        }

        if(f2[j-1]+a[j][1] <= f1[j-1]+t[j-1][0]+a[j][1]){
            f2[j] = f2[j-1]+a[j][1];
        }else{
            f2[j] = f1[j-1]+t[j-1][0]+a[j][1];
        }
        
    }

    
    
    
    
    //Trabajar datos
}

int main(int argc, char** argv) {
    
    return 0;
}