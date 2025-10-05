/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:35:02 by yopeng            #+#    #+#             */
/*   Updated: 2025/06/18 17:17:13 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_string(char spec, va_list args)
{
	char	*s;

	if (spec == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			return (ft_putstr("(null)"));
		return (ft_putstr(s));
	}
	return (-1);
}

static int	handle_format(char spec, va_list args)
{
	int				len;
	unsigned long	p;

	len = 0;
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (spec == 's')
		return (handle_string('s', args));
	if (spec == 'p')
	{
		p = (unsigned long)va_arg(args, void *);
		return (len += ft_putptr(p));
	}
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (spec == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	if (spec == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	if (spec == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if ((*format == '%') && *(format + 1))
			count += handle_format(*(++format), args);
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
