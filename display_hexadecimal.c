#include "main.h"

/**
 * print_hexadecimal - Display numbers  in hexadecimal notation
 * @types: Argument List
 * @buffr: Container to be displayed 
 * @curr_flags:  Derives amount of flags 
 * @prnt_len: Length of dat to be displayed
 * @precision: Sspecified precision 
 * @arg_sz_spf: size specifier
 * Return: Amount of characters printed successfully 
 */
int print_hexadecimal(va_list types, char buffr[],
	int curr_flags, int prnt_len, int precision, int arg_sz_spf)
{
	return (print_hexa(types, "0123456789abcdef", buffr,
		curr_flags, 'x', prnt_len, precision, arg_sz_spf));
}