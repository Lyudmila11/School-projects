/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:00:33 by ldon              #+#    #+#             */
/*   Updated: 2024/01/31 16:36:29 by ldon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned long num, char type, unsigned int base)
{
	int		res;
	char	*hex;
	char	c;

	res = 0;
	hex = "0123456789abcdef";
	if (type == 'X')
		hex = "0123456789ABCDEF";
	c = hex[num % base];
	if (num >= base)
		res += ft_unsigned(num / base, type, base);
	res += write(1, &c, 1);
	return (res);
}

int	ft_putptr(unsigned long num)
{
	int	res;

	res = 0;
	if (!num)
		return (ft_putstr("(nil)"));
	res += ft_putstr("0x");
	res += ft_unsigned(num, 'x', 16);
	return (res);
}

int	ft_putnbr(long num)
{
	int		res;
	char	*dec;
	char	c;

	res = 0;
	dec = "0123456789";
	if (num < 0)
	{
		res += write(1, "-", 1);
		num *= -1;
	}
	c = dec[num % 10];
	if (num > 9)
		res += ft_putnbr(num / 10);
	res += write(1, &c, 1);
	return (res);
}

int	check(va_list vl, char c)
{
	int	res;

	res = 0;
	if (c == 's')
		res += ft_putstr(va_arg(vl, char *));
	else if (c == 'd' || c == 'i')
		res += ft_putnbr(va_arg(vl, int));
	else if (c == 'u')
		res += ft_unsigned(va_arg(vl, unsigned int), c, 10);
	else if (c == 'x' || c == 'X')
		res += ft_unsigned(va_arg(vl, unsigned int), c, 16);
	else if (c == 'p')
		res += ft_putptr((unsigned long)va_arg(vl, void *));
	else if (c == 'c')
		res += ft_putchar(va_arg(vl, int));
	else if (c == '%')
		res += ft_putchar('%');
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	int		i;
	va_list	vl;

	va_start(vl, str);
	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			res += check(vl, str[++i]);
		else
			res += write(1, &str[i], 1);
		i++;
	}
	va_end(vl);
	return (res);
}

/*
#include <stdio.h>
int main(void)
{
	char	c;
	printf("%d\n", ft_printf("%s %x %d %p\n", "hello", 77, (int)-217483648, &c));
}
*/
