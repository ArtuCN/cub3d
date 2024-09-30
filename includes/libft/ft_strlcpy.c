/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:49:04 by aconti            #+#    #+#             */
/*   Updated: 2023/10/11 15:51:29 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return (ft_strlen(src));
	while (src[i] && i < s - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (dest[i])
		dest[i] = '\0';
	return (ft_strlen(src));
}
/*int main()
{
	const char src[] = "porcodio";
	char dest[] = "widucemadonnacane";
	size_t s;
	
	s = 5;
	printf("size: %zu \n", ft_strlcpy(dest, src, 5));
	printf("dest: %s", dest);
    return 0;
}*/
