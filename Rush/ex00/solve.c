/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjun-kea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:09:26 by wjun-kea          #+#    #+#             */
/*   Updated: 2024/09/01 15:41:13 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int	g_set;
extern int	**g_grid;
extern int	*g_top_clues;
extern int	*g_bottom_clues;
extern int	*g_left_clues;
extern int	*g_right_clues;

bool	check_row_constraints(int row);
bool	check_column_constraints(int col);

bool	is_valid(int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < g_set)
	{
		if (g_grid[row][i] == num || g_grid[i][col] == num)
			return (false);
		i++;
	}
	g_grid[row][col] = num;
	if (col == g_set - 1 && !check_row_constraints(row))
	{
		g_grid[row][col] = 0;
		return (false);
	}
	if (row == g_set - 1 && !check_column_constraints(col))
	{
		g_grid[row][col] = 0;
		return (false);
	}
	g_grid[row][col] = 0;
	return (true);
}

bool	solve(int row, int col)
{
	int	num;

	num = 1;
	if (row == g_set)
		return (true);
	if (col == g_set)
		return (solve(row + 1, 0));
	if (g_grid[row][col] != 0)
		return (solve(row, col + 1));
	while (num <= g_set)
	{
		if (is_valid(row, col, num))
		{
			g_grid[row][col] = num;
			if (solve(row, col + 1))
				return (true);
			g_grid[row][col] = 0;
		}
		num++;
	}
	return (false);
}
