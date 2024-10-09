/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:52:53 by adonato           #+#    #+#             */
/*   Updated: 2024/09/10 17:16:28 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_lost
{
	char			*content;
	struct s_lost	*next;
}			t_lost;

int		ft_strlen2(t_lost *txt);
int		ft_end_line(t_lost *txt);
void	ft_new_str2(t_lost *txt, char *str);
t_lost	*ft_lstlast2(t_lost *txt);
void	ft_dealloc2(t_lost **txt, t_lost *cleannode, char *buf);
void	ft_start_txt(t_lost **txt);
char	*ft_attach(t_lost *txt);
void	ft_add_node2(t_lost **txt, char *buf);
void	ft_create_new_list(t_lost **txt, int fd);
char	*get_next_line(int fd);

#endif
