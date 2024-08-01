/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:47:42 by aconti            #+#    #+#             */
/*   Updated: 2023/10/13 18:55:56 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

static int	cancel(const char str)
{
	if (str == 32 || (str >= '\t' && str <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	r;

	r = 0;
	neg = 1;
	while (cancel(*str) == 1)
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0' && *str <= '9') && *str)
	{
		r *= 10;
		r += (*str - 48);
		str++;
	}
	return (r * neg);
}
/*int main()
{	
	printf("atoi :%d \n", atoi(" -+434"));
	printf("ft_atoi :%d", ft_atoi(" -+424"));
}*/
