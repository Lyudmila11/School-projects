/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:14:43 by ldon              #+#    #+#             */
/*   Updated: 2024/01/31 16:35:15 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putchar(char c);

int	ft_putstr(char *str);

int	ft_unsigned(unsigned long num, char type, unsigned int base);

int	ft_putptr(unsigned long num);

int	ft_putnbr(long num);

int	check(va_list vl, char c);

int	ft_printf(const char *str, ...);

#endif
