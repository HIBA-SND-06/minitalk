/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:48:07 by yopeng            #+#    #+#             */
/*   Updated: 2025/05/05 17:00:35 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	str_len(int n)
{
	size_t	str_len;

	str_len = 0;
	if (n <= 0)
		str_len++;
	while (n)
	{
		str_len++;
		n /= 10;
	}
	return (str_len);
}

char	*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	num;

	len = str_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (n == 0)
		str[0] = '0';
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
