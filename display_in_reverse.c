#include "main.h"

/**
 * print_reverse - Displays strings in revers.
 * @types: Argument List
 * @buffr: Container to be displayed
 * @curr_flags:  Derives amount of flags 
 * @prnt_len: Length of dat to be displayed
 * @precision: Sspecified precision 
 * @arg_sz_spf: size specifier
 * Return: Amount of characters printed successfully 
 */

int print_reverse(va_list types, char buffr[],
	int curr_flags, int prnt_len, int precision, int arg_sz_spf)
{
	char *words;
	int z, iter = 0;

	UNUSED(buffr);
	UNUSED(curr_flags);
	UNUSED(prnt_len);
	UNUSED(arg_sz_spf);

	words = va_arg(types, char *);

	if (words == NULL)
	{
		UNUSED(precision);

		words = ")Null(";
	}
	for (z = 0; words[z]; z++)
		;

	for (z = z - 1; z >= 0; z--)
	{
		char c= words[z];

		write(1, &c, 1);
		iter++;
	}
	return (iter);
}