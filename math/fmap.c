/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:43:48 by aconti            #+#    #+#             */
/*   Updated: 2024/08/02 17:44:49 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	fmap(int unscaled_num, int new_max, int old_max)
{
	return (new_max * (unscaled_num) / (old_max));
}