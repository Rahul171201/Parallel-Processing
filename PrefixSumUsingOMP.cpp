#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

// NAME : RAHUL ROY
// ENROLLMENT: IIT2019194

using namespace std;

void timestamp ( );

int main(int argc, char *argv[]){
	int tid, nthreads, i,j,k,n=500;
	int A[n],int pre[n];
	
	// Creating a parallel space for all the varibales
	
	#pragma omp parallel shared(A,B,C,nthreads) private(tid,i,j,k)
	{
		tid = omp_get_thread_num();
		
		// Initializing Array
		#pragma omp for
		for(i=0;i<n;i++){
			A[i] = i;
		}
		pre[0] = A[0];
			
		cout<<"Prefix Sum by thread"<<tid<<"\n";
		#pragma omp for
		for(i=1;i<n;i++){
			pre[i] = pre[i-1]+A[i];
		 }
	}
	return 0;
}
