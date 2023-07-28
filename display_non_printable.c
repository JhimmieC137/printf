#include "main.h"

/**
 * print_non_printable - displays characters ascii codes in hexa
 * @types: Argument List
 * @buffr: Container to be displayed
 * @curr_flags:  Derives amount of flags 
 * @prnt_len: Length of dat to be displayed
 * @precision: Sspecified precision 
 * @arg_sz_spf: size specifier
 * Return: Amount of characters printed successfully 
 */
int print_non_printable(va_list types, char buffr[],
	int curr_flags, int prnt_len, int precision, int arg_sz_spf)
{
	int z = 0, off = 0;
	char *words = va_arg(types, char *);

	UNUSED(curr_flags);
	UNUSED(prnt_len);
	UNUSED(precision);
	UNUSED(arg_sz_spf);

	if (words == NULL)
		return (write(1, "(null)", 6));

	while (words[z] != '\0')
	{
		if (is_printable(words[z]))
			buffr[z + off] = words[z];
		else
			off += append_hexa_code(words[z], buffr, z + off);

		z++;
	}

	buffr[z + off] = '\0';

	return (write(1, buffr, z + off));
}