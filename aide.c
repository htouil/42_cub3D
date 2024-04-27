/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aide.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:37:07 by aben-dhi          #+#    #+#             */
/*   Updated: 2024/04/20 16:18:32 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}

void	ft_jsp(t_map *map)
{
	char	*tmp;
	int		i;
	int		length;

	i = 0;
	while (i < map->rows)
	{
		length = ft_strlen1(map->map[i]);
		if (length < map->max)
		{
			tmp = malloc(map->max + 1);
			ft_strcpy(tmp, map->map[i]);
			ft_memset(tmp + length, '1', map->max - length);
			tmp[map->max] = '\0';
			free(map->map[i]);
			map->map[i] = tmp;
		}
		i++;
	}
}

void	idk2(t_game *game, t_ray *ray)
{
	if ((ray->ra < M_PI) && (ray->ra > 0) && ray->side == 1)
	{
		game->textures->current = game->textures->wall[2];
		game->textures->cur_size[0] = game->textures->wall_size[4];
		game->textures->cur_size[1] = game->textures->wall_size[5];
	}
	else
	{
		game->textures->current = game->textures->wall[3];
		game->textures->cur_size[0] = game->textures->wall_size[6];
		game->textures->cur_size[1] = game->textures->wall_size[7];
	}
}

void	idk(t_game *game, t_ray *ray)
{
	ray->side = 1;
	if (ray->dir == 0)
	{
		if ((ray->ra < M_PI / 2 || ray->ra > 3 * M_PI / 2) && ray->side == 1)
		{
			game->textures->current = game->textures->wall[0];
			game->textures->cur_size[0] = game->textures->wall_size[0];
			game->textures->cur_size[1] = game->textures->wall_size[1];
		}
		else
		{
			game->textures->current = game->textures->wall[1];
			game->textures->cur_size[0] = game->textures->wall_size[2];
			game->textures->cur_size[1] = game->textures->wall_size[3];
		}
	}
	else
	{
		idk2(game, ray);
	}
}
