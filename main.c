#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY 10

struct Matrix {
	int x;
	int y;
	int data[MAX_ARRAY][MAX_ARRAY];
};
struct Matrix A;
struct Matrix B;

void printArray(struct Matrix thisMatrix);

struct Matrix getArrayFromInput(){
	int x;
	int y;

	printf("Enter x y: ");
	scanf("%i %i", &x, &y);
	if(x > MAX_ARRAY || y > MAX_ARRAY) {
		exit(-1);
	}

	struct Matrix temp;
	temp.x = x;
	temp.y = y;

	printf("Type ya numbers(%i):\n",x);

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
	if (A.y != B.x) {
		printf("Size Mismatch: %i %i\n", A.y, B.x);
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

	printf("\n");

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
	printf("SUM: %i\n", sum);

	return 1;
}

int main() {
	A = getArrayFromInput();
	B = getArrayFromInput();

	printArray(A);
	printArray(B);

	printf("---------------\n");
	for (int i = 1; i < A.x; ++i) {
		for (int j = 1; j < B.y; ++j) {
			getMatrixProduct(i,j);
//			printf("%i %i\n",i, j);
		}
	}

	printf("---------------\n");


}

void printArray(struct Matrix thisMatrix) {
//	printf("x: %i\n",thisMatrix.x);
//	printf("y: %i\n",thisMatrix.y);
	for (int j = 0; j < thisMatrix.y; ++j) {
		for (int i = 0; i < thisMatrix.x; ++i) {
				printf("%i ", thisMatrix.data[i][j]);
		}
		printf("\n");
	}
}
