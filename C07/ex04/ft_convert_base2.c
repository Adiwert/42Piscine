/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:08:06 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/09 17:54:25 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	validbase(char *str)
{
	int	i;
	int	j;

	if (ft_strlen(str) <= 1)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' '
			|| (str[i] >= 9 && str[i] <= 13))
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	map_base(char str, char *base)
{
	int	num;

	num = 0;
	while (base[num] != '\0')
	{
		if (str == base[num])
		{
			return (num);
		}
		num++;
	}
	return (-1);
}

int	spaces_and_sign(char *str, int *ptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*ptr = i;
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			sign;
	int			num;
	int			base_len;
	int			current_digit;

	i = 0;
	num = 0;
	base_len = ft_strlen(base);
	if (validbase(base) < 2)
		return (0);
	sign = spaces_and_sign(str, &i);
	current_digit = map_base(str[i], base);
	while (current_digit != -1)
	{
		num = (num * base_len) + current_digit;
		i++;
		current_digit = map_base(str[i], base);
	}
	return (num * sign);
}
