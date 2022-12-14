This directory contains code aimed at implementing the functionality of a linux bash shell at basic level. Here is the basic break down of how it works:

Print prompt to user and recieve user input
Tokenize input
check if token[0] (command element in input) is valid
Get file path for command
Duplicate program process into parent and Child.
Parent process above will wait which child process executes command
If any special character is present, the program passes the input to a character check function to determine and implement the expected funtionality for the character
Afterwards, the prompt is printed again and the program loops back to beginning

The program is terminated when EOF is detected or any errors like invalid command, missing argument etc is encountered.
