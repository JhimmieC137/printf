#include "main.h"

/**
 * print_pointer - Display pointer values
 * @types: Argument List
 * @buffr: Container to be displayed
 * @curr_flags:  Derives amount of flags 
 * @prnt_len: Length of dat to be displayed
 * @precision: Sspecified precision 
 * @arg_sz_spf: size specifier
 * Return: Amount of characters printed successfully 
 */
int print_pointer(va_list types, char buffr[],
	int curr_flags, int prnt_len, int precision, int arg_sz_spf)
{
	char ext_m = 0, dapp = ' ';
	int tel = BUFF_SIZE - 2, len = 2, dapp_strt = 1;
	unsigned long int_loc;
	char trace[] = "0123456789abcdef";
	void *loc = va_arg(types, void *);

	UNUSED(prnt_len);
	UNUSED(arg_sz_spf);

	if (loc == NULL)
		return (write(1, "(nil)", 5));

	buffr[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	int_loc = (unsigned long)loc;

	while (int_loc > 0)
	{
		buffr[tel--] = trace[int_loc % 16];
		int_loc /= 16;
		len++;
	}

	if ((curr_flags & F_ZERO) && !(curr_flags & F_MINUS))
		dapp = '0';
	if (curr_flags & F_PLUS)
		ext_m = '+', len++;
	else if (curr_flags & F_SPACE)
		ext_m = ' ', len++;

	tel++;

	return (write_pointer(buffr, tel, len,
		prnt_len, curr_flags, dapp, ext_m, dapp_strt));
}