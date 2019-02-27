#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ARRAY 10
#define PROMPT 0

struct Indices {
	int i; /* row */
	int j; /* column */
} ;
struct Matrix {
	int x;
	int y;
	int data[MAX_ARRAY][MAX_ARRAY];
};
struct Matrix A;
struct Matrix B;
struct Matrix R;

void printArray(struct Matrix thisMatrix);

struct Matrix getArrayFromInput(){
	int x;
	int y;

	if (PROMPT){
		printf("Enter y x: ");
	}
	scanf("%i %i", &y, &x);
	if(x > MAX_ARRAY || y > MAX_ARRAY) {
		exit(-1);
	}

	struct Matrix temp;
	temp.x = x;
	temp.y = y;

	if (PROMPT){
		printf("Type ya numbers(%i):\n",x);
	}

	for (int j = 0; j < y; ++j) {
		for (int i = 0; i < x; ++i) {
			int input = 0;
			scanf("%i", &input);
			temp.data[i][j] = input;
		}
		fflush(stdin);
	}
	return temp;
}

int getMatrixProduct(int col, int row){
//	printf("Output Array Size: %i\n", A.x*B.y);
	if (A.x != B.y) {
		printf("Size Mismatch: %i %i\n", A.x, B.y);
		return -1;
	}
//
//	for (int l = 0; l <A.x; ++l) {
//		for (int k = 0; k < B.y; ++k) {
//			printf("%i %i\n",l, k);
//		}
//	}

	int rowValues[10] = {0};
	for (int k = 0; k < A.x; ++k) {
		int val = A.data[k][col - 1];
//		printf("%i ", val);
		rowValues[k] = val;
	}


	int colValues[10] = {0};
	for (int l = 0; l < B.y; ++l) {
		int val = B.data[row - 1][l];
//		printf("%i\n", val);
		colValues[l] = val;
	}

	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		sum = sum + (rowValues[i] * colValues[i]);
	}
//	printf("SUM: %i\n", sum);

	return sum;
}

void* multiplyThread(void* thing){

	int j = ((struct Indices*)thing)->j;
	int i = ((struct Indices*)thing)->i;
	R.data[j-1][i-1] = getMatrixProduct(i,j);
//	printf("%s\n","lol wut");
	return NULL;
}

int main() {
	A = getArrayFromInput();
	B = getArrayFromInput();

	if (PROMPT){
		printArray(A);
		printArray(B);
	}

	R.y = A.y;
	R.x = B.x;

	pthread_t thread_id[MAX_ARRAY*MAX_ARRAY];
	int threadCount = 0;

	for (int i = 1; i < R.y+1; ++i) {
		for (int j = 1; j < R.x+1; ++j) {
			struct Indices *data = (struct Indices *)malloc(sizeof(struct Indices));
			data->i = i;
			data->j = j;
			pthread_create(&thread_id[threadCount], NULL, multiplyThread, (void *)data);
			threadCount++;
		}
	}
	for (int k = 0; k < threadCount; ++k) {
		pthread_join( thread_id[k], NULL);
	}

	printArray(R);

}

void printArray(struct Matrix thisMatrix) {
//	printf("x: %i\n",thisMatrix.x);
//	printf("y: %i\n",thisMatrix.y);
	for (int j = 0; j < thisMatrix.y; ++j) {
		for (int i = 0; i < thisMatrix.x; ++i) {
				printf("%i  ", thisMatrix.data[i][j]);
		}
		printf("\n");
	}
}
