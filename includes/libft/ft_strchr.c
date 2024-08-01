/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:07:06 by aconti            #+#    #+#             */
/*   Updated: 2023/10/11 20:32:34 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((char)s[i] != (unsigned char)c && s[i])
		i++;
	if ((char)s[i] == ((unsigned char)c))
		return ((char *)s + i);
	return (NULL);
}
/*int main()
{
    const char *str = "tripouille";
    const char *str2 = "tripouille";
	
    printf("funzione mia %s \n", ft_strchr(str, 'z'));
    printf("funzione vera %s \n", strchr(str2, 'z'));

    return 0;
}*/
