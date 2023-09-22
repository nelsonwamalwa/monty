#include "monty.h"

vars *first;

/**
 * main - main
 * description: main
 * @argc: argc
 * @argv: argv
 * Return: 0
 */

int main(int argc, char **argv)
{
	first = malloc(sizeof(vars));
	if (!first)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	first->n = 0;
	first->f_error_code = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_opcode_loop(argv);
	return (0);
}

/**
 * opcode_loop - interpreter
 * description: this takes input
 * @argv: argv
 * Return: 0
 */

int f_opcode_loop(char **argv)
{
	stack_tt *stack = NULL;
	unsigned int counter = 0;
	int i, err;
	char *linebuff = NULL;
	size_t buffsize;
    ssize_t characters;
	FILE *fp = fopen(argv[1], "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(first);
		exit(EXIT_FAILURE);
	}

	characters = _getline(&linebuff, &buffsize, fp);

	while (characters >= 0)
	{
		for (i = 0; linebuff[i] != '\0'; i++)
		{
			if (linebuff[i] == '\n' && linebuff[i + 1] == '\0')
				linebuff[i] = '\0';
		}
		counter++;
		f_tokenize(&stack, linebuff, counter);
		if (linebuff != NULL)
			free(linebuff);
		linebuff = NULL;
		if (first->f_error_code == -1)
			break;

	    characters = _getline(&linebuff, &buffsize, fp);
	}
	err = first->f_error_code;
	fclose(fp);
	if (linebuff != NULL)
		free(linebuff);
	f_free_stack(stack);
	free(first);
	if (err == -1)
		exit(EXIT_FAILURE);
	return (0);
}

/**
 * tokenize - tokenize
 * description: tokenize
 * @line: line
 * @stack: dbl ptr to stack
 * @counter: ln count for errors
 * Return: 0
 */

int f_tokenize(stack_tt **stack, char *line, unsigned int counter)
{
	char *linebuff = NULL, *nbuff = NULL;
	int b = 0;

	linebuff = strtok(line, " ");
	if (!linebuff)
	{
		return (0);
	}
	nbuff = linebuff;
	nbuff = strtok(NULL, " ");
	if (nbuff != NULL)
	{
		first->n = atoi(nbuff);
		b = f_opcode_finder(stack, linebuff, counter);
	}
	else if (b != 1)
	{
		if (strcmp(linebuff, "push") == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			first->f_error_code = -1;
			return (-1);
		}
			b = f_opcode_finder(stack, linebuff, counter);
	}
	return (1);
}


/**
 * opcode_finder - finds proper opcode
 * description: str compares opcode for correlating func
 * @stack: dbl ptr to stack
 * @linebuff: linebuff
 * @counter: ln count for errors
 * Return: 0 or 1
 */


int f_opcode_finder(stack_tt **stack, char *linebuff, unsigned int counter)
{
	int i;

	instruction_tt arr[] = {
		{"push", f_pushit}, {"pall", f_pallit},
		{"pint", f_pintit}, {"pop", f_popit},
		{"swap", f_swapit}, {"add", f_addit},
		{"nop", f_nope}, {"sub", f_subit},
		{"div", f_divit}, {"mul", f_mullet},
		{"mod", f_modit},	{"#", f_nope},
		{"pchar", f_pcharit}, {"pstr", f_pstrit},
		{"rotl", f_rotlit}, {"rotr", f_rotrit},
		{"\0", NULL}
	};

	if (linebuff != NULL)
	{
		for (i = 0; arr[i].f; i++)
		{
			if (strcmp(linebuff, arr[i].f_opcode) == 0)
			{
				arr[i].f(stack, counter);
				return (1);
			}
			else if (linebuff[0] == '#')
			{
				arr[11].f(stack, counter);
				return (1);
			}
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", counter, linebuff);
	first->f_error_code = -1;
	return (-1);
}