#include "shell.h"

/**
* char_colon - function to check for chars
*@str: pointer to input string
*
* Return: pointer to array of strings or NULL
*/

char **char_colon(char *str)
{
	int i;
	char *token;
	int colon_count = 0;
	char *temp_str = NULL;
	char **strings = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == ';')
		colon_count++;
	}

	if (colon_count >= 1)
	{
		temp_str = malloc(sizeof(char) * (strlen(str) + 2));
		strcpy(temp_str, str);
		strcat(temp_str, ";");
	}

	if (temp_str != NULL)
	{
		strings = malloc(sizeof(char *) * (colon_count + 2));

		i = 0;
		token = strtok(str, ";");
		while (token != NULL)
		{
			strings[i] = malloc(sizeof(char) * strlen(token));
			strcpy(strings[i], token);
			token = strtok(NULL, ";");
			i++;
		}
		strings[i] = NULL;
	}

	// strings now contains seperate commands to be executed one by one

	return (strings);
}




/**
* char_hash - checks for # in string
*@str: input string
*
* Return: pointer to editted string
*/

char **char_hash(char *str)
{
	int i = 0;
	int flag = 0;
	char **strings = malloc(sizeof(char *) * 2);

	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			*str[i] = '\0';
			flag = 1;
		}
	}

	if (flag == 1)
	{
		strings[0] = malloc(sizeof(char) * (strlen(str) + 1));
		strcpy(strings[0], str);
		strings[1] = NULL;
	}

	return (strings);
	// string has been essentially truncated. we execute only until '\0' now
}




/**
* char_ampersand - checks for logical &&
*@str: pointer to input string
*
* Return: tokenized string commands for execution
*/

char **char_ampersand(char *str)
{
	int i = 0;
	int ampersand_count = 0;
	char *temp_str = NULL;
	char **strings = NULL;
	char *token = NULL;

	while (str[i] != '\0')
	{
		if (str[i] == '&' && str[i + 1] == '&')
		ampersand_count++;
		i++;
	}

	if (ampersand_count >= 1)
	{
		temp_str = malloc(sizeof(char) * (strlen(str) + 3));
		strcpy(temp_str, str);
		strcat(temp_str, "&&");
	}


	if (temp_str != NULL)
	{
		strings = malloc(sizeof(char *) * (ampersand_count + 2));
		
		i = 0;
		token = strtok(strings, "&&");
		while (token != NULL)
		{
			string[i] = malloc(sizeof(char) * strlen(token));
			strcpy(string[i], token);
			token = strtok(NULL, "&&");
			i++;
		}

		strings[i] = NULL;

	}

	// tokens now ready for stepwise conditional execution

	return (strings);
}




/**
* char_line - checks for logical OR
*@str: pointer to string input
*
* Return: pointer to sorted strings
*/
	
char **char_line(char *str)
{
	int i = 0;
	int line_count = 0;
	char *temp_str = NULL;
	char **strings = NULL;
	char *token = NULL;

	while (str[i] != '\0')
	{
		if (str[i] == '|' && str[i + 1] == '|')
		line_count++;
		i++;
	}

	if (line_count >= 1)
	{
		temp_str = malloc(sizeof(char) * (strlen(str) + 3));
		strcpy(temp_str, str);
		strcat(temp_str, "||");
	}


	if (temp_str != NULL)
	{
		strings = malloc(sizeof(char *) * (ampersand_count + 2));
		
		i = 0;
		token = strtok(strings, "||");
		while (token != NULL)
		{
			string[i] = malloc(sizeof(char) * strlen(token));
			strcpy(string[i], token);
			token = strtok(NULL, "||");
			i++;
		}

		strings[i] = NULL;

	}
	// all tokens ready to be run as commands

	return (strings);
}
