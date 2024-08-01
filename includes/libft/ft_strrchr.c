/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:34:49 by aconti            #+#    #+#             */
/*   Updated: 2023/10/11 20:36:47 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*result;
	int			i;

	result = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			result = (char *)&s[i];
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		result = (char *)&s[i];
	return (result);
}
/*int main()
{
    const char *str = "Hello, World!";
    char target = 'o';
    char *result = ft_strrchr(str, target);

    if (result != 0) {
        printf("'%c' found at position: %ld\n", target, result - str);
    } else {
        printf("'%c' not found in the string.\n", target);
    }

    return 0;
}*/
