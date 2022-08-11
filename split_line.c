#include "shell.h"
#define SHELL_TOK_BUFSIZE 64
#define SHELL_TOK_DELIM " \t\r\n\a"
/**
 * **shell_split_line -  Split a line into tokens (very naively).
 * @line: String input from stdin.
 * Return: Null-terminated array of tokens.
 */
char **shell_split_line(char *line)
{
	int bufsize = SHELL_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		write(1, "shell: allocation error\n", 26);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, SHELL_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

	if (position >= bufsize)
	{
		bufsize += SHELL_TOK_BUFSIZE;
		tokens_backup = tokens;
		tokens = realloc(tokens, bufsize * sizeof(char *));
		if (!tokens)
		{
			free(tokens_backup);
			write(1, "shell: allocation error\n", 26);
			exit(EXIT_FAILURE);
		}
	}

	token = strtok(NULL, SHELL_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
