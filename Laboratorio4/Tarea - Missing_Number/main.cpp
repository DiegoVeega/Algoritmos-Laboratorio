/* 
 * File:   main.cpp
 * Author: 00148816
 *
 * Created on September 17, 2019, 11:16 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

void swap(int* a, int* b){
    int t=*a;
    *a = *b;
    *b =t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i =(low -1);
    
    for(int j=low;j<=high-1;j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return(i+1);
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);
        quickSort(arr, low,pi-1);
        quickSort(arr, pi+1,high);
    }
}

void PrintSiguiente(int arr[], int size){
    int i;
    int mayor=0;
    for(i=0;i<size;i++){
        if(arr[i] > mayor){
            mayor=arr[i];
        }
    }
    mayor++;
    while(mayor%2!=0 || mayor<0){
        mayor++;
    }
    cout<<mayor;
}

void printArray(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main(int argc, char** argv) {
    
    int arr[]={10,7,8,9,1,5};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<"Su arreglo es: ";
    printArray(arr,n);
    quickSort(arr,0,n-1);
    cout<<"Sorted array: ";
    printArray(arr,n);
    cout<<"El siguiente numero positivo y multiplo de 2 que no esta en la lista es: ";
    PrintSiguiente(arr, n);

    return 0;
}

