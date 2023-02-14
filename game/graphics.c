/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:59:45 by joslopez          #+#    #+#             */
/*   Updated: 2022/09/14 22:44:10 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer,
		game->player,
		width * 60,
		height * 60);
	game->playerheight = height;
	game->playerwidth = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer,
		game->collectable,
		width * 60,
		height * 60);
	game->collectables++;
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"images/land.xpm",
			&i,
			&j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"images/wall.xpm",
			&i,
			&j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"images/sonic.xpm",
			&i,
			&j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"images/exit.xpm",
			&i,
			&j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"images/coin.xpm",
			&i,
			&j);
}

void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = -1;
	while (++height < game->heightmap)
	{
		width = -1;
		while (game->map[height][++width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer,
					game->barrier, width * 60, height * 60);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer,
					game->exit, width * 60, height * 60);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer,
					game->floor, width * 60, height * 60);
		}
	}
}
