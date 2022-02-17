#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

// NAME : RAHUL ROY
// ENROLLMENT : IIT2019194

void timestamp ( );

int main(int argc, char *argv[]){
	int tid, nthreads, i,j,k,n=500;
	int A[n][n], B[n][n], C[n][n];
	
	// Creating a parallel space for all the varibales
	
	#pragma omp parallel shared(A,B,C,nthreads) private(tid,i,j,k)
	{
		tid = omp_get_thread_num();
		
		// Initializing matrices
		#pragma omp for
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				A[i][j] = i+j;
			}
		}
		#pragma omp for
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				B[i][j] = A[i][j];
			}
		}
		#pragma omp for
		 for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				C[i][j] = 0;
			}
		 }
			
		cout<<"Matrix Multiplication by thread"<<tid<<"\n";
		#pragma omp for
		for(i=0;i<1024;i++){
			for(j=0;j<1024;j++){
				for(k=0;k<1024;k++){
					C[i][j] = C[i][j] + A[i][k]*B[k][j];
				}
			}
		 }
	}
	return 0;
}
