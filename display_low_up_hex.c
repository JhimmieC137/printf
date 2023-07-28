#include "main.h"

/**
 * print_hexa - Diaplays integers as hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @tracer: Array of values to map the number to
 * @buffr: Buffer array to handle print
 * @curr_flags:  Calculates active flags
 * @chr_flgs: Calculates active flags
 * @prnt_len: get width
 * @precision: Precision specification
 * @arg_sz_spf: Size specifier
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char tracer[], char buffr[],
	int flags, char chr_flgs, int prnt_len, int precision, int arg_sz_spf)
{
	int z = BUFF_SIZE - 2;
	unsigned long int iter = va_arg(types, unsigned long int);
	unsigned long int init_val = iter;

	UNUSED(prnt_len);

	iter = convert_size_unsgnd(iter, arg_sz_spf);

	if (iter == 0)
		buffr[z--] = '0';

	buffr[BUFF_SIZE - 1] = '\0';

	while (iter > 0)
	{
		buffr[z--] = tracer[iter % 16];
		iter /= 16;
	}

	if (flags & F_HASH && init_val != 0)
	{
		buffr[z--] = chr_flgs;
		buffr[z--] = '0';
	}

	z++;

	return (write_unsgnd(0, z, buffr, flags, prnt_len, precision, arg_sz_spf));
}
