/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:29:57 by aconti            #+#    #+#             */
/*   Updated: 2024/09/12 14:13:34 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "libft.h"

static size_t	cpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (dest[i])
		dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(src);
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	ft_memset(copy, 0, len + 1);
	cpy(copy, src);
	return (copy);
}

/*int main()
{
	const char c[] = "comunisti al rogo";
	printf("mia: %s\n", ft_strdup(c));
	printf("sua: %s\n", strdup(c));
		
}*/