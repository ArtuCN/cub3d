/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:13:14 by aconti            #+#    #+#             */
/*   Updated: 2023/10/11 15:16:02 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dest == 0 && src == 0)
		return (0);
	d = (char *)dest;
	s = (const char *)src;
	while (n-- > 0)
	{
		d[n] = s[n];
	}
	return (dest);
}
/*int main()
{
	char	dest[] = "casa";
	const char	src[] = "camaleonte";
	ft_memcpy(dest, src, 7);
	printf("%s", dest);
}*/
