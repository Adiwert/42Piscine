/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:52:11 by tstewart          #+#    #+#             */
/*   Updated: 2024/08/28 19:12:40 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	current_index;
	int	compare_index;
	int	temp;

	current_index = 0;
	while (current_index < size - 1)
	{
		compare_index = current_index + 1;
		while (compare_index < size)
		{
			if (tab[current_index] > tab[compare_index])
			{
				temp = tab[current_index];
				tab[current_index] = tab[compare_index];
				tab[compare_index] = temp;
			}
			compare_index++;
		}
		current_index++;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	int	array[] = {5, 6, 1, 4, 3, 2};
	int	size = 6;
	int	i = 0;

	ft_sort_int_tab(array, size);
	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
