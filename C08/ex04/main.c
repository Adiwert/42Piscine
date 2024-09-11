/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:31:23 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/11 19:56:48 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av); // Function prototype.

int	main(int ac, char **av)
{
	int			i; // Looping index.
	t_stock_str	*tab; // Declares a pointer to hold the array of structures returned by ft_strs_to_tab.

	i = 0;
	tab = ft_strs_to_tab(ac - 1, av + 1); // "ac - 1" (the number of strings excluding the program name) and "av + 1" (the pointer to the first argument string, skipping the program name)
	if (tab == NULL)
	{
		printf("Memory allocation failed.\n"); // Indicates that memory allocation failed 
		return (1); // Indicate failure.
	}
	while (tab[i].str != NULL)
	{
		printf("Size %d: %d\n", i, tab[i].size); // The index i and the size of the string.
		printf("String %d: %s\n", i, tab[i].str); // The original string.
		printf("Copy %d: %s\n", i, tab[i].copy); // The copied string.
		printf("\n");
		i++;
	}
	i = 0; // Initializes i to 0 again.
	while (tab[i].str != NULL) // Inside the loop, it frees the memory allocated for each copied string tab[i].copy.
	{
		free(tab[i].copy);
		i++;
	}
	free(tab); // After the loop, it frees the memory allocated for the array of t_stock_str structures itself.
	return (0); // Indicate successful.
}
