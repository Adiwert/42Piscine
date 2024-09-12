/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:11:38 by zlee              #+#    #+#             */
/*   Updated: 2024/08/27 14:40:36 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if ((str[count] >= 'A') && (str[count] <= 'Z'))
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
    char test1[] = "sfgfdhsfdh";
    char test2[] = "AAAgesesg";
    char test3[] = "AAA";
    
    int num1 = ft_str_is_uppercase(test1);
    int num2 = ft_str_is_uppercase(test2);
    int num3 = ft_str_is_uppercase(test3);
    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
}
