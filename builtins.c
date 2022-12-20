/**
* cmd_func - function to select appropriatr builtin to run
*@name: input
*
* Return: pointer to appropriate function
*/
#include "shell.h"

int (*cmd_func(char *name))(char *)
{
	int i = 0;

	built_t cmds[] = {
		{"cd", cd},
		{"setenv", env_set},
		{"unsetenv", env_unset},
		{'0', NULL}
		};


	while (cmds[i].name != '0')
	{
		if (cmds[i].name == name)
		return (cmds[i].func);

		i++;
	}

	return (NULL);

}
