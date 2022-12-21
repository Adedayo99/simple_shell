/**
* cd - function to change directory
*@arg: input argument
*
* Return: int value for success
*/
#include "shell.h"

int cd(char *arg)
{
	char *dir;
	char *env;


	if (arg == NULL)
	{
		dir = getenv("HOME");
		if (chdir(dir) == 0)
		{
			env = getenv("PWD");
			env = dir;
		}

		else
		perror("./shell");

	}

	if (arg != NULL && strcmp(arg, "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (chdir(dir) == 0)
		{
			env = getenv("PWD");
			*env = *dir;
		}

		else
		perror("./shell");

	}


	if (arg != NULL && strlen(arg) > 1)
	{	
		char *env2;
		char buf[200];
		size_t n = 200;

		if (chdir(arg) == 0)
		{
			getcwd(buf, n);
			env2 = getenv("PWD");
			strcpy(env2, buf);
			*env2 = *buf; 
		}

		else
		perror("./shell");
	}


	return (0);
}
