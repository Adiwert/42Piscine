/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:54:03 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/08 20:37:01 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (arr == NULL)
	{
		*range = NULL;
		return (-1);
	}
	*range = arr;
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	int	*arr;
	int size;
	int i;

	i = 0;
	size = ft_ultimate_range(&arr, 3, 8);
	if (size == -1)
	{
		printf("Memory allocation failed\n");
	}
	else if (size == 0)
	{
		printf("No range allocated: min >= min\n");
	}
	else
	{
		printf("Array of size %d:\n", size);
		while (i < size)
		{
			printf("%d ", arr[i]);
			i++;
		}
		printf("\n");
	}
	free(arr);
	return (0);
}
*/
