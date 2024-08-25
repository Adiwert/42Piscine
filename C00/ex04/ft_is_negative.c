/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:17:24 by tstewart          #+#    #+#             */
/*   Updated: 2024/08/22 20:23:29 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write (1, "N", 1);
	else
		write (1, "P", 1);
}

int	main(void)
{
	ft_is_negative(-1);
	ft_is_negative(0);
	ft_is_negative(1);
	ft_is_negative('n');
	write (1, "\n", 1);
	return (0);
}
