#include "monty.h"
global glob;

/**
 * free_glob - frees the global variables
 *
 * return: no return
 */
void free_glob(void)
{
	free_ list(glob.head);
	free(glob.buff);
	free(glob.fdis);
}

/**
 * start_glob - initialize the global variables
 *
 * @fdis: file descriptor
 * Return: no return
 */
void start_glob(FILE *fdis)
{
	glob.lifo = 1;
	glob.curr = 1;
	glob.arg = NULL;
	glob.head = NULL;
	glob.fdis = fdis;
	glob.buff = NULL;
}
/**
 * check_input - checks if the file exists and if
 * the file can be opened
 * @argc: argument count.
 * @argv: argument vector.
 * Return: file struct
 */

FILE *check_input(int argc, char *argv[])
{
	FILE *fdis;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fdis = fopen(argv[1], "r");

	if (fdis == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fdis);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fdis;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fdis = check_input(argc, argv);
	start_glob(fdis);
	nlines = getline(&glob.buff, &size, fdis);
	while (nlines != -1)
	{
	lines[0] = strtok(			
	}
