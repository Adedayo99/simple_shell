/**
* char_executor - runs commands given with special characters
*@strings: pointer to array of commands
*
* int value for success
*/
#include "shell.h"

int char_executor(char **strings)
{
	int i;
	char **args;
	int fork_val;
	char *cmd_path;

	for (i = 0; strings[i] != NULL; i++)
	{
		args = tokenizer(strings[i]);
		if (executables_check(args[0]) == 0)
		{
			fork_val = fork();

			if (fork_val == 0)
			{
				cmd_path = get_path(args[0]);
				cmd_exec(args, cmd_path);
			}

			else
			wait(NULL);
		}

		
		if (builtins_check(args[0]) == 0)
		{
			if (strcmp(args[0], "setenv") == 0)
			env_set(args[1], args[2]);

			if (strcmp(strings[i], "unsetenv") == 0)
			env_unset(args[1]);
			
			if (strcmp(strings[i], "env") == 0)
			env();

			if (strcmp(strings[i], "cd") == 0)
			cd(args[1]);
		}

	}

	return (0);

}
