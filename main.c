#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY 10

struct Matrix {
	int x;
	int y;
	int data[MAX_ARRAY][MAX_ARRAY];
};

void printArray(struct Matrix thisMatrix);

int main() {
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
	printArray(temp);
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