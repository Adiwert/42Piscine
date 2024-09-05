/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:08:39 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/05 14:59:37 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_solution(int table[10])
{
	int	j;

	j = 0;
	while (j < 10)
	{
		ft_putchar(table[j] + '0');
		j++;
	}
	ft_putchar('\n');
}

int	ft_check_duplicate(int table[10], int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (y == table[i]
			|| x + y == i + table[i]
			|| x - y == i - table[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_recursive_puzzle(int table[10], int *solution, int placed_queen)
{
	int	i;

	if (placed_queen == 10)
	{
		*solution += 1;
		ft_print_solution(table);
		return ;
	}
	i = 0;
	while (i < 10)
	{
		if (ft_check_duplicate(table, placed_queen, i))
		{
			table[placed_queen] = i;
			ft_recursive_puzzle(table, solution, placed_queen + 1);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	table[10];
	int	i;
	int	solution;

	i = 0;
	while (i < 10)
	{
		table[i] = -1;
		i++;
	}
	solution = 0;
	ft_recursive_puzzle(table, &solution, 0);
	return (solution);
}

/*
int	main(void)
{
	int	solutions;

	solutions = ft_ten_queens_puzzle();
	ft_putchar(solutions / 10 + '0');
	ft_putchar(solutions % 10 + '0');
	ft_putchar('\n');
	return (0);
}
*/
