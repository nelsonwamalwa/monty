#include "monty.h"

vars *first;

/**
 * main - Entry Point
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
 * f_opcode_loop - interpret
 * description: Takes the input
 * @argv: argv
 * Return: 0
 */

int f_opcode_loop(char **argv)
{
	stack_tt *stack = NULL;
	unsigned int counter = 0;
	int chars, i, err;
	char *linebuff = NULL;
	size_t buffsize;
FILE *fp = fopen(argv[1], "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(first);
		exit(EXIT_FAILURE);
	}
	chars = getline(&linebuff, &buffsize, fp);
	while (chars >= 0)
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
	    chars = getline(&linebuff, &buffsize, fp);
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
 * f_tokenize - Tokenizes
 * description: Tokenizes
 * @line: line
 * @stack: Pointer to stack
 * @counter: Count for errors
 * Return: Always 0 (Success)
 */

int f_tokenize(stack_tt **stack, char *line, unsigned int counter)
{
	char *linebuff = NULL, *xbuff = NULL;
	int count = 0;

	linebuff = strtok(line, " ");
	if (!linebuff)
	{
		return (0);
	}
	xbuff = linebuff;
	xbuff = strtok(NULL, " ");
	if (xbuff != NULL)
	{
		first->n = atoi(xbuff);
		count = f_opcode_finder(stack, linebuff, counter);
	}
	else if (count != 1)
	{
		if (strcmp(linebuff, "push") == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			first->f_error_code = -1;
			return (-1);
		}
			count = f_opcode_finder(stack, linebuff, counter);
	}
	return (1);
}


/**
 * f_opcode_finder - Finds proper op-code
 * description: Compares opcode for correlating functions
 * @stack: Pointer to stack
 * @linebuff: line-buffer
 * @counter: Count for errors
 * Return: Always 0 (Success) or 1 on error
 */

int f_opcode_finder(stack_tt **stack, char *linebuff, unsigned int counter)
{
	int i;

	instruction_tt a[] = {
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
		for (i = 0; a[i].f; i++)
		{
			if (strcmp(linebuff, a[i].f_opcode) == 0)
			{
				a[i].f(stack, counter);
				return (1);
			}
			else if (linebuff[0] == '#')
			{
				a[11].f(stack, counter);
				return (1);
			}
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", counter, linebuff);
	first->f_error_code = -1;
	return (-1);
}
