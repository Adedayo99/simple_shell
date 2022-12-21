/**
* env_set - set or modify environment variable
*@var: environment variable to add or modify
*@value: value to set variable to
* 
* Return: int value to indicate success
*/

int env_set(char *var, char *value)
{
	int i;
	int env_count = 0;
	char *temp_env = NULL;
	char **env = environ;



	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], var, strlen(var)) == 0)
		{
			temp_env = getenv(var);
			*env[i] = *temp_env;
		 	flag = 1;
		}
		env_count++;
	}

	if (flag == 0)
	{
		env = malloc(sizeof(char *) * (env_count + 2));

		for (i = 0; environ[i] != NULL; i++)
		{
			env[i] = malloc(sizeof(char) * strlen(environ[i]));
			strcpy(env[i], environ[i]);
		}

		

		env[i] = malloc(sizeof(char) *  
