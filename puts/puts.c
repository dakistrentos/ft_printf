#include "../ft_printf.h"

void	putchar_count(char c, int fd)
{
	fd = 1;
	write(fd, &c, 1);
	printed_char_counter(1);
}

void	putstr_count(char *s, int fd)
{
	unsigned long int	len;

	fd = 1;
	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
	printed_char_counter(len);
}

static char	*conv_loop(unsigned long int num, int base, char c)
{
	char			buf[MAXBUF];	
	char			*result;
	char			*ret;
	size_t			len;

	len = 0;
	ret = (char *)malloc(MAXBUF);
	if (!ret)
		return (NULL);
	result = &buf[MAXBUF - 1];
	while (num != 0)
	{
		if (c == 'l')
			*result = DIGITSLO[num % base];
		else
			*result = DIGITSUP[num % base];
		result--;
		num /= base;
		len++;
	}
	ft_strlcpy(ret, result + 1, len + 1);
	return (ret);
}

char	*conv_base_str(unsigned long int num, int base, char c)
{
	char	*ret;

	if (num == 0)
	{
		ret = (char *)malloc(2);
		if (!ret)
			return (NULL);
		ft_strlcpy(ret, &ZERO[0], 2);
		return (ret);
	}
	else
		return (conv_loop(num, base, c));
}

char	*pointer_str(unsigned long int num)
{
	char			buf[MAXBUF];	
	char			*result;
	char			*ret;
	size_t			len;

	len = 0;
	result = &buf[MAXBUF - 1];
	ret = (char *)malloc(MAXBUF);
	ft_strlcpy(ret, &ZERO_X[0], 3);
	if (num == 0)
		ft_strlcpy(&ret[2], &ZERO[0], 2);
	else
	{
		while (num != 0)
		{
			*result = DIGITSLO[num % 16];
			result--;
			num /= 16;
			len++;
		}
		ft_strlcpy(ret + 2, result + 1, len + 1);
	}
	return (ret);
}
