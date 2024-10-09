/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:49 by adonato           #+#    #+#             */
/*   Updated: 2024/09/10 17:17:45 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_lost	*txt;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_create_new_list(&txt, fd);
	if (txt == NULL)
		return (NULL);
	line = ft_attach(txt);
	ft_start_txt(&txt);
	return (line);
}

void	ft_create_new_list(t_lost **txt, int fd)
{
	int		count;	
	char	*buf;

	while (!ft_end_line(*txt))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		count = read(fd, buf, BUFFER_SIZE);
		if (count == 0)
		{
			free(buf);
			return ;
		}
		if (count < 0 || !count)
		{
			free(buf);
			ft_dealloc2(txt, NULL, NULL);
			return ;
		}
		buf[count] = '\0';
		ft_add_node2(txt, buf);
	}
}

void	ft_add_node2(t_lost **txt, char *buf)
{
	t_lost	*newnode;
	t_lost	*lastnode;

	newnode = malloc(sizeof(t_lost));
	if (newnode == NULL)
		return ;
	lastnode = ft_lstlast2(*txt);
	if (lastnode == NULL)
		*txt = newnode;
	else
		lastnode->next = newnode;
	newnode->content = buf;
	newnode->next = NULL;
}

char	*ft_attach(t_lost *txt)
{
	int		len;
	char	*nextstr;

	if (txt == NULL)
		return (NULL);
	len = ft_strlen2(txt);
	nextstr = malloc(len + 1);
	if (nextstr == NULL)
		return (NULL);
	ft_new_str2(txt, nextstr);
	return (nextstr);
}

void	ft_start_txt(t_lost **txt)
{
	t_lost	*lastnode;
	t_lost	*cleannode;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	cleannode = malloc(sizeof(t_lost));
	if (buf == NULL || cleannode == NULL)
		return ;
	lastnode = ft_lstlast2(*txt);
	i = 0;
	j = 0;
	while (lastnode->content[i] && lastnode->content[i] != '\n')
		++i;
	while (lastnode->content[i] && lastnode->content[++i])
		buf[j++] = lastnode->content[i];
	buf[j] = '\0';
	cleannode->content = buf;
	cleannode->next = NULL;
	ft_dealloc2(txt, cleannode, buf);
}
/*
int	main()
{
	int	i = 0;
	int	fd;
	char	*str;
	fd = open("prova.txt", O_RDONLY);
	while (i < 5)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	close(fd);
}*/
