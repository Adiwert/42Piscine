/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:49:55 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/11 15:00:57 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft.h"

void	test_ft_putchar(void)
{
	printf("Testing ft_putchar:\n");
	ft_putchar('A');
	ft_putchar('\n');
}

void	test_ft_swap(void)
{
	int	a;
	int	b;

	a = 2;
	b = 4;
	printf("Testing ft_swap:\n");
	printf("Before swap: a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("After swap: a = %d, b = %d\n", a, b);
}

void	test_ft_putstr(void)
{
	printf("Testing ft_putstr:\n");
	ft_putstr("Hello, World!\n");
}

void	test_ft_strlen(void)
{
	char	str[] = "Test string";

	printf("Testing ft_strlen:\n");
	printf("Length of \"%s\" is %d\n", str, ft_strlen(str));
}

void	test_ft_strcmp(void)
{
	char	s1[] = "Hello";
	char	s2[] = "Hella";

	printf("Testing ft_strcmp:\n");
	printf("Comparing \"%s\" and \"%s\": %d\n", s1, s2, ft_strcmp(s1, s2));
}

int	main(void)
{
	test_ft_putchar();
	printf("\n");
	test_ft_swap();
	printf("\n");
	test_ft_putstr();
	printf("\n");
	test_ft_strlen();
	printf("\n");
	test_ft_strcmp();
	return (0);
}
