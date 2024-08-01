/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:03:29 by aconti            #+#    #+#             */
/*   Updated: 2023/10/11 15:51:04 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char			*d;
	const char		*s;
	size_t			i;

	d = (char *) dest;
	s = (const char *) src;
	if (d == s)
		return (dest);
	i = len + 1;
	if (d > s)
	{
		while (--i > 0)
			d[i - 1] = s[i - 1];
	}
	else
	{
		i = -1;
		while (++i < len)
			d[i] = s[i];
	}
	return (dest);
}
/*int main()
{
	char	dest[] = "dioboia";
	const char	src[] = "wild";
    printf("prima di memmove %s\n", dest);
	ft_memmove(dest, src, 0);
	printf("dopo di memmove %s\n", dest);
}*/
