/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaitihy <idaitihy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:32:08 by idaitihy          #+#    #+#             */
/*   Updated: 2026/11/21 13:37:08 by idaitihy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putulhex(unsigned long addr)
{
	char	*base;
	int		count;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (addr >= 16)
	{
		count = ft_putulhex(addr / 16);
		if (count < 0)
			return (-1);
		len += count;
	}
	if (ft_putchar_fd(base[addr % 16], 1) < 0)
		return (-1);
	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	ret;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	len = ft_putstr_fd("0x", 1);
	if (len < 0)
		return (-1);
	ret = ft_putulhex((unsigned long)ptr);
	if (ret < 0)
		return (-1);
	return (len + ret);
}
