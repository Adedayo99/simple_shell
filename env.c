/**
* env - displays environment
*@void: no input
*
* Return: int value for success
*/
#include "shell.h"

int env(void)
{

	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, (const void *) environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (0);
}
