#ifndef SHELL_H
#define SHELL_H

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * Function Declarations for builtin shell commands:
 */
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);
char **shell_split_line(char *line);
char *shell_read_line(void);
int shell_execute(char **args);
int shell_launch(char **args);
int shell_(char **args);
int shell_help(char **args);
int shell_cd(char **args);
int shell_num_builtins(void);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
