#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
* spec_C - to print the c character
* @c: the character to be printed
* Return: 1
*/
int spec_C(char c)
{
	write(1, &c, 1);
	return (1);
}
/**
* spec_S - to print the string character
* @str: the variadic string
* Return: string length of str
*/
int spec_S(char *str)
{
	if (str == NULL)
	{
		return (0);
	}
	write(1, str, strlen(str));
	return (strlen(str));
}
