/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:22:29 by yopeng            #+#    #+#             */
/*   Updated: 2025/06/18 17:18:50 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthex_ptr(unsigned long n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += ft_puthex_ptr(n / 16);
	len += ft_putchar(base[n % 16]);
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthex_ptr(ptr);
	return (len);
}
