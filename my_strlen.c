/*
** EPITECH PROJECT, 2017
** Library
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}
