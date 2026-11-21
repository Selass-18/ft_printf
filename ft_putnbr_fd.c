/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaitihy <idaitihy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 20:24:24 by idaitihy          #+#    #+#             */
/*   Updated: 2026/11/21 10:24:24 by idaitihy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;
	int		len;
	int		tmp;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		if (write(fd, "-", 1) != 1)
			return (-1);
		nb = -nb;
		len++;
	}
	if (nb >= 10)
	{
		tmp = ft_putnbr_fd(nb / 10, fd);
		if (tmp < 0)
			return (-1);
		len += tmp;
	}
	c = (nb % 10) + '0';
	if (write(fd, &c, 1) != 1)
		return (-1);
	return (len + 1);
}
