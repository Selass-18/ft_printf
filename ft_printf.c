/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaitihy <idaitihy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 20:12:28 by idaitihy          #+#    #+#             */
/*   Updated: 2026/11/21 15:28:57 by idaitihy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cor(const char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	else if (c == 'u')
		return (ft_unsi_putnbr_fd(va_arg(*args, unsigned int), 1));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	else if (c == 'x')
		return (ft_hex(va_arg(*args, unsigned int)));
	else if (c == 'X')
		return (ft_uhex(va_arg(*args, unsigned int)));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}

static int	ft_track(const char *string, int i, va_list *args)
{
	if (string[i] == '%' && string[i + 1] == '\0')
		return (-1);
	if (string[i] == '%')
		return (ft_cor(string[i + 1], args));
	return (ft_putchar_fd(string[i], 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		i;
	int		total;

	if (!format)
		return (-1);
	i = 0;
	total = 0;
	va_start(args, format);
	while (format[i])
	{
		ret = ft_track(format, i, &args);
		if (ret < 0)
		{
			va_end(args);
			return (-1);
		}
		total += ret;
		if (format[i] == '%')
			i++;
		i++;
	}
	va_end(args);
	return (total);
}
