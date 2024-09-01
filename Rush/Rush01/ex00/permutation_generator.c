/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation_generator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:23:12 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/01 17:02:18 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Heap's algorithm generates all possible permutations of a set of n objects.
*/
int	g_permutations[24][4];
int	g_current;

/*
Swap the values of x and y
*/
void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/*
Add the combination "array" to the list of combinations "g_permutations"
*/
void	add_permutation(const int *array)
{
	g_permutations[g_current][0] = array[0];
	g_permutations[g_current][1] = array[1];
	g_permutations[g_current][2] = array[2];
	g_permutations[g_current][3] = array[3];
	g_current = g_current + 1;
}

/*
Recursive implementation of Heap's algorithm
*/
void	heap_permute(int array[], int n)
{
	int	i;

	if (n == 1)
		add_permutation(array);
	else
	{
		i = 0;
		while (i < n)
		{
			heap_permute(array, n - 1);
			if (n % 2 == 1)
				swap(&array[0], &array[n - 1]);
			else
				swap(&array[i], &array[n - 1]);
			i++;
		}
	}
}

/*
Copy each element from "source" to "destination"
*/
void	copy_array(int source[24][4], int destination[24][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 4)
		{
			destination[i][j] = source[i][j];
			j++;
		}
		i++;
	}
}

/*
Generate permutations and copy them into the array "permutations"
*/
void	get_permutations(int permutations[24][4])
{
	int	elements[4];

	elements[0] = 1;
	elements[1] = 2;
	elements[2] = 3;
	elements[3] = 4;
	g_current = 0;
	heap_permute(elements, 4);
	copy_array(g_permutations, permutations);
}
