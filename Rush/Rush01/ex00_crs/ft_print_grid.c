/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiew <jthiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:47:15 by jthiew            #+#    #+#             */
/*   Updated: 2024/09/01 16:51:48 by jthiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

extern int	**g_grid;
extern int	g_set;

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_grid(void)
{
	int		i;
	int		j;
	char	num;

	i = 0;
	while (i < g_set)
	{
		j = 0;
		while (j < g_set)
		{
			num = g_grid[i][j] + '0';
			ft_putchar(num);
			j++;
			if (j < g_set)
				ft_putchar(' ');
		}
		write(1, "\n", 1);
		i++;
	}
}
