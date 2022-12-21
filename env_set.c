/**
* env_set - set or modify environment variable
*@var: environment variable to add or modify
*@value: value to set variable to
* 
* Return: int value to indicate success
*/
#include "shell.h"

int env_set(char *var, char *value)
{
	int i;
	int len1, len2;
	int env_count = 0;
	char *temp_env = NULL;
	char **env = environ;
	char **temp;
	int flag = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], var, strlen(var)) == 0)
		{
			temp_env = getenv(var);
			*temp_env = *value;
		 	flag = 1;
		}
		env_count++;
	}

	if (flag == 0)
	{
		temp = malloc(sizeof(char *) * (env_count + 2));

		for (i = 0; environ[i] != NULL; i++)
		{
			temp[i] = malloc(sizeof(char) * strlen(environ[i]));
			strcpy(temp[i], environ[i]);
		}

		len1 = strlen(var);
		len2 = strlen(value);
		temp[i] = malloc(sizeof(char) *  (len1 + len2 + 2));
		strcpy(temp[i], var);
		strcat(temp[i], "=");
		strcat(temp[i], value);

		temp[i + 1] = NULL;
		env = temp;
	}

	environ = env;

	return (0);
}



/**
* env_unset - removes environment variable from list
*@var: variable to remove
*
* Return: int value for success
*/

int env_unset(char *var)
{
	int i;
	int flag = 0;
	int env_count = 0;
	char **temp_env = NULL;
	

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], var, strlen(var)) == 0)
		flag = 1;
		env_count++;
	}

	if (flag == 1)
	{
		temp_env = malloc(sizeof(char *) * env_count);

		i = 0;
		while (strncmp(environ[i], var, strlen(var)) != 0)
		{
			temp_env[i] = malloc(sizeof(char) * strlen(environ[i]));
			strcpy(temp_env[i], environ[i]);
			i++;
		}
		
		i++;
		while (environ[i] != NULL)
		{
			temp_env[i - 1] = malloc(sizeof(char) * strlen(environ[i]));
			strcpy(temp_env[i - 1], environ[i]);
			i++;
		}

		temp_env[i - 1] = NULL;

	}

	environ = temp_env;

	return (0);
}
