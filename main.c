#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char name[] = "Pankaja";


char ** words(char *str) {
	char ** res  = NULL;
	char *  p    = strtok (str, " ");
	int n_spaces = 0, i;


	while (p) {
		res = realloc (res, sizeof (char*) * ++n_spaces);
		if (res == NULL)
			exit (-1); /* memory allocation failed */
		res[n_spaces-1] = p;
		p = strtok (NULL, " ");
	}

/* real loc one extra element for the last NULL */
	res = realloc (res, sizeof (char*) * (n_spaces+1));
	res[n_spaces] = 0;

// Test
	for (i = 0; i < (n_spaces+1); ++i){
//		printf ("res[%d] = %s\n", i, res[i]);
	}

	return res;
}

void testOutput(char** output){
	int counter = 0;
	while (output[counter] != 0) {
		printf("%d | %s",  counter, output[counter]);
		printf("%s", "\n");
		counter++;
	}
}

int main() {
	while (1) {
		printf("%s >", name);

		char buffer[80];
		fgets(buffer, sizeof buffer, stdin);

		if (buffer[0] == '\n') {
			printf("Good Bye!\n");
			exit(0);
		}


		char **cmd = words(strtok(buffer, "\n"));
//		testOutput(cmd);

		if (fork() != 0) { /* fork off child process */
			// Parent code
			int status;
			waitpid(-1, &status, 0); /* wait for child to exit */
			printf("Status: %d \n\n", status);

		} else {
			// Child code
			execvp(cmd[0], cmd);
		}

		free(cmd);
	}
}
