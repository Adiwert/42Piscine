/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:16:09 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/03 17:51:11 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_getnum(char *str, int *sign)
{
	int	i;

	*sign = 1;
	i = 0;
	while (ft_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	i = ft_getnum(str, &sign);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
		}
		else
			break ;
		i++;
	}
	return (result * sign);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("	-42"));
	printf("%d\n", ft_atoi("--+--++-42"));
	printf("%d\n", ft_atoi("  \n+42abc"));
	printf("%d\n", ft_atoi("abc42"));
	printf("%d\n", ft_atoi("   42abc42"));
	printf("%d\n", ft_atoi("2147483648"));
	return (0);
}
*/
