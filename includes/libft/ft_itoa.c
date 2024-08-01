/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:00:18 by aconti            #+#    #+#             */
/*   Updated: 2023/10/18 14:07:43 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long n)
{
	int	lunghezza;

	lunghezza = 0;
	if (n <= 0)
	{
		lunghezza++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		lunghezza++;
	}
	return (lunghezza);
}

char	*ft_itoa(int n)
{
	char		*r;
	int			l;
	long		nb;

	nb = n;
	l = len(nb);
	r = malloc(sizeof(char) * (l + 1));
	if (r == NULL)
		return (NULL);
	if (nb == 0)
		r[0] = '0';
	if (0 > nb)
	{
		nb = -nb;
		r[0] = '-';
	}
	r[l] = '\0';
	l--;
	while (nb > 0)
	{
		r[l] = (nb % 10) + 48;
		nb /= 10;
		l--;
	}
	return (r);
}

/*int main()
{
	printf("eiaeiaellala: %s", ft_itoa(525230));
}*/
