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

	/* In-shell command line arguments parsing */
	for (i = 1; argv[i] != NULL; i++)
	{
		if	(strcmp(argv[i], "--debug") == 0 || strcmp(argv[i], "-d") == 0) /* Debug mode */
			debug = 1;
		else if	(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) /* Help */
		{
			printf("\n\n'--debug' or '-d':\tDebug mode on\n'--help' or '-h':\tPrint this message\n\n");
			return 0;
		} else {
			printf("\nInvalid command line argument.\n\n");
			return 1;
		}
	}


	printf("\nDebug mode: %s\n\n", (debug == 1) ? "ON" : "OFF" );

	puts("\tCCC YYY BBB EEE RRR DD  U U NNN GGG");
	puts("\tC    Y  B B E   R R D D U U N N G  ");
	puts("\tC    Y  BBB EEE RR  D D U U N N G G");
	puts("\tC    Y  B B E   R R D D U U N N G G");
	puts("\tCCC  Y  BBB EEE R R DDD UUU N N GGG\n");

	while (running)	/* Main loop */
	{
		/* Input stuff */
		printf("> ");
		fgets(input, 100, stdin);
		clearArgs(args);
		parseInput(input);

		if (debug)
		{
			i = 0;
			for (i = 0; i < ARGS_MAX; i++) printf("\n%s\n", args[i]);
		}

		if	(strcmp(args[0], "quit") == 0)
		{
			printf("\nDo you really want to quit the program? Y/N\n");
			if (getchar() == 'y') return 0;
			if (getchar() == 'n') printf("\nOkay.\n");
		}
		else if (strcmp(args[0], "make") == 0 && strcmp(args[1], "love\n") == 0) 
		{
			printf("\nNot war.\n");
		}
		else printf("\nUnknown command '%s'.\n", args[0]);
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
	extern char *args[];
	char *word;
	int i;

	word = strtok(input, " ");
	while (word != NULL)
	{
		args[i] = word;
		word = strtok(NULL, " ");
		i++;
	}
	if (args[1] == NULL) args[0][strlen(args[0])-1] = '\0';
}
