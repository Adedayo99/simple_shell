/**
* myexit - terminates the shell program
*@status: return value to parent
*
* Return: void
*/
#include "shell.h"

void myexit(int status)
{
	int i;

	fflush(stdin);
	fflush(NULL);

	for (i = 0; i < 4; i++)
	close(i);

	_exit(status);

}
