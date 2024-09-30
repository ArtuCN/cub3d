/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:14:14 by aconti            #+#    #+#             */
/*   Updated: 2023/10/09 12:20:05 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int arg)
{
	if (arg >= 32 && arg <= 126)
		return (1);
	return (0);
}
/*int main()
{
	printf("l is -> %d\n", ft_isprint(2));
	printf("l is -> %d\n", ft_isprint('!'));
	printf("l is -> %d\n", ft_isprint('2'));
	printf("l is -> %d\n", ft_isprint(' '));
}*/
