/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mahf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:12:26 by aal-mahf          #+#    #+#             */
/*   Updated: 2024/08/27 15:41:30 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	cr;

	cr = 'z';
	while (cr >= 'a')
	{
		write(1, &cr, 1);
		cr--;
	}
}

int	main(void)
{
	ft_print_reverse_alphabet();
	write (1, "\n", 1);
	return (0);
}
