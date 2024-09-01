/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:48:28 by jthiew            #+#    #+#             */
/*   Updated: 2024/09/01 16:17:50 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr(char *str);
int		ft_valid_grid(int argc, char *argv);
void	ft_ini_global_array(char *argv);
void	ft_print_grid(void);
bool	solve(int row, int col);
int		ft_len(char *str);
extern int	*g_top_clues;
extern int	*g_bottom_clues;
extern int	*g_left_clues;
extern int	*g_right_clues;
int			**g_grid;
int			g_set;

int	ft_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			len++;
		}
		i++;
	}
	return (len);
}

int	**create_2d_array(void)
{
	int	i;
	int	j;
	int	**array;

	array = (int **)malloc(g_set * sizeof(int *));
	if (array == NULL)
	{
		ft_putstr("Failed to allocate memory for rows");
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < g_set)
	{
		array[i] = (int *)malloc(g_set * sizeof(int));
		if (array[i] == NULL)
		{
			j = -1;
			ft_putstr("Failed to allocate memory for columns");
			while (++j < i)
				free(array[j]);
			free(array);
			exit(EXIT_FAILURE);
		}
	}
	return (array);
}

void	ft_fill_grid(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_set)
	{
		j = 0;
		while (j < g_set)
		{
			g_grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	g_set = ft_len(argv[1]) / 4;
	if (ft_valid_grid(argc, argv[1]) == 0)
	{
		return (0);
	}
	else
	{
		ft_ini_global_array(argv[1]);
		g_grid = create_2d_array();
		ft_fill_grid();
		if (solve(0, 0))
		{
			ft_print_grid();
		}
		else
		{
			ft_putstr("No solution found.\n");
		}
	}
	return (0);
}
