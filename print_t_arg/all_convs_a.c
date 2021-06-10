#include "../ft_printf.h"

void	d_conv(va_list list, t_arg *arg)
{
	char	*arg_string;

	arg_string = ft_itoa((int)va_arg(list, int));
	arg->arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
	ft_strlcpy(arg->arg_string, arg_string, ft_strlen(arg_string) + 1);
	free(arg_string);
}

void	s_conv(va_list list, t_arg *arg)
{
	char	*arg_string;

	arg_string = va_arg(list, char *);
	if (!arg_string)
	{
		arg->arg_string = (char *)malloc(ft_strlen(STR_NULL) + 1);
		ft_strlcpy(arg->arg_string, &STR_NULL[0], ft_strlen(STR_NULL) + 1);
	}
	else
	{
		arg->arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
		ft_strlcpy(arg->arg_string, arg_string, ft_strlen(arg_string) + 1);
	}
}

void	c_conv(va_list list, t_arg *arg)
{
	/* arg->arg_string = (char *)malloc(1);
	arg->arg_string[0] = '\0';

	arg->result_arg_string = (char *)malloc(1);
	arg->result_arg_string[0] = '\0'; */
	//arg->arg_string[0] = va_arg(list, int);
	//arg->arg_string[0] = '\0';
	//arg->value = arg->arg_string[0];
	arg->value = va_arg(list, int);
}

void	percentage_conv(t_arg *arg)
{
	arg->arg_string = (char *)malloc(2);
	arg->arg_string[0] = '%';
	arg->arg_string[1] = '\0';
}
