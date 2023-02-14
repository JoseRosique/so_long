/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:01:37 by joslopez          #+#    #+#             */
/*   Updated: 2022/09/14 22:42:53 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/MLX42.h"
# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		playerwidth;
	int		playerheight;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}			t_complete;

int			exit_point(t_complete *game);
int			map_reading(t_complete *game, char **argv);
int			controls_working(int command, t_complete *game);
void		adding_in_graphics(t_complete *game);
void		place_images_in_game(t_complete *game);
void		if_walls(t_complete *game);
void		character_valid(t_complete *game);

#endif
