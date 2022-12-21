#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>

char **tokenizer(char *buf);
int cmd_check(char *token);
void cmd_exec(char **argv, char *cmd_path);
char *get_path(char *cmd);
void exit(int status);

extern char **environ;
int env_set(char *var, char *value);
int env(void);
int env_unset(char *var);
int cd(char *arg);

typedef struct builtins{
	char *name;
	int(*func)(char *arg);
	} built_t;


#endif
