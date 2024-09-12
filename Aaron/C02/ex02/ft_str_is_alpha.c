/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:59:12 by zlee              #+#    #+#             */
/*   Updated: 2024/08/29 14:50:40 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			i++;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			i++;
		else
			return (0);
	}
	if (i == 0)
		return (1);
	else
		return (1);
}
 #include <stdio.h>
int main(void)
{
    int num = 0;
    char test1[] = "testtest";
    char test2[] = "TESTtestTES";
    char test3[] = "setsetet3test";

    int num1 = ft_str_is_alpha(test1);
    int num2 = ft_str_is_alpha(test2);
    int num3 = ft_str_is_alpha(test3);
    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
}
