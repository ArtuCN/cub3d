/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:29:57 by aconti            #+#    #+#             */
/*   Updated: 2023/10/14 15:40:05 by aconti           ###   ########.fr       */
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
	char	*copia;
	size_t	l;

	l = ft_strlen (src);
	copia = malloc((l + 1) * sizeof(char));
	if (copia == 0)
		return (NULL);
	cpy(copia, src);
	return (copia);
}
/*int main()
{
	const char c[] = "comunisti al rogo";
	printf("mia: %s\n", ft_strdup(c));
	printf("sua: %s\n", strdup(c));
		
}*/
