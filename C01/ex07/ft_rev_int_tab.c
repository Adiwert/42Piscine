/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:56:56 by tstewart          #+#    #+#             */
/*   Updated: 2024/08/28 18:48:26 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	start;
	int	end;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab[end] = temp;
		start++;
		end--;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	int	array[] = {1, 2, 3, 4, 5, 6};
	int	size = 6;
	int	i = 0;
	ft_rev_int_tab(array, size);
	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
	printf("\n");

	return (0);
}
*/
