/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:49:39 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/09 20:31:51 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	validbase(char *str);
int	map_base(char str, char *base);
int	spaces_and_sign(char *str, int *ptr);
int	ft_atoi_base(char *str, char *base);

int	num_len(int ori_num, char *base, int len)
{
	int	base_len;
	int	num;

	base_len = ft_strlen(base);
	if (ori_num < 0)
	{
		num = -ori_num;
		len++;
	}
	else
		num = ori_num;
	while (num >= base_len)
	{
		num /= base_len;
		len++;
	}
	return (len + 1);
}

void	ft_putnbr_base(int ori_num, char *base, char *formatted_num)
{
	int	base_len;
	int	num;
	int	formatted_num_len;
	int	i;

	base_len = ft_strlen(base);
	formatted_num_len = num_len(ori_num, base, 0);
	formatted_num[formatted_num_len] = '\0';
	i = formatted_num_len - 1;
	num = ori_num;
	if (num < 0)
	{
		formatted_num[0] = '-';
		num = -num;
	}
	while (num >= base_len)
	{
		formatted_num[i--] = base[num % base_len];
		num /= base_len;
	}
	formatted_num[i] = base[num];
}

int	check_overflow(int num, int base_len)
{
	int	max_int;
	int	min_int;

	max_int = 2147483647;
	min_int = -2147483648;
	if (num > max_int || num < min_int)
		return (1);
	if (num > max_int / base_len || num < min_int / base_len)
		return (1);
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*formatted_num;
	int		num;
	int		formatted_num_len;

	if (validbase(base_from) == 0 || validbase(base_to) == 0)
	{
		return (NULL);
	}
	num = ft_atoi_base(nbr, base_from);
	if (check_overflow(num, ft_strlen(base_to)))
		return (NULL);
	formatted_num_len = num_len(num, base_to, 0);
	formatted_num = (char *)malloc(formatted_num_len + 1);
	if (formatted_num == NULL)
	{
		return (NULL);
	}
	ft_putnbr_base(num, base_to, formatted_num);
	formatted_num[formatted_num_len] = '\0';
	return (formatted_num);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*result;

	result = ft_convert_base("-42", "0123456789", "01");
	if (result != NULL)
	{
		printf("Result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Conversion failed\n");
	}
	return (0);
}
*/
