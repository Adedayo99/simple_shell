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
		chdir(dir);
		env = getenv("PWD");
		env = dir;
	}

	if (arg != NULL && strcmp(arg, "-") == 0)
	{
		dir = getenv("OLDPWD");
		chdir(dir);
		env = getenv("PWD");
		*env = *dir;
	}

	if (arg != NULL && strlen(arg) > 1)
	{	
		char *env2;
		char buf[200];
		size_t n = 200;

		chdir(arg);
		
		getcwd(buf, n);
		env2 = getenv("PWD");
		strcpy(env2, buf);
		*env2 = *buf; 
	}
	
	return (0);
}
