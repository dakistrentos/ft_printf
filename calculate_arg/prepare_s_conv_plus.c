#include "../ft_printf.h"

void	prepare_s_conv_plus_util_a(t_arg *arg, char *arg_string)
{
	if (arg->precision <= (int)ft_strlen(arg_string)
		&& arg->precision < arg->min_width)
	{	
		if (arg->minus_flag_on == '1')
		{
			arg->result_arg_string = (char *)malloc(arg->min_width + 1);
			ft_strlcpy(arg->result_arg_string, arg_string, arg->precision + 1);
			ft_memset(&arg->result_arg_string[arg->precision], ' ',
				arg->min_width - arg->precision);
			arg->result_arg_string[arg->min_width] = '\0';
		}
		else if (arg->minus_flag_on == '0')
		{
			arg->result_arg_string = (char *)malloc(arg->min_width + 1);
			ft_memset(arg->result_arg_string, ' ',
				arg->min_width - arg->precision);
			ft_strlcpy(&arg->result_arg_string[arg->min_width - arg->precision],
				arg_string, arg->precision + 1);
		}
	}
	else
	{
		arg->result_arg_string = (char *)malloc(arg->precision + 1);
		ft_strlcpy(arg->result_arg_string, arg_string, arg->precision + 1);
	}
}

void	prepare_s_conv_plus_util_b(t_arg *arg, char *arg_string)
{
	if (arg->minus_flag_on == '0')
	{				
		arg->result_arg_string = (char *)malloc(arg->min_width + 1);
		ft_memset(arg->result_arg_string, ' ',
			arg->min_width - ft_strlen(arg_string));
		ft_strlcpy(&arg->result_arg_string[arg->min_width
			- ft_strlen(arg_string)], arg_string,
			ft_strlen(arg_string) + 1);
	}
	else if (arg->minus_flag_on == '1')
	{
		arg->result_arg_string = (char *)malloc(arg->min_width + 1);
		ft_strlcpy(arg->result_arg_string, arg_string,
			ft_strlen(arg_string) + 1);
		ft_memset(&arg->result_arg_string[ft_strlen(arg_string)],
			' ', arg->min_width - (int)ft_strlen(arg_string));
		arg->result_arg_string[arg->min_width] = '\0';
	}
}

void	prepare_s_conv_plus_util_c(t_arg *arg, char *arg_string)
{
	if (arg->precision >= (int)ft_strlen(arg_string))
	{
		arg->result_arg_string = (char *)malloc(arg->min_width + 1);
		ft_memset(arg->result_arg_string, ' ',
			arg->min_width - ft_strlen(arg_string));
		ft_strlcpy(&arg->result_arg_string[arg->min_width
			- ft_strlen(arg_string)], arg_string,
			ft_strlen(arg_string) + 1);
	}
	else if (arg->precision < (int)ft_strlen(arg_string))
	{
		arg->result_arg_string = (char *)malloc(arg->min_width + 1);
		ft_memset(arg->result_arg_string, ' ',
			arg->min_width - arg->precision);
		ft_strlcpy(&arg->result_arg_string[arg->min_width
			- arg->precision], arg_string, arg->precision + 1);
	}
}

void	prepare_s_conv_plus_util_d(t_arg *arg, char *arg_string)
{
	if (arg->precision >= (int)ft_strlen(arg_string))
	{
		arg->result_arg_string = (char *)malloc(arg->min_width + 1);
		ft_strlcpy(arg->result_arg_string,
			arg_string, ft_strlen(arg_string) + 1);
		ft_memset(&arg->result_arg_string[ft_strlen(arg_string)],
			' ', arg->min_width - (int)ft_strlen(arg_string));
		arg->result_arg_string[arg->min_width] = '\0';
	}
	else if (arg->precision < (int)ft_strlen(arg_string))
	{
		arg->result_arg_string = (char *)malloc(arg->min_width + 1);
		ft_strlcpy(arg->result_arg_string, arg_string, arg->precision + 1);
		ft_memset(&arg->result_arg_string[arg->precision],
			' ', arg->min_width - arg->precision);
		arg->result_arg_string[arg->min_width] = '\0';
	}
}

void	prepare_s_conv_plus(t_arg *arg, char *arg_string)
{
	if (arg->min_width_on == '1')
		prepare_s_conv_plus_util(arg, arg_string);
	else if (arg->min_width_on == '0')
	{
		arg->result_arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
		ft_strlcpy(arg->result_arg_string, arg_string,
			ft_strlen(arg_string) + 1);
	}
}
