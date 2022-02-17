#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

// NAME: RAHUL ROY
// ENROLLMENT : IIT2019194

//void timestamp ( );

int main(){
	int n = 1000;
	int A[n][n];
	int B[n][n];
	int C[n][n];
	
	// Initializing matrices
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			A[i][j] = i+j;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			B[i][j] = i+j;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			C[i][j] = 0;
		}
	}
	
	// performing matrix multiplication and storing in C
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				C[i][j] = C[i][j] + A[i][k]*B[k][j];
			}
		}
	 }
	//cout<<"test statement"<<"\n";
	//for(int i=0;i<n;i++){
	//	for(int j=0;j<n;j++){
	//		cout<<C[i][j]<<" ";
	//	}
	//	cout<<"\n";
	//}
	return 0;
}
