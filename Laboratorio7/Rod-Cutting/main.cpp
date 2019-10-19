/* 
 * File:   main.cpp
 * Author: 00148816
 *
 * Created on October 18, 2019, 3:53 PM
 */

#include <iostream>
using namespace std;

int p[]={0,1,5,8,9};
int r[]={-1,-1,-1,-1,-1};
int rodCutting(int n){
	r[0]=0;
	
	for(int j=1;j<=n;j++){
		int q=-1;
		for(int i = 1;i<=j;i++){
			q = max(q,p[i]+r[j-i]);
		}r[j]=q;
	}
	return r[n];
}

int main(){
	cout<<rodCutting(4)<<endl;
}