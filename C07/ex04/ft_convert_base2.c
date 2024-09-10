/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstewart <tstewart@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:08:06 by tstewart          #+#    #+#             */
/*   Updated: 2024/09/09 17:54:25 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0') // Loop through the string until the null terminator ('\0') is found.
	{
		i++; // Increment the counter for each character.
	}
	return (i); // Return the total number of characters in the string (length).
}

int	validbase(char *str)
{
	int	i; // Character Index
	int	j; // Compare Index

	if (ft_strlen(str) <= 1) // A valid base must have more than one character.
		return (0);
	i = 0;
	while (str[i] != '\0') // Loop through each character in the base string.
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == ' '
			|| (str[i] >= 9 && str[i] <= 13)) // Invalid characters for a base: '+', '-', space, or control characters.
			return (0);
		j = i + 1;
		while (str[j] != '\0') // Check for duplicate characters.
		{
			if (str[i] == str[j]) // If the current character is found duplicate, the base is invalid.
				return (0);
			j++;
		}
		i++;
	}
	return (i); // Return the length of the base if valid.
}

int	map_base(char str, char *base)
{
	int	num;

	num = 0;
	while (base[num] != '\0') // Loop through the base string.
	{
		if (str == base[num]) // If the character `str` matches the current character in the base, return its index.
		{
			return (num); // Map and return the index of the character in the base.
		}
		num++;
	}
	return (-1); // If the character is not found in the base or invalid, the loop breaks and conversion stops.
}

int	spaces_and_sign(char *str, int *ptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) // Skip leading whitespaces and control characters.
		i++;
	while (str[i] == '+' || str[i] == '-') // Handle '+' and '-' signs.
	{
		if (str[i] == '-')
			sign *= -1; // Flip the sign if a '-' is encountered.
		i++;
	}
	*ptr = i; // Update the index pointer to the first non-digit character.
	return (sign); // Return the sign: positive or negative.
}

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			sign;
	int			num;
	int			base_len;
	int			current_digit;

	i = 0;
	num = 0;
	base_len = ft_strlen(base); // Get the length of the base.
	if (validbase(base) < 2) // Ensure the base is valid (has at least two characters).
		return (0);
	sign = spaces_and_sign(str, &i); // Get the sign of the number and skips the spaces.
	current_digit = map_base(str[i], base); // Map the first character in `str` to the corresponding digit in the base.
	while (current_digit != -1) // While valid digits from the base are found:
	{
		num = (num * base_len) + current_digit; // Build the number by multiplying index and base length, then adding the current digit.
		i++;
		current_digit = map_base(str[i], base); // Map the next character to its digit until '\0' (return -1 in map_base()).
	}
	return (num * sign); // Return the result multiplied by the sign (positive or negative).
}
