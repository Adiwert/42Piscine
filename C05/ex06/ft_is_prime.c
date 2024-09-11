/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:44:57 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/04 21:23:38 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

/*
int	main(void)
{
	int	n;

	n = 2;
	printf("Is %d a prime number? %s\n", n, ft_is_prime(n) ? "Yes" : "No");
	n = 0;
	printf("Is %d a prime number? %s\n", n, ft_is_prime(n) ? "Yes" : "No");
	n = 42;
	printf("Is %d a prime number? %s\n", n, ft_is_prime(n) ? "Yes" : "No");
	n = -42;
	printf("Is %d a prime number? %s\n", n, ft_is_prime(n) ? "Yes" : "No");	
	n = 97;
	printf("Is %d a prime number? %s\n", n, ft_is_prime(n) ? "Yes" : "No");
	return (0);
}
*/
