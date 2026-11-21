/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idaitihy <idaitihy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 20:17:57 by idaitihy          #+#    #+#             */
/*   Updated: 2026/11/21 13:33:59 by idaitihy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(const char *s, int fd);
int		ft_unsi_putnbr_fd(unsigned int n, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_hex(unsigned int a);
int		ft_uhex(unsigned int a);
int		ft_putptr(void *ptr);
#endif