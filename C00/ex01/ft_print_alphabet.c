/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:35:04 by tstewart          #+#    #+#             */
/*   Updated: 2024/08/22 18:43:49 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	i;

	i = 'a';
	while (i <= 'z')
	{
		write (1, &i, 1);
		i++;
	}
}

int	main(void)
{
	ft_print_alphabet();
	write (1, "\n", 1);
	return (0);
}
