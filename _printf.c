#include "main.h"

void print_buffer(char buffr[], int *buffr_itb);

/**
 * _printf - Works just like the printf function
 * 
 * @format: pointer to characters
 * Return: 0 on Success
 */

int _printf(const char *format, ...)
{
	int z, displayed = 0, num_prntd_chars = 0;
	int num_curr_flags, prnt_length, precision, arg_sz, buffr_itb = 0;
	va_list ap;
	char buffr[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	for (z = 0; format && format[z] != '\0'; z++)
	{
		if (format[z] != '%')
		{
			buffr[buffr_itb++] = format[z];
			if (buffr_itb == BUFF_SIZE)
				print_buffer(buffr, &buffr_itb);
			/* write(1, &format[z], 1);*/
			num_prntd_chars++;
		}
		else
		{
			print_buffer(buffr, &buffr_itb);
			num_curr_flags = get_flags(format, &z);
			prnt_length = get_width(format, &z, ap);
			precision = get_precision(format, &z, ap);
			arg_sz = get_size(format, &z);
			++z;
			displayed = handle_print(format, &z, ap, buffr,
				num_curr_flags, prnt_length, precision, arg_sz);
			if (displayed == -1)
				return (-1);
			num_prntd_chars += displayed;
		}
	}

	print_buffer(buffr, &buffr_itb);

	va_end(ap);

	return (num_prntd_chars);
}

/**
 * print_buffer - it displays any content availabele in the buffer
 *
 * @buffr: List of characters
 * @buffr_itb: Iteration to add next character.
 *
 * Return: Void
 */

void print_buffer(char buffr[], int *buffr_itb)
{
	if (*buffr_itb > 0)
		write(1, &buffr[0], *buffr_itb);

	*buffr_itb = 0;
}
