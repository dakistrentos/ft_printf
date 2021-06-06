#include "../ft_printf.h"

void	x_conv(va_list list, t_arg *arg)
{
	char	*arg_string;

	arg->type = 'x';
	arg_string = conv_base_str((unsigned int)va_arg(list, int), 16, 'l');
	arg->arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
	ft_strlcpy(arg->arg_string, arg_string, ft_strlen(arg_string) + 1);
	free(arg_string);
}

void	u_x_conv(va_list list, t_arg *arg)
{
	char	*arg_string;

	arg->type = 'X';
	arg_string = conv_base_str((unsigned int)va_arg(list, int), 16, 'U');
	arg->arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
	ft_strlcpy(arg->arg_string, arg_string, ft_strlen(arg_string) + 1);
	free(arg_string);
}

void	p_conv(va_list list, t_arg *arg)
{
	char	*arg_string;

	arg->type = 'p';
	arg_string = pointer_str((unsigned long int)va_arg(list, void (*)));
	arg->arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
	ft_strlcpy(arg->arg_string, arg_string, ft_strlen(arg_string) + 1);
	free(arg_string);
}

void	u_conv(va_list list, t_arg *arg)
{
	char	*arg_string;

	arg->type = 'u';
	arg_string = conv_base_str((unsigned long int)va_arg(list, unsigned int),
			10, 'l');
	arg->arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
	ft_strlcpy(arg->arg_string, arg_string, ft_strlen(arg_string) + 1);
	free(arg_string);
}
