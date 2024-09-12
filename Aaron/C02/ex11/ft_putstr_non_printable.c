/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:16:19 by zlee              #+#    #+#             */
/*   Updated: 2024/08/27 14:47:47 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_div_mod(char a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

void	ft_int_to_hex(char c)
{
	int	store[2];
	int	*div_ptr;
	int	*mod_ptr;
	int	count;

	count = 0;
	div_ptr = &store[0];
	mod_ptr = &store[1];
	ft_div_mod(c, 16, div_ptr, mod_ptr);
	while (count < 2)
	{
		if (store[count] >= 10)
			store[count] = store[count] + 87;
		else
			store[count] = store[count] + 48;
		ft_putchar(store[count]);
		count++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if ((str[count] >= 32) && (str[count] <= 126))
			ft_putchar(str[count]);
		else
		{
			ft_putchar('\\');
			ft_int_to_hex(str[count]);
		}
		count++;
	}
}

#include <stdio.h>
int main(void)
{
    char test1[] = "I am a\n good guy";
    ft_putstr_non_printable(test1);
}
