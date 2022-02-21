#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

// NAME : RAHUL ROY
// ENROLLMENT: IIT2019194

//void timestamp ( );



int main(){
	int n = 1000;
	int A[n];
	for(int i=0;i<n;i++){
		A[i] = i;
	}
	int pre[n];
	pre[0] = A[0];
	// Calculating prefix sum
	for(int i=1;i<n;i++){
		pre[i] = pre[i-1] + A[i];
	}
	 
	// Displaying prefix sum
	for(int i=0;i<n;i++){
		cout<<pre[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
