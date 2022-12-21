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
int executables_check(char *token);
int builtins_check(char *token);
void cmd_exec(char **argv, char *cmd_path);
char *get_path(char *cmd);
int myexit(int status);

extern char **environ;
int env_set(char *var, char *value);
int env(void);
int env_unset(char *var);
int cd(char *arg);
int char_executor(char **strings);
char **char_semicolon(char *str);
char **char_hash(char *str);
char **char_ampersand(char *str);
char **char_line(char *str);





#endif
