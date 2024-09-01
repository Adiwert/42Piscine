/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjun-kea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:00:35 by wjun-kea          #+#    #+#             */
/*   Updated: 2024/09/01 16:19:58 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

int	count_visible_from_left(int row);
int	count_visible_from_right(int row);
int	count_visible_from_bottom(int col);
int	count_visible_from_top(int col);
extern int	g_set;
extern int	**g_grid;
extern int	*g_top_clues;
extern int	*g_bottom_clues;
extern int	*g_left_clues;
extern int	*g_right_clues;

bool	check_row_constraints(int row)
{
	return (count_visible_from_left(row) == g_left_clues[row]
		&& count_visible_from_right(row) == g_right_clues[row]);
}

bool	check_column_constraints(int col)
{
	return (count_visible_from_top(col) == g_top_clues[col]
		&& count_visible_from_bottom(col) == g_bottom_clues[col]);
}
