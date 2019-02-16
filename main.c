#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY 10


int main() {
	int number;
	printf("Enter Number: ");
	scanf("%i", &number);
	printf("%i\n", number);
	if(number > MAX_ARRAY) {
		exit(-1);
	}

	int array[MAX_ARRAY] = {0};

	printf("Type ya numbers(%i): ",number);
	for (int i = 0; i < number; ++i) {
		int input = 0;
		scanf("%i", &input);
		array[i] = input;
		printf(" ");
	}

	printf("Output: ");
	for (int j = 0; j < 9; ++j) {
		printf("%i ",array[j]);
	}
}
