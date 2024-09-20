/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:10:30 by aconti            #+#    #+#             */
/*   Updated: 2023/10/27 18:10:32 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*c;
	t_list	*next;

	c = *lst;
	while (c != NULL)
	{
		next = c->next;
		del(c->content);
		free(c);
		c = next;
	}
	*lst = NULL;
}
