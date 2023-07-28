#include "main.h"

/**
 * print_percent - Displays the percent character 
 * @types: Argument List
 * @buffr: Container to be displayed 
 * @curr_flags:  Derives amount of flags 
 * @prnt_len: Length of dat to be displayed
 * @precision: Sspecified precision 
 * @arg_sz_spf: Size specifier
 * Return: Amount of characters printed successfully 
 */

int print_percent(va_list types, char buffr[],
	int curr_flags, int prnt_len, int precision, int arg_sz_spf)
{
	UNUSED(types);
	UNUSED(buffr);
	UNUSED(curr_flags);
	UNUSED(prnt_len);
	UNUSED(precision);
	UNUSED(arg_sz_spf);
	return (write(1, "%%", 1));
}