/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dhi <aben-dhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:42:06 by aben-dhi          #+#    #+#             */
/*   Updated: 2024/04/21 17:56:54 by aben-dhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_params(t_map *map)
{
	map->rows = 0;
	map->columns = 0;
	map->file = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = NULL;
	map->c = NULL;
	map->map = NULL;
	map->tmp = NULL;
	map->max = 0; 
	map->n_chars = 0;
}

void	max2(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->max = ft_strlen1(map->map[0]);
	while (i < map->rows)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (ft_strlen1(map->map[i]) > map->max)
			{
				map->max = ft_strlen1(map->map[i]);
			}
			j++;
		}
		i++;
	}
}

void	add_walls(t_map *map)
{
	char	wall;
	int		i;
	int		j;

	wall = '1';
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->map[i][j] != wall && j < ft_strlen1(map->map[i]))
		{
			map->map[i][j] = wall;
			j++;
		}
		i++;
	}
	max2(map);
	ft_jsp(map);
}

int	setup_game_data(char **av, t_map *map)
{
	int		fd;

	if (check_extension(av[1]) == 0)
	{
		free(map);
		return (ft_putstr_fd("Error\nInvalid file extension!\n", 2), 1);
	}
	init_params(map);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		free(map);
		return (ft_putstr_fd("Error\nInvalid file!\n", 2), 1);
	}
	read_map(fd, map);
	display_map_errors1(map);
	display_map_errors2(map);
	add_walls(map);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	*game;

	if (ac == 2)
	{
		map = malloc(sizeof(t_map));
		if (!map)
			return (1);
		if (setup_game_data(av, map) == 1)
			return (1);
		game = alloc_game(map);
		init_game(game);
		mlx_loop(game->mlx);
		free_exit(game);
		free_data(map);
	}
	else
		return (ft_error("Error\nInvalid number of arguments!\n", 2), 1);
	return (0);
}

// int main(int ac, char **av)
// {
// 	main21(ac, av);
// 	
// 	return (0);
// }
