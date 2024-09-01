/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:22:56 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/01 17:13:20 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reverse_int_array(int *array, int size);
int		array_element(int *row);
void	get_column(int column_array[4], int array[4][4], int column_index);

/*
1. Checks if the row passed contains the correct number of visible boxes
2. "value" is the number obtain from the clues
3. "tab" can represent either a row or a column
*/
int	check(int *tab, int value)
{
	int	max_seen;
	int	index;
	int	visible_count;

	if (value < 1 || value > 4)
		return (0);
	index = 1;
	max_seen = tab[0];
	visible_count = 1;
	while (visible_count < 4)
	{
		if (tab[visible_count] > max_seen)
		{
			index++;
			max_seen = tab[visible_count];
		}
		visible_count++;
	}
	return (index == value && array_element(tab) == 0);
}

/*
1. Reverses the row/column passed as an argument and then calls "check"
2. "tab" can represent either a row or a column
*/
int	reverse_check(int *tab, int value)
{
	reverse_int_array(tab, 4);
	return (check(tab, value));
}

/*
Calls check and reverse_check for each row, with the appropriate clues
*/
int	verify_rows(int array[4][4], int *values)
{
	int	row_index;
	int	status;

	row_index = 0;
	while (row_index < 4)
	{
		status = 0;
		status += check(array[row_index], values[row_index]);
		status += reverse_check(array[row_index], values[row_index + 4]);
		if (status != 2)
			return (0);
		row_index++;
	}
	return (1);
}

/*
Calls check and reverse_check for each column, with the appropriate clues
*/
int	verify_columns(int array[4][4], int *values)
{
	int	col_index;
	int	column[4];
	int	status;

	col_index = 0;
	while (col_index < 4)
	{
		status = 0;
		get_column(column, array, col_index);
		status += check(column, values[col_index + 8]);
		status += reverse_check(column, values[col_index + 12]);
		if (status != 2)
			return (0);
		col_index++;
	}
	return (1);
}

/*
If both rows and columns are correct, the array is considered a solution.
*/
int	verify(int array[4][4], int *values)
{
	return (verify_columns(array, values) && verify_rows(array, values));
}
