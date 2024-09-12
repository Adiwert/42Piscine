/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:07:08 by zlee              #+#    #+#             */
/*   Updated: 2024/08/27 14:40:01 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if ((str[count] >= 'a') && (str[count] <= 'z'))
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

    int num1 = ft_str_is_lowercase(test1);
    int num2 = ft_str_is_lowercase(test2);
    int num3 = ft_str_is_lowercase(test3);
    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
}
