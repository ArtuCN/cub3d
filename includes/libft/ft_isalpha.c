/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:05:08 by aconti            #+#    #+#             */
/*   Updated: 2023/10/09 11:16:52 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int arg)
{
	if ((arg >= 'a' && arg <= 'z') || (arg >= 'A' && arg <= 'Z'))
		return (1);
	else
		return (0);
}
/*int main()
{
	printf("l is -> %d\n", ft_isalpha('l'));
	printf("l is -> %d\n", ft_isalpha(5));
	printf("l is -> %d\n", ft_isalpha('1'));
}*/
