/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjun-kea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:00:35 by wjun-kea          #+#    #+#             */
/*   Updated: 2024/09/01 16:33:34 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

extern int	g_set;
extern int	**g_grid;
extern int	*g_top_clues;
extern int	*g_bottom_clues;
extern int	*g_left_clues;
extern int	*g_right_clues;

int	count_visible_from_left(int row)
{
	int	max_height;
	int	visible_count;
	int	i;

	i = 0;
	max_height = 0;
	visible_count = 0;
	while (i < g_set)
	{
		if (g_grid[row][i] > max_height)
		{
			max_height = g_grid[row][i];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}

int	count_visible_from_right(int row)
{
	int	max_height;
	int	visible_count;
	int	i;

	max_height = 0;
	visible_count = 0;
	i = g_set - 1;
	while (i >= 0)
	{
		if (g_grid[row][i] > max_height)
		{
			max_height = g_grid[row][i];
			visible_count++;
		}
		i--;
	}
	return (visible_count);
}

int	count_visible_from_top(int col)
{
	int	max_height;
	int	visible_count;
	int	i;

	max_height = 0;
	visible_count = 0;
	i = 0;
	while (i < g_set)
	{
		if (g_grid[i][col] > max_height)
		{
			max_height = g_grid[i][col];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}

int	count_visible_from_bottom(int col)
{
	int	max_height;
	int	visible_count;
	int	i;

	max_height = 0;
	visible_count = 0;
	i = g_set - 1;
	while (i >= 0)
	{
		if (g_grid[i][col] > max_height)
		{
			max_height = g_grid[i][col];
			visible_count++;
		}
		i--;
	}
	return (visible_count);
}
