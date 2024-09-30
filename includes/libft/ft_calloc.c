/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:04:48 by aconti            #+#    #+#             */
/*   Updated: 2023/10/13 19:52:36 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = (void *)malloc(n * size);
	if (!ptr)
		return (0);
	i = 0;
	while (i < size * n)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
