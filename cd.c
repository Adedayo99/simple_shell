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
			*env = *dir;
		}

		else
		perror("./shell");

	}

	if (*arg == '-')
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


	if (arg != NULL)
	{
		char *env2;
		char buf[200];
		size_t n = 200;

		if (chdir(arg) == 0)
		{
			getcwd(buf, n);
			env2 = getenv("PWD");

			*env2 = *env;
		}

		else
		perror("./shell");
	}

	return (0);
}
