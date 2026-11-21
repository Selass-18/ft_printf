/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsi_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaitihy <idaitihy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:17:35 by idaitihy          #+#    #+#             */
/*   Updated: 2026/11/21 10:24:31 by idaitihy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsi_putnbr_fd(unsigned int n, int fd)
{
	char	c;
	int		ret;
	int		len;

	len = 0;
	if (n >= 10)
	{
		ret = ft_unsi_putnbr_fd(n / 10, fd);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	c = (n % 10) + '0';
	if (write(fd, &c, 1) != 1)
		return (-1);
	len++;
	return (len);
}
