/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:58:06 by aconti            #+#    #+#             */
/*   Updated: 2023/10/16 14:58:12 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	controllo(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*r;
	size_t	i;

	while (*s1 && controllo(*s1, set))
		s1++;
	i = ft_strlen(s1);
	while (i > 0 && controllo(s1[i - 1], set))
		i--;
	r = (char *)malloc(sizeof (char) * (i + 1));
	if (r == NULL)
		return (NULL);
	r[i] = '\0';
	while (i > 0)
	{
		r[i - 1] = s1[i - 1];
		i--;
	}
	return (r);
}

/*int main()
{
	printf("ciuccia :%s", ft_strtrim("xxxz  
	test with x and z and x .  zx  xx z", "z x"));
}*/
