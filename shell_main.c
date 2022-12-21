/**
* shell_main - mother function for simple shell
*@void: no inputs
*
* Return: int value for success
*/
#include "shell.h"

int main(void)
{
	int val, i, fork_val;
	char *buf = NULL;
	size_t n = 0;
	char **argv = NULL;
	char *cmd_path = NULL;
	char **cmd_array = NULL;
	
	while (1)
	{
		write(STDOUT_FILENO,"($)", 3);
		val = getline(&buf,&n, stdin);
		buf[val - 1] = ' ';
		
		if (val == -1)
		return (-1);

		i = 0;
		while (buf[i] == ' ')
		{
			buf[i] = '\0';
			i++;
		}
		buf = &buf[i];

		if (char_semicolon(buf))		
		{
			cmd_array = char_semicolon(buf);
			char_executor(cmd_array);
		}
		if (char_hash(buf))		
		{
			cmd_array = char_hash(buf);
			char_executor(cmd_array);
		}

		if (char_ampersand(buf))		
		{
			cmd_array = char_ampersand(buf);
			char_executor(cmd_array);
		}

		if (char_line(buf))		
		{
			cmd_array = char_line(buf);
			char_executor(cmd_array);
		}


		argv = tokenizer(buf);
		

		if (executables_check(argv[0]) == 0)
		{
			fork_val = fork();

			if (fork_val == 0)
			{
				cmd_path = get_path(argv[0]);
				cmd_exec(argv, cmd_path);
			}

			else
			wait(NULL);
		}


		if (builtins_check(argv[0]) == 0)
		{
			if (strcmp(argv[0], "setenv") == 0)
			env_set(argv[1], argv[2]);

			if (strcmp(argv[0], "unsetenv") == 0)
			env_unset(argv[1]);

			if (strcmp(argv[0], "env") == 0)
			env();

			if (strcmp(argv[0] , "exit") == 0 && argv[1] == NULL)
			myexit(1000);

			if (strcmp(argv[0], "exit") == 0 && argv[1] != NULL)
			myexit((int) *argv[1]);

			if (strcmp(argv[0], "cd") == 0)
			cd(argv[1]);
		}
			


/*		else
		{
			errno = 
			perror("./shell");
*/
	}

	return (0);

}


/**
* executables_check - to check if command is valid
*@token: first token from input
*
* Return: 0 to indicate executable present
*/

int executables_check(char *token)
{
	int flag = 1;
	int i = 0;
	char *args[] = {"ls", "touch", "pwd", "rm", "echo", "cat", NULL};

	while (args[i] != NULL)
	{
		flag = strcmp(args[i], token);

		if (flag == 0)
		return (flag);

		i++;
	}

	return (flag);
}


/**
* builtins_check - to check if command is valid
*@token: first token from input
*
* Return: 0 to indicate builtin present
*/

int builtins_check(char *token)
{
	int flag = 1;
	int i = 0;
	char *args[] = {"env", "exit", "setenv", "unsetenv", "cd", NULL};

	while (args[i] != NULL)
	{
		flag = strcmp(args[i], token);

		if (flag == 0)
		return (flag);

		i++;
	}

	return (flag);
}
