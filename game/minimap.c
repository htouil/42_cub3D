/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:24:08 by aben-dhi          #+#    #+#             */
/*   Updated: 2024/04/01 22:26:02 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_coords(t_ray *ray, float coords[2], float steps[2])
{
	if (ray->start[0] <= ray->end[0])
		coords[0] += steps[0];
	else
		coords[0] -= steps[0];
	if (ray->start[1] <= ray->end[1])
		coords[1] += steps[1];
	else
		coords[1] -= steps[1];
}

void	draw_minimap(t_game *game, t_ray *ray, int dir, mlx_image_t *img)
{
	int		i;
	float	coords[2];
	float	steps[2];

	i = 0;
	coords[0] = ray->start[0];
	coords[1] = ray->start[1];
	steps[0] = fabs(ray->end[0] - ray->start[0]) / (float)dir;
	steps[1] = fabs(ray->end[1] - ray->start[1]) / (float)dir;
	mlx_put_pixel(img, ray->start[0], ray->start[1], 0xbad129);
	while (i < dir)
	{
		set_coords(ray, coords, steps);
		i++;
		if (coords[0] >= 0 && coords[0] < MINIMAP 
			&& coords[1] >= 0 && coords[1] < MINIMAP)
		{
			game->ray_tiles[(int)coords[1]][(int)coords[0]] = true;
			mlx_put_pixel(img, coords[0], coords[1], 0xbad129);
		}
	}
}

void	draw_ray(t_game *game, t_ray *ray, mlx_image_t *img)
{
	int	dir;

	dir = fabs(ray->end[0] - ray->start[0]);
	if (fabs(ray->end[0] - ray->start[0]) < fabs(ray->end[1] - ray->start[1]))
		dir = fabs(ray->end[1] - ray->start[1]);
	draw_minimap(game, ray, dir, img);
}
