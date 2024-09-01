/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:19:59 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/01 17:53:58 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Returns 1 if there are two identical elements in the array (indicate error), 
returns 0 if all elements are different (indicate program runs successfully)
*/
int	array_element(int *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (array[i] == array[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
Fills the check_array with the rows from the permutations specified by row_nums
*/
void	rows_to_array(int check_array[4][4],
		int permutations[24][4], int row_nums[4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			check_array[i][j] = permutations[row_nums[i]][j];
			j++;
		}
		i++;
	}
}

/*
Takes a 4x4 two-dimensional array and displays it
*/
void	print_solution(int array[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = array[j][3 - i] + '0';
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

/*
A function that reverses the elements of the array passed as parameters
*/
void	reverse_int_array(int *array, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = temp;
		i++;
	}
}

/*
Fill a 4-element array with the column number "col_num".
*/
void	get_column(int col_array[4], int array[4][4], int col_num)
{
	int	row_index;

	row_index = 0;
	while (row_index < 4)
	{
		col_array[row_index] = array[row_index][col_num];
		row_index++;
	}
}
