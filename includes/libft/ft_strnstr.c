/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:04:19 by aconti            #+#    #+#             */
/*   Updated: 2023/10/13 17:46:36 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*b;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && len > i)
	{
		while (big[i + j] == little[j] && little[j] && (i + j) < len)
		{
			j++;
		}
		if (!little[j])
		{
			b = (char *)&big[i];
			return (b);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

/*int main ()
{
	printf("&s", ft_strnstr("itaste", "ata", 2));
}*/
