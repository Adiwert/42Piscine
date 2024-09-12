/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:15:25 by zlee              #+#    #+#             */
/*   Updated: 2024/08/29 15:08:46 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if ((str[count] >= 32) && (str[count] < 127))
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
    char test3[] = "\n";
    
    int num1 = ft_str_is_printable(test1);
    int num2 = ft_str_is_printable(test2);
    int num3 = ft_str_is_printable(test3);
    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
}
