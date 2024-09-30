/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:46:40 by adonato           #+#    #+#             */
/*   Updated: 2024/09/10 17:15:58 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_dealloc2(t_lost **txt, t_lost *cleannode, char *buf)
{
	t_lost	*tmp;

	if (*txt == NULL)
		return ;
	while (*txt)
	{
		tmp = (*txt)->next;
		free((*txt)->content);
		free(*txt);
		*txt = tmp;
	}
	*txt = NULL;
	if (!cleannode || cleannode->content[0])
		*txt = cleannode;
	else
	{
		free(buf);
		free(cleannode);
	}
}

t_lost	*ft_lstlast2(t_lost *txt)
{
	if (txt == NULL)
		return (NULL);
	while (txt->next)
		txt = txt->next;
	return (txt);
}

void	ft_new_str2(t_lost *txt, char *str)
{
	int	i;
	int	j;

	if (txt == NULL)
		return ;
	j = 0;
	while (txt)
	{
		i = 0;
		while (txt->content[i] != '\0')
		{
			if (txt->content[i] == '\n')
			{
				str[j] = '\n';
				j++;
				str[j] = '\0';
				return ;
			}
			str[j] = txt->content[i];
			j++;
			i++;
		}
		txt = txt->next;
	}
	str[j] = '\0';
}

int	ft_end_line(t_lost *txt)
{
	int	i;

	if (txt == NULL)
		return (0);
	while (txt)
	{
		i = 0;
		while (txt->content[i] && i < BUFFER_SIZE)
		{
			if (txt->content[i] == '\n')
				return (1);
			++i;
		}
		txt = txt->next;
	}
	return (0);
}

int	ft_strlen2(t_lost *txt)
{
	int	i;
	int	len;

	if (txt == NULL)
		return (0);
	len = 0;
	while (txt)
	{
		i = 0;
		while (txt->content[i])
		{
			if (txt->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		txt = txt->next;
	}
	return (len);
}
