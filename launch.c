#include "shell.h"
/**
  * shell_launch - Launch a program and wait for it to terminate.
  * @args: Null terminated list of arguments (including program)
  * Return: Always returns 1, to continue execution.
  */
int shell_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	/* Child process */
		if (execve(args[0], args, NULL) == -1)
			perror("./shell");
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	/* Error forking */
		perror("./shell");
	else
	{
	/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
