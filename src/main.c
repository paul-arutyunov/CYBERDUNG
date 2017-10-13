#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char input[100];

/* In-game shell functions */
void clearArgs(char *args);
void parseInput(char *input);

/* Simple random funtion*/
int rnd(int min, int max);

int main(int argc, char *argv[])
{
	extern char input[];	

	int running = 1;
	srand(time(NULL));	

	while (running)
	{
		/* Input stuff */
		fgets(input, 100, stdin);
		clearArgs;
		parseInput(input);
	}
}
