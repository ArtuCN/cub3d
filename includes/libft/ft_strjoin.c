/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:44:05 by aconti            #+#    #+#             */
/*   Updated: 2023/10/16 11:44:14 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l3;
	char	*r;
	int		i;
	int		j;

	l3 = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	r = 0;
	i = 0;
	j = 0;
	r = (char *)malloc(l3);
	if (r == 0)
		return (0);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[j] && i < (int)l3)
	{
		r[i] = s2[j];
		i++;
		j++;
	}
	r[i] = '\0';
	return (r);
}
/*int main()
{
	char const	s1[] = "poppe";
	char const	s2[] = "culo";
	printf("%s", ft_strjoin(s1, s2));
}*/
