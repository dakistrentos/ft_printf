#include "../ft_printf.h"

void 	check_type_copy(char conv, va_list list, t_arg *arg)
{
	if (conv == 'd' || conv == 'i')
		d_conv(list, arg);
	else if (conv == 's')
		s_conv(list, arg);
	else if (conv == 'c')
		c_conv(list, arg);
	else if (conv == 'x')
		x_conv(list, arg);
	else if (conv == 'X')
		u_x_conv(list, arg);
	else if (conv == 'p')
		p_conv(list, arg);
	else if (conv == 'u')
		u_conv(list, arg);
	else if (conv == '%')
		percentage_conv(arg);
}

void	print_t_arg(t_arg *arg, char *index)
{
	arg->type = *index;
	calculate_arg(arg);
	if (arg->type == 'c')
	{
		prepare_c_conv_main(arg);
		init_arg(arg);
	}
	else if (arg->type != 'c')
	{
		putstr_count(arg->result_arg_string, 1);
		if (arg->arg_string)
			free(arg->arg_string);
		if (arg->result_arg_string)
			free(arg->result_arg_string);
		init_arg(arg);
	}
}
