#include <main.h>

/**
 * print_R13 - substitute %R by argument number in rot13
 * @buff_dest: string to change
 * @arg: va_list char to change
 * @buff_count: index of dst where the R of %R is
 * Return: New index
 */
int print_R13(char *buff_dest, va_list arg, int buff_count)
{
	char *str;
	char keys[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char keynew[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j;

	str = va_arg(arg, char *);
	for (j = 0; str[j]; j++)
	{
		if (isalpha(str[j]))
		{
			for (i = 0; keys[i]; i++)
			{
				if (str[j] == keys[i])
				{
					buff_dest[buff_count] = keynew[i];
					break;
				}
			}
			if (!keys[i])
			{
				buff_dest[buff_count] = str[j];
			}
		}
		else
		{
			buff_dest[buff_count] = str[j];
		}
		buff_count++;
	}

	return (buff_count);
}
