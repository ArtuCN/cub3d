/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:36:54 by aconti            #+#    #+#             */
/*   Updated: 2023/10/13 16:56:24 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*su;
	const unsigned char	*sd;
	int					r;
	size_t				i;

	su = (const unsigned char *)s1;
	sd = (const unsigned char *)s2;
	r = 0;
	i = 0;
	while (i < n)
	{
		if (su[i] != sd[i])
		{
			r = su[i] - sd[i];
			return (r);
		}
		i++;
	}
	return (0);
}
