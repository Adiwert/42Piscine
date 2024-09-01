/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:21:00 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/01 19:25:10 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	rows_to_array(int check_array[4][4],
			int permutations[24][4], int row_indices[4]);
void	print_solution(int array[4][4]);
void	get_permutations(int all_permutations[24][4]);
int		verify(int array[4][4], int *values);

/*
Loops through the 331,776 possibilities, prints and returns at the first solution
*/
void	loop(int row_indices[4], int check_array[4][4],
		int permutations[24][4], int values[16])
{
	while (row_indices[0]++, row_indices[0] < 24)
	{
		row_indices[1] = 0;
		while (row_indices[1]++, row_indices[1] < 24)
		{
			row_indices[2] = 0;
			while (row_indices[2]++, row_indices[2] < 24)
			{
				row_indices[3] = 0;
				while (row_indices[3]++, row_indices[3] < 24)
				{
					rows_to_array(check_array, permutations, row_indices);
					if (verify(check_array, values) == 1)
					{
						print_solution(check_array);
						return ;
					}
				}
			}
		}
	}
	write(1, "Error\n", 6);
}

/*
1. Creates and initializes the variables needed for the loop function
2. Only serves to reduce the number of lines
*/
void	resolve(int values[16])
{
	int	permutations[24][4];
	int	check_array[4][4];
	int	row_indices[4];
	int	i;

	i = -1;
	while (i++, i < 4)
		row_indices[i] = -1;
	get_permutations(permutations);
	loop(row_indices, check_array, permutations, values);
}

/*
1. Checks if the character of argv[1] at index cur is in its place
and if so adds it to the values array
2. Helps to reduce the number of lines in main
*/
int	process_character(int index, char **argv, int values[16])
{
	if (index > 31)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (index % 2 == 0)
	{
		if (argv[1][index] >= '0' && argv[1][index] <= '9')
			values[index / 2] = argv[1][index] - '0';
		else
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	else
	{
		if (argv[1][index] != ' ')
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}

/*
Main: retrieves the input string and converts it to an array of values
then calls the resolve function with this array
*/
int	main(int argc, char **argv)
{
	int	values[16];
	int	index;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	index = -1;
	while (index++, argv[1][index] != 0)
	{
		if (process_character(index, argv, values) == 1)
			return (1);
	}
	resolve(values);
}
