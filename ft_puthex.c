/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaitihy <idaitihy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:02:15 by idaitihy          #+#    #+#             */
/*   Updated: 2026/11/21 13:02:22 by idaitihy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int a)
{
	char	*str;
	char	c;
	int		count;
	int		len;

	len = 0;
	str = "0123456789abcdef";
	count = 0;
	if (a >= 16)
	{
		count = ft_hex(a / 16);
		if (count < 0)
			return (-1);
		len = len + count;
	}
	c = str[a % 16];
	if (ft_putchar_fd(c, 1) < 0)
		return (-1);
	return (len + 1);
}
