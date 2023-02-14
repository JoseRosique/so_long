/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:00:28 by joslopez          #+#    #+#             */
/*   Updated: 2022/09/14 22:57:14 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	exit_point(t_complete *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->heightmap - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc == 2)
	{
		ft_memset(&game, 0, sizeof(t_complete));
		map_reading(&game, argv);
		if_walls(&game);
		character_valid(&game);
		game.mlxpointer = mlx_init();
		game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 60),
				(game.heightmap * 60), "solong");
		place_images_in_game(&game);
		adding_in_graphics(&game);
		mlx_key_hook(game.winpointer, controls_working, &game);
		mlx_loop(game.mlxpointer);
	}
	else if (argc > 2)
		printf("Error, more than 2 arguments");
	printf("\n");
}
