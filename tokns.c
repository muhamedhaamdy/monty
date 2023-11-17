#include "monty.h"

/**
 * array_of_tokns - this function returns the number of tokens in a string
 *
 * @comm: the string to be tokenized
 * @token_num: the number of tokens
 * Return: the number of tokens in the string
 */

char **array_of_tokns(char *comm, int token_num)
{
	char *tkn;
	char **arr;
	int i = 0, j;

	tkn = strtok(comm, " \t\n");
	if (tkn == NULL)
	{
		free(tkn);
		return (NULL);
	}
	else
		arr = malloc(sizeof(char *) * (token_num + 1));
	while (tkn)
	{
		arr[i] = malloc(strlen(tkn) + 1);
		if (!arr[i])
		{
			for (j = 0; j < i; j++)
				free(arr[j]);
			free(arr);
			perror("cannot allocate memory");
			exit(0);
		}
		strcpy(arr[i], tkn);
		i++;
		tkn = strtok(NULL, " \t\n");
	}
	arr[i] = NULL;
	free(tkn);
	return (arr);
}