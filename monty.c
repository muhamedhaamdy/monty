#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

info_t info = INIT_INF;


/**
 * twoD_free - Frees the memory allocated for a 2D array
 */
void twoD_free(void)
{
	int i = 0;

	while (info.arr[i])
	{
		free(info.arr[i]);
		i++;
	}
	free(info.arr);
}

/**
 * main - entry point
 * @ac: the number of arguments
 * @av: the arguments
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	char *line;
	int tokns_num;

	info.file = fopen(av[1], "r");
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!info.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		tokns_num = preprocess(&line, info.file);
		info.arr = array_of_tokns(line, tokns_num);
		info.line_num++;
		if (info.arr == NULL)
			continue;
		free(line);
		exe_func(info.arr);
		twoD_free();
	}
	fclose(info.file);
}
