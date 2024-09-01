/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:01:46 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/01 16:02:30 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Takes a 4x4 two-dimensional array and displays it
*/
void	print_array(int array[4][4])
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
			c = array[i][j] + '0';
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
				j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
