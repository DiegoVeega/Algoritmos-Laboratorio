/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 00148816
 *
 * Created on October 25, 2019, 3:50 PM
 */

#include <cstdlib>
#include "../iostream"

using namespace std;

/*
 * 
 */

int Tareas(int inicio[], int fin[]){
    int L[]={0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < i; j++) {
            if(fin[j]<inicio[i] && L[i]<L[j]){
                L[i]=L[j];
            }
        }
        L[i]++;
    }
    return L[10];
}
int main(int argc, char** argv) {
    
    int inicio[]={0,1,2,3,3,5,5,6,8,8,12};
    int fin[]={6,4,13,5,8,7,9,10,11,12,14};
    
    cout<<("%d",Tareas(inicio, fin));
    
    return 0;
}

