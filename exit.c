/**
* exit - terminates the shell program
*@status: return value to parent
*
* Return: void
*/
#include "shell.h"

int myexit(int status)
{
	int i;

	fflush(stdin);
	fflush(NULL);

	for (i = 0; i < 4; i++)
	close(i);

	if (status == 1000)
	_exit;

	else
	_exit(status);

	return (status);
}
