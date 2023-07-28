#include "main.h"

/**
 * print_percent - Displays integers 
 * @types: Argument List
 * @buffr: Container to be displayed 
 * @curr_flags:  Derives amount of flags 
 * @prnt_len: Length of dat to be displayed
 * @precision: Sspecified precision 
 * @arg_sz_spf: size specifier
 * Return: Amount of characters printed successfully 
 */
int print_int(va_list types, char buffr[],
	int curr_flags, int prnt_len, int precision, int arg_sz_spf)
{
	int z = BUFF_SIZE - 2;
	int neg_int = 0;
	long int ln = va_arg(types, long int);
	unsigned long int pos_int;

	ln = convert_size_number(ln, arg_sz_spf);

	if (ln == 0)
		buffr[z--] = '0';

	buffr[BUFF_SIZE - 1] = '\0';
	pos_int = (unsigned long int)ln;

	if (ln < 0)
	{
		pos_int = (unsigned long int)((-1) * ln);
		neg_int = 1;
	}

	while (pos_int > 0)
	{
		buffr[z--] = (pos_int % 10) + '0';
		pos_int /= 10;
	}

	z++;

	return (write_number(neg_int, z, buffr, curr_flags, prnt_len, precision, arg_sz_spf));
}