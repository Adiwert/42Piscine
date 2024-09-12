/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:56:29 by zlee              #+#    #+#             */
/*   Updated: 2024/08/27 14:38:58 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if ((str[count] >= 48) && (str[count] <= 57))
			count++;
		else
			return (0);
	}
	if (count == 0)
		return (1);
	else
		return (1);
}

#include <stdio.h>
 int main(void)
{
    char test1[] = "53656346";
    char test2[] = "erwr345";
    char test3[] = "test";
    
    int num1 = ft_str_is_numeric(test1);
    int num2 = ft_str_is_numeric(test2);
    int num3 = ft_str_is_numeric(test3);
    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
}
