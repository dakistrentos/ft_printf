#include "../ft_printf.h"

int	min_width_flag(char *flag, t_arg *arg)
{
	int	index;

	index = 0;
	arg->min_width_on = '1';
	arg->min_width = count_width(flag);
	while (ft_isdigit(*flag))
	{
		flag++;
		index++;
	}
	return (index);
}

int	asterisk_flag(char *flag, va_list list, t_arg *arg)
{
	flag--;
	if (*flag == '%' || *flag == '0' || *flag == '-')
	{
		arg->min_width_on = '1';
		arg->min_width = va_arg(list, int);
		if (arg->min_width < 0)
		{
			arg->minus_flag_on = '1';
			arg->min_width = arg->min_width * (-1);
		}
	}
	else if (*flag == '.')
	{
		arg->precision_on = '1';
		arg->precision = va_arg(list, int);
		if (arg->precision < 0)
		{
			arg->precision_minus = '1';
			arg->precision = arg->precision * (-1);
		}
	}
	return (1);
}

int	zero_flag(t_arg *arg)
{
	int	index;

	arg->zero_flag_on = '1';
	index = 1;
	return (index);
}

int	minus_flag(t_arg *arg)
{
	int	index;

	index = 1;
	arg->minus_flag_on = '1';
	return (index);
}
