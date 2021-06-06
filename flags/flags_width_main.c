#include "../ft_printf.h"

int	count_width(char *flag)
{
	char	*str;
	char	*copy;
	int		i;

	i = 0;
	copy = flag;
	while (ft_isdigit(*flag) && *flag)
	{
		flag++;
		i++;
	}
	str = (char *)malloc(i + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, copy, i + 1);
	i = ft_atoi(str);
	free(str);
	return (i);
}

int	check_flag(char *flag, va_list list, t_arg *arg)
{
	int	found;

	found = 0;
	if (ft_isdigit(*flag) && *flag != '0')
		found = min_width_flag(flag, arg);
	else if (*flag == '0')
		found = zero_flag(arg);
	else if (*flag == '-')
	{
		flag++;
		if (ft_isdigit(*flag) || *flag == '*')
			found = minus_flag(arg);
		else
			found = 1;
	}
	else if (*flag == '*')
		found = asterisk_flag(flag, list, arg);
	else if (*flag == '.')
		found = precision_flag(flag, list, arg);
	return (found);
}
