/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:36:33 by aconti            #+#    #+#             */
/*   Updated: 2023/10/11 17:36:36 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t s)
{
	size_t	d;
	size_t	so;
	size_t	r;
	size_t	i;

	i = 0;
	d = ft_strlen(dest);
	so = ft_strlen(src);
	if (s < d)
		r = s + so;
	else
		r = so + d;
	while (s - 1 > d && src[i] != 0 && s != 0)
	{
		dest[d] = src[i];
		d++;
		i++;
	}
	dest[d] = 0;
	return (r);
}
/*int main()
{
	const char src[] = "abc";
	char dest[] = "ciao";
	size_t s;
	
	s = 1;
	printf("s: %zu \n", ft_strlcat(dest, src, 0));
	printf("dest: %s \n", dest);
}*/
