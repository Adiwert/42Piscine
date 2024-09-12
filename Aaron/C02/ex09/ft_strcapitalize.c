/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:23:00 by zlee              #+#    #+#             */
/*   Updated: 2024/08/29 20:20:59 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	char	*temp;
	int		count;

	count = 0;
	temp = str;
	while (str[count] != '\0')
	{
		if ((str[count] >= 'A') && (str[count] <= 'Z'))
		{
			temp[count] += 32;
		}
		count++;
	}
	return (str);
}

int	ft_isletter(int c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	else if (c >= 'A' && c <= 'Z')
		return (0);
	else if (c >= '0' && c <= '9')
		return (0);
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		count;
	int		char_num;
	char	*temp;

	count = 0;
	temp = str;
	ft_strlowcase(temp);
	while (temp[count] != '\0')
	{
		if ((temp[count] >= 'a') && (temp[count] <= 'z'))
		{
			if (count != 0)
			{
				char_num = ft_isletter(temp[count - 1]);
				if (char_num == 1)
					temp[count] = temp[count] - 32;
			}
			else
				temp[count] = temp[count] - 32;
		}
		count++;
	}
	return (str);
}

#include <stdio.h>
int main(void)
{
    char test1[] = "hi 0hello+woRLd";
    ft_strcapitalize(test1);
    printf("%s\n", test1);

}
