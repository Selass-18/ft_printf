/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaitihy <idaitihy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:02:15 by idaitihy          #+#    #+#             */
/*   Updated: 2026/11/21 13:15:23 by idaitihy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uhex(unsigned int a)
{
	char	*str;
	char	c;
	int		count;
	int		len;

	len = 0;
	str = "0123456789ABCDEF";
	count = 0;
	if (a >= 16)
	{
		count = ft_uhex(a / 16);
		if (count < 0)
			return (-1);
		len = len + count;
	}
	c = str[a % 16];
	if (ft_putchar_fd(c, 1) < 0)
		return (-1);
	return (len + 1);
}
