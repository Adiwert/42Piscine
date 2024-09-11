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
#include "../ex04/ft_strs_to_tab.c"
#include "ft_stock_str.h"

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_show_tab(struct s_stock_str *par);

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
	ft_show_tab(tab);
	while (tab[i].str != NULL)
	{
		free(tab[i].copy);
		i++;
	}
	free (tab);
	return (0);
}
