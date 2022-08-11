#include "shell.h"
/**
 * shell_cd - Bultin command change directory.
 * @args: List of args.  args[0] is "cd".  args[1] is the directory
 * Return: Always returns 1, to continue executing.
 */
int shell_cd(char **args)
{
	if (args[1] == NULL)
		write(1, "./shell: expected argument to \"cd\"\n", 35);
	else
	{
		if (chdir(args[1]) != 0)
			perror("./shell");
	}
	return (1);
}

/**
 * shell_help - Builtin command: print help.
 * @args: List of args.  Not examined.
 * Return: Always returns 1, to continue executing.
 */
int shell_help(char **args)
{
	write(1, "Simple Shell\n", 13);
	write(1, "Type help followed by arguments, and hit enter.\n", 62);
	write(1, "Use the man command for information on other programs.\n", 55);
	return (1);
}

/**
 * shell_exit - Builtin command: .
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int shell_exit(char **args)
{
	return (0);
}
