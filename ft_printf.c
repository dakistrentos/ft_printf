#include "ft_printf.h"

int	printed_char_counter(int add)
{
	static int	counter = 0;

	counter = counter + add;
	return (counter);
}

static void	check_print(char *index, va_list list, t_arg *arg)
{
	check_type_copy(*index, list, arg);
	print_t_arg(arg, index);
}

void	string_reader(char *str, va_list list, t_arg *arg)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr((const char *)FLAGS, str[i]))
			{
				while (ft_strchr((const char *)FLAGS, str[i]))
					i = i + check_flag(&str[i], list, arg);
				if (str[i] == '$')
					i++;
				check_print(&str[i], list, arg);
			}
			else
				check_print(&str[i], list, arg);
		}
		else
			putchar_count(str[i], 1);
		i++;
	}
}

void 	init_arg(t_arg *arg)
{
	arg->min_width_on = '0';
	arg->minus_flag_on = '0';
	arg->precision_on = '0';
	arg->zero_flag_on = '0';
	arg->precision_minus = '0';
}

int	ft_printf(const char *str, ...)
{
	va_list		list;
	t_arg		*arg_ptr;
	t_arg		arg;
	int			result;

	arg_ptr = &arg;
	if (!str)
		return (0);
	va_start(list, str);
	init_arg(arg_ptr);
	string_reader((char *)str, list, arg_ptr);
	va_end(list);
	result = printed_char_counter(0);
	printed_char_counter(result * (-1));
	return (result);
}
