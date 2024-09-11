/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:12:52 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/11 23:06:42 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../ex04/ft_strs_to_tab.c" // Get it from the "ex04" file.
#include "ft_stock_str.h"

t_stock_str	*ft_strs_to_tab(int ac, char **av);
void		ft_show_tab(t_stock_str *par);  // Function prototypes.

int	main(int ac, char **av)
{
	int			i; // Looping index.
	t_stock_str	*tab; // Declares a pointer tab of type t_stock_str, which will point to an array of t_stock_str structures created by ft_strs_to_tab.

	i = 0;
	tab = ft_strs_to_tab(ac - 1, av + 1); // Calls the function ft_strs_to_tab to convert the command-line arguments into an array of t_stock_str structures.
	if (tab == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	ft_show_tab(tab); // Calls ft_show_tab to display the contents of the tab array (the strings, their sizes, and their copies).
	while (tab[i].str != NULL)
	{
		free(tab[i].copy); // Frees the memory allocated for the copy string in each t_stock_str structure to prevent memory leaks.
		i++;
	}
	free (tab); // After freeing each copied string, the entire tab array itself is freed to prevent memory leaks.
	return (0);
}
