#define _POSIX_C_SOURCE 200809L

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * number_fo_tokns - this function returns the number of tokens in a string
 *
 * @commcpy: the string to be tokenized
 * Return: the number of tokens in the string
 */
int number_fo_tokns(char *commcpy)
{
	char *tkn = strtok(commcpy, " \t\n");
	int token_num = 0;

	while (tkn)
	{
		token_num++;
		tkn = strtok(NULL, " \t\n");
	}
	free(tkn);
	free(commcpy);
	return (token_num);
}
/**
 * check_EOF - check for end of file condition
 *
 * @n : the size of line
 * @command : the string that should be freed
*/
void check_EOF(size_t n, char *command)
{
	if ((int)n == -1)
	{
		free(command);
		fclose(info.file);
		exit(0);
	}
}

/**
 * preprocess - this function returns the number of tokens in a string
 *
 * @commcpy: the string to be tokenized
 * @file: the file to be reads
 * Return: the number of tokens in the string
 */
int preprocess(char **commcpy, FILE *file)
{
	ssize_t read;
	size_t letters = 0;
	char *command = NULL;

	read = getline(&command, &letters, file);
	check_EOF(read, command);
	*commcpy = malloc(sizeof(char) * (strlen(command) + 1));
	strcpy(*commcpy, command);
	if (!*commcpy)
	{
		perror("cannot allocate memory\n");
		free(command);
		free(*commcpy);
		exit(0);
	}
	return (number_fo_tokns(command));
}
