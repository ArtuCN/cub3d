/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmspi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:19:50 by aconti            #+#    #+#             */
/*   Updated: 2023/10/18 19:20:01 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>
//#include <stdlib.h>

/*char f(unsigned int index, char c)
{	
    if (c >= 'a' && c <= 'z')
    {
        return (c - ('a' - 'A'));
    }
    index++;
    index--;
    return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	long	i;
	long	l;
	char	*r;

	if (s == NULL)
		return (NULL);
	i = 0;
	l = 0;
	while (s[l])
		l++;
	r = malloc(sizeof(char) * (l + 1));
	if (r == NULL)
		return (NULL);
	while (s[i])
	{
		r[i] = f(i, s[i]);
		i++;
	}
	r[l] = 0;
	return (r);
}

/*int main()
{
    const char *input = "Hello, World!";
    char *result = ft_strmapi(input, f);

    if (result == NULL)
    {
        printf("Errore nell'allocazione di memoria.\n");
        return (1);
    }

    printf("Stringa di input: %s\n", input);
    printf("Stringa risultante: %s\n", result);

    free(result); // Libera la memoria allocata

    return (0);
}*/
