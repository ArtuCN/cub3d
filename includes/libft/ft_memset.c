/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:01:40 by aconti            #+#    #+#             */
/*   Updated: 2023/10/10 10:42:14 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *p, int v, size_t s)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)p;
	i = 0;
	while (i < s)
	{
		ptr[i] = v;
		i++;
	}
	return (p);
}
/*int main() {
	char	*arr = malloc(sizeof (char)*5);
	int	i;
	i = 0;
	ft_memset(arr, 'h', 5);
	while(i < 5)
	{
		write(1, arr + (i), 1);
		i++;
	}

    return 0;
}*/
