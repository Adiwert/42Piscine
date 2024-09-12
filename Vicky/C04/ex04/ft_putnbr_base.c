/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:38:40 by vlow              #+#    #+#             */
/*   Updated: 2024/09/03 14:41:03 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	base_check(char *base)
{
	int	cnt;
	int	bcnt;

	bcnt = 0;
	if (base[0] == '\0')
		return (1);
	while (*base)
	{
		cnt = 0;
		while (*base == base[++cnt] && base[++cnt] != '\0')
			return (1);
		if (*base == '+' || *base == '-')
			return (1);
		bcnt++;
		base++;
	}
	return (bcnt);
}

void	ft_putnbr_base(int nb, char *base)
{
	int				amt;
	unsigned int	val;

	amt = base_check(base);
	if (amt < 2)
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		val = (unsigned)(-nb);
	}
	else
	{
		val = (unsigned)(nb);
	}
	if (val >= (unsigned)(amt))
		ft_putnbr_base(val / amt, base);
	ft_putchar(base[val % amt]);
}
