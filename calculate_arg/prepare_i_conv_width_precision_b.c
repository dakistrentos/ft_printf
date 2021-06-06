#include "../ft_printf.h"

static char	*prec_bigger_len_plus(t_arg *arg, char *arg_string,
	int arg_string_len)
{
	char	*arg_string_prec;

	arg_string_prec = (char *)malloc(arg->precision + 1);
	ft_memset(arg_string_prec, '0', arg->precision - arg_string_len);
	ft_strlcpy(&arg_string_prec[arg->precision - arg_string_len],
		arg_string, arg_string_len + 1);
	return (arg_string_prec);
}

static char	*prec_smaller_or_equal_len_plus(t_arg *arg, char *arg_string,
	int arg_string_len)
{
	char	*arg_string_prec;

	arg_string_prec = (char *)malloc(arg->precision + 1);
	arg_string_prec[0] = '-';
	ft_memset(&arg_string_prec[1], '0', arg->precision - arg_string_len);
	ft_strlcpy(&arg_string_prec[arg->precision - arg_string_len + 1],
		&arg_string[1], arg_string_len + 1);
	return (arg_string_prec);
}

char	*prepare_precision(t_arg *arg, char *arg_string)
{
	char	*arg_string_prec;
	int		arg_string_len;

	arg_string_len = (int)ft_strlen(arg_string);
	if (ft_strchr(arg_string, '-'))
		arg_string_len--;
	if (arg->precision > arg_string_len && arg->precision != 0)
	{
		if (!ft_strchr(arg_string, '-'))
		{
			arg_string_prec = prec_bigger_len_plus(arg,
					arg_string, arg_string_len);
		}
		else
			arg_string_prec = prec_smaller_or_equal_len_plus(arg,
					arg_string, arg_string_len);
	}
	else
	{
		if (ft_strchr(arg_string, '-'))
			arg_string_len++;
		arg_string_prec = (char *)malloc(arg_string_len + 1);
		ft_strlcpy(arg_string_prec, arg_string, arg_string_len + 1);
	}
	return (arg_string_prec);
}
