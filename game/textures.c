/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:44:28 by aben-dhi          #+#    #+#             */
/*   Updated: 2024/04/19 15:03:01 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_textures(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/wall.png");
	game->map->wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/floor.png");
	game->map->floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/tile_water.png");
	game->map->out = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	init_an(t_game *game, mlx_texture_t *text)
{
	text = mlx_load_png(game->map->no);
	game->textures->wall[0] = ft_color(text);
	game->textures->wall_size[0] = text->width;
	game->textures->wall_size[1] = text->height;
	mlx_delete_texture(text);
	text = mlx_load_png(game->map->so);
	game->textures->wall[1] = ft_color(text);
	game->textures->wall_size[2] = text->width;
	game->textures->wall_size[3] = text->height;
	mlx_delete_texture(text);
}

void	init_textures(t_game *game)
{
	mlx_texture_t	*text;

	game->textures = malloc(sizeof(t_textures));
	text = NULL;
	init_an(game, text);
	text = mlx_load_png(game->map->ea);
	game->textures->wall[2] = ft_color(text);
	game->textures->wall_size[4] = text->width;
	game->textures->wall_size[5] = text->height;
	mlx_delete_texture(text);
	text = mlx_load_png(game->map->we);
	game->textures->wall[3] = ft_color(text);
	game->textures->wall_size[6] = text->width;
	game->textures->wall_size[7] = text->height;
	mlx_delete_texture(text);
	text = mlx_load_png("./textures/floor.png");
	game->textures->floor = ft_color(text);
	mlx_delete_texture(text);
}
