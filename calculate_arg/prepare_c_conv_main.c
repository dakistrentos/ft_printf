#include "../ft_printf.h"

static void	prepare_c_conv_util_a(t_arg *arg)
{
	int	min_width;

	min_width = arg->min_width;
	while (min_width > 1)
	{
		putchar_count(' ', 1);
		min_width--;
	}
	putchar_count(arg->value, '1');
}

static void	prepare_c_conv_util_b(t_arg *arg)
{
	int	min_width;

	min_width = arg->min_width;
	putchar_count(arg->value, '1');
	while (min_width > 1)
	{
		putchar_count(' ', 1);
		min_width--;
	}
}

void	prepare_c_conv_main(t_arg *arg)
{
	if ((arg->min_width_on == '0') || (arg->min_width_on == '1'
			&& arg->min_width <= 1))
		putchar_count(arg->value, 1);
	else if (arg->min_width_on == '1' && arg->minus_flag_on == '0'
		&& arg->min_width > 1)
		prepare_c_conv_util_a(arg);
	else if (arg->min_width_on == '1' && arg->minus_flag_on == '1'
		&& arg->min_width > 1)
		prepare_c_conv_util_b(arg);
}
