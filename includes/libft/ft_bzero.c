/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:49:30 by aconti            #+#    #+#             */
/*   Updated: 2023/10/10 10:53:54 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdlib.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*int main() {
	char	*arr = malloc(sizeof (char)*5);
	int	i;
	i = 0;
	
	ft_bzero(arr, 5);
	while(i < 5)
	{
		write(1, arr + (i), 1);
		i++;
	}

    return 0;
}*/
