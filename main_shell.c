#include "shell.h"
char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};
int (*builtin_func[]) (char **) = {
	&shell_cd,
	&shell_help,
	&shell_exit
};

/**
 * main - main shell function
 * Return: Exit Success
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		write(1, "$ ", 2);
		line = shell_read_line();
		args = shell_split_line(line);
		status = shell_execute(args);

		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}

/**
  * shell_execute - Execute shell built-in or launch program.
  * @args: Null terminated list of arguments.
  * Return: 1 if the shell should continue running, 0 if terminat
  */
int shell_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	/* An empty command was entered. */
	return (1);

	for (i = 0; i < shell_num_builtins(); i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	return (shell_launch(args));
}

/**
 * shell_num_builtins - Builtin command: .
 * Return: Always returns 0, to terminate execution.
 */
int shell_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}
