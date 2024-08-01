/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:29:10 by aconti            #+#    #+#             */
/*   Updated: 2023/10/27 18:29:44 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	scorp(t_list **new, t_list **head, t_list **lst, void *(*f)(void *))
{
	(*new)->content = f((*lst)->content);
	(*new)->next = NULL;
	*head = *new;
	*lst = (*lst)->next;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	scorp(&new, &head, &lst, f);
	while (lst != NULL)
	{
		new->next = malloc(sizeof(t_list));
		if (new->next == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new = new->next;
		new->content = f(lst->content);
		new->next = NULL;
		lst = lst->next;
	}
	return (head);
}
