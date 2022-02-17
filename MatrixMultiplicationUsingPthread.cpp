#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

using namespace std;

#define n 500
#define MAX_THREADS 8

// NAME : RAHUL ROY
// ENROLLMENT : IIT2019194


int A[n][n], B[n][n], C[n][n];

typedef struct {
	int startX;
}Args;

pthread_t tid[MAX_THREADS];

void * worker(void *);

void MULT_MATRIX() {
	int xCounter = 0;
	int yCounter = 0;
	int threadCounter = 0;
	for(int i = 0; i < MAX_THREADS; i++) {
		Args * args = (Args*)malloc(sizeof(Args));
		args->startX = xCounter;
		xCounter += n/MAX_THREADS;
		pthread_create(&tid[threadCounter++], 0, worker, args);
	} 
	
	for(int j = 0; j < MAX_THREADS; j++) {
		pthread_join(tid[j], NULL);
	}
}

void* worker(void * args) {
	Args * arg = (Args*)malloc(sizeof(Args));
	int i,j,k;
	int endX = arg->startX + n/MAX_THREADS;
	for(i = arg->startX; i < endX; i++) {
		for(j = 0; j < n; ++j) {
			for(k = 0; k < n; ++k) {
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
	free(arg);
	pthread_exit(0);
}

int main(int argc, char **argv) {
	srand((unsigned) time(NULL));
	
	// Initialize the matrices
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
	
	// Performing Matrix Multiplication
 	MULT_MATRIX();
 	
}

// When dealing with larger matrices, the execution time decreases with parallel threading.
