/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mahf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:14:07 by aal-mahf          #+#    #+#             */
/*   Updated: 2024/08/27 15:43:56 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	char	ne;
	char	po;

	ne = 'N';
	po = 'P';
	if (n < 0)
	{
		write (1, &ne, 1);
	}
	else
	{
		write (1, &po, 1);
	}
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
