/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:48:33 by aconti            #+#    #+#             */
/*   Updated: 2023/10/13 15:14:05 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (unsigned char)str1[i] && (unsigned char)str2[i])
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

/*
int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, OpenAI!";
    int n = 5;  // Number of characters to compare

    int result = ft_strncmp(str1, str2, n);

    if (result == 0) {
        printf("The first %d characters are equal.\n", n);
    } else if (result < 0) {
        printf("str1 is less than str2 in the first %d characters.\n", n);
    } else {
        printf("str1 is greater than str2 in the first %d characters.\n", n);
    }

    return 0;
}*/
