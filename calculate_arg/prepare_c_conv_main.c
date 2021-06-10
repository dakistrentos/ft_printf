#include "ft_printf.h"

void	prepare_c_conv_main(t_arg *arg)
{
	int min_width;

	if (arg->min_width_on == '0' || (arg->min_width_on == '1' 
		&& arg->min_width == 1))
		putchar_count(arg->value, 1);
	else if (arg->min_width_on == '1' && arg->minus_flag_on == '0'
		&& arg->min_width > 1)
	{
		min_width = arg->min_width;
		while (min_width > 1)
		{
			putchar_count(' ', 1);
			min_width--;
		}
		putchar_count(arg->value, '1');	
	}
	else if (arg->min_width_on == '1' && arg->minus_flag_on == '1'
		&& arg->min_width > 1)
	{
		min_width = arg->min_width;
		putchar_count(arg->value, '1');
		while (min_width > 1)
		{
			putchar_count(' ', 1);
			min_width--;
		}
	}
}