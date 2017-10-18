#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ARGS_MAX	10

char input[100];
char *args[ARGS_MAX];

/* In-game shell functions */
void clearArgs(char *args[]);
void parseInput(char *input);

/* Simple random funtion*/
int rnd(int min, int max);

int main(int argc, char *argv[])
{
	extern char input[];	
	extern char *args[];

	int running = 1;
	int debug = 0;

	srand(time(NULL));	

	int i;

	/* In-shell command line arguments parsing doesn't work. FIXME!!! */
	for (i = 0; i < ARGS_MAX; i++)
	{
		if	(strcmp(argv[i], "--debug") == 0 || strcmp(argv[i], "-d") == 0) /* Debug mode */
			debug = 1;
		else if	(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) /* Help */
		{
			printf("\n\n'--debug' or '-d':\tDebug mode on\n'--help' or '-h':\tPrint this message\n\n");
		} else {
			printf("\nInvalid command line argument.\n");
			return 1;
		}
	}

	while (running)	/* Main loop */
	{
		/* Input stuff */
		fgets(input, 100, stdin);
		clearArgs(args);
		parseInput(input);
	}
}

void clearArgs(char *args[])
{
	int i;

	for (i = 0; i < ARGS_MAX; i++)
	{
		args[i] = NULL;
	}
}

void parseInput(char *input)
{
	char *word;
	int i;

	word = strtok(input, " ");
	while (word != NULL)
	{
		args[i] = word;
		word = strtok(NULL, " ");
		i++;
	}
}
