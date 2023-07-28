#include "main.h"


/**
 * print_octal - Display octal notation of a positive integer
 * @types: Argument List
 * @buffr: Container to be displayed 
 * @curr_flags:  Derives amount of flags 
 * @prnt_len: Length of dat to be displayed
 * @precision: Sspecified precision 
 * @arg_sz_spf: size specifier
 * Return: Amount of characters printed successfully 
 */

int print_octal(va_list types, char buffr[],
	int curr_flags, int prnt_len, int precision, int arg_sz_spf)
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
		buffr[z--] = (iter % 8) + '0';
		iter /= 8;
	}

	if (curr_flags & F_HASH && init_val != 0)
		buffr[z--] = '0';

	z++;

	return (write_unsgnd(0, z, buffr, curr_flags, prnt_len, precision, arg_sz_spf));
}