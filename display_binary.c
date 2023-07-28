#include "main.h"

/**
 * print_binary - Converts to binary
 * @types: Argument List
 * @buffr: Container to be displayed 
 * @curr_flags:  Derives amount of flags 
 * @prnt_len: Length of dat to be displayed
 * @precision: Sspecified precision 
 * @arg_sz_spf: size specifier
 * Return: Amount of characters printed successfully 
 */

int print_binary(va_list types, char buffr[],
	int curr_flags, int prnt_len, int precision, int arg_sz_spf)
{
	unsigned int pl, s, f, total;
	unsigned int b[32];
	int iter;

	UNUSED(buffr);
	UNUSED(curr_flags);
	UNUSED(prnt_len);
	UNUSED(precision);
	UNUSED(arg_sz_spf);

	pl = va_arg(types, unsigned int);
	s = 2147483648;
	b[0] = pl / s;
	for (f = 1; f < 32; f++)
	{
		s /= 2;
		b[f] = (pl / s) % 2;
	}
	for (f = 0, total = 0, iter = 0; f < 32; f++)
	{
		total += b[f];
		if (total || f == 31)
		{
			char z = '0' + b[f];

			write(1, &z, 1);
			iter++;
		}
	}
	return (iter);
}
