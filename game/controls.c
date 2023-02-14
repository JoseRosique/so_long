/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:52:10 by joslopez          #+#    #+#             */
/*   Updated: 2022/09/14 22:43:27 by joslopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	right_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\e[31m\e[1m\nYou Have Won, Congrats! \e[0m \n");
		exit_point(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->playerwidth = i;
		game->playerheight = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->playerwidth = i;
		game->playerheight = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

static int	keyboard_w_s(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->playerwidth;
	j = game->playerheight;
	if (movement == 13)
	{
		if (game->map[--j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == 1)
	{
		if (game->map[++j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	return (1);
}

static int	keyboard_a_d(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->playerwidth;
	j = game->playerheight;
	if (movement == 0)
	{
		if (game->map[j][--i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == 2)
	{
		if (game->map[j][++i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	return (1);
}

int	controls_working(int command, t_complete *game)
{
	int	works;

	if (command == 53)
		exit_point(game);
	if (command == 13 || command == 1)
	{
		works = keyboard_w_s(game, command);
		printf("Steps Taken: %i\n", game->counter);
		printf("Collectables Remaining: %i\n", game->collectables);
	}
	if (command == 0 || command == 2)
	{
		works = keyboard_a_d(game, command);
		printf("Steps Taken: %i\n", game->counter);
		printf("Collectables Remaining: %i\n", game->collectables);
	}
	if (works)
		adding_in_graphics(game);
	return (1);
}
