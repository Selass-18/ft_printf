/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaitihy <idaitihy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 12:18:12 by idaitihy          #+#    #+#             */
/*   Updated: 2026/11/21 10:24:27 by idaitihy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(const char *s, int fd)
{
	int	i;
	int	ret;

	if (!s)
		return (ft_putstr_fd("(null)", fd));
	i = 0;
	while (s[i] != '\0')
	{
		ret = ft_putchar_fd(s[i], fd);
		if (ret != 1)
			return (-1);
		i++;
	}
	return (i);
}
