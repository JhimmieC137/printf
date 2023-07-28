#include "main.h"

/**
 * print_char - Displays a character
 * @types: Argument List
 * @buffr: Container to be displayed 
 * @curr_flags:  Derives amount of flags 
 * @prnt_len: Length of dat to be displayed
 * @precision: Sspecified precision 
 * @arg_sz_spf: Size specifier
 * Return: Amount of characters printed successfully 
 */
int print_char(va_list types, char buffr[],
	int curr_flags, int prnt_len, int precision, int arg_sz_spf)
{
	char v = va_arg(types, int);

	return (handle_write_char(v, buffr, curr_flags, prnt_len, precision, arg_sz_spf));
}