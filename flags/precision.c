#include "../ft_printf.h"

static int	precision_flag_ret(char *flag, va_list list, t_arg *arg, int index)
{
	if (ft_strchr(CONVS, *flag))
		arg->precision = 0;
	else if (*flag != '*' && ft_isdigit(*flag))
	{
		arg->precision = count_width(flag);
		while (ft_isdigit(*flag))
		{
			flag++;
			index++;
		}
	}
	else
	{	
		arg->precision = va_arg(list, int);
		if (arg->precision < 0 && *flag != '*')
		{
			arg->precision = arg->precision * (-1);
			arg->precision_minus = '1';
		}
		else if (arg->precision < 0 && *flag == '*')
			arg->precision_on = '0';
		index++;
	}
	return (index);
}

int	precision_flag(char *flag, va_list list, t_arg *arg)
{
	int	index;

	arg->precision_on = '1';
	index = 0;
	flag++;
	index++;
	return (precision_flag_ret(flag, list, arg, index));
}
