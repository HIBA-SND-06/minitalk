/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:40:02 by yopeng            #+#    #+#             */
/*   Updated: 2025/04/30 19:55:32 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last = str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return ((char *)last);
}
