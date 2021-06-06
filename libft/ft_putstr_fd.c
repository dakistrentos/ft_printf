/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 10:07:15 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/05/17 18:21:47 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	unsigned long int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}
