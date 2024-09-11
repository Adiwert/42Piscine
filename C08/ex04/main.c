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

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	i = 0;
	tab = ft_strs_to_tab(ac - 1, av + 1);
	if (tab == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	while (tab[i].str != NULL)
	{
		printf("Size %d: %d\n", i, tab[i].size);
		printf("String %d: %s\n", i, tab[i].str);
		printf("Copy %d: %s\n", i, tab[i].copy);
		printf("\n");
		i++;
	}
	i = 0;
	while (tab[i].str != NULL)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
	return (0);
}
