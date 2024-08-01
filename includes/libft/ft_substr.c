/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:44:37 by aconti            #+#    #+#             */
/*   Updated: 2023/10/14 18:25:30 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sb;
	size_t	i;

	if (start > (unsigned int)ft_strlen(s))
	{
		sb = malloc(sizeof(char) * 1);
		if (sb == NULL)
			return (NULL);
		*sb = '\0';
		return (sb);
	}
	s += start;
	if (ft_strlen(s) <= len)
		sb = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		sb = malloc(sizeof(char) * (len + 1));
	if (sb == 0)
		return (0);
	i = -1;
	while (s[++i] && i < len)
		sb[i] = s[i];
	sb[i] = '\0';
	return (sb);
}
/*int main()
{
	const char	*p = "se ni mondo esistesse un po di bene";
	unsigned int	i;
	size_t	l;

	i = 10;
	l = 10;
	printf("mia: %s \n", ft_substr(p, 6, 65));
    //printf("sua: %d \n", substr(p, 11, 10));

}*/
