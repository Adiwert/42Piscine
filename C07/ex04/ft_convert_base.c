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

	base_len = ft_strlen(base); // Get the length of the base.
	if (ori_num < 0) // If the number is negative:
	{
		num = -ori_num; // Convert the number to positive.
		len = len + 1; // Increment the length by 1 for the negative sign.
	}
	else
		num = ori_num; // Maintain the number.
	while (num >= base_len) // While the number is larger than or equal to the base (formatted_num will more than one digit):
	{
		num /= base_len; // Divide the number by the base.
		len++; // Increment the length for each division for each digit.
	}
	return (len + 1); // Return the length (with an extra 1 for the '\0').
}

void	ft_putnbr_base(int ori_num, char *base, char *formatted_num) // Converts an integer to a string in a specified base.
{
	int	base_len; // Desired base.
	int	num; // Temporary variable for the number conversion (Avoid modifying the original value of "ori_num").
	int	formatted_num_len;
	int	i; // Index used to place characters in "formatted_num".

	base_len = ft_strlen(base); // Get the length of the base string using ft_strlen().
	formatted_num_len = num_len(ori_num, base, 0); // Calculate the length of the formatted string with num_len().
	formatted_num[formatted_num_len] = '\0'; // Set the end of the string.
	i = formatted_num_len - 1; // Start at the last position of formatted_num.
	num = ori_num; // Initialise the temporary variable.
	if (num < 0)
	{
		formatted_num[0] = '-'; // If num is negative, place a '-' at the beginning.
		num = -num; // Convert num to positive.
	}
	while (num >= base_len) // While the number is larger than or equal to the base (formatted_num will more than one digit):
	{
		formatted_num[i--] = base[num % base_len]; 
		// Digits are placed in reverse order starting from the end of formatted_num (formatted_num[i--]) 
		// by finding the digit in the desired base (base[num % base_len]).
		num /= base_len; // Reduces num by dividing it by the base, to process the next higher place value in the base representation.
	}
	formatted_num[i] = base[num]; // Place the last remaining digit at the final position (Can directly convert)(num < base_len).
}

int	check_overflow(int num, int base_len) // Checks for overflow or underflow conditions during base conversion.
{
	int	max_int;
	int	min_int;

	max_int = 2147483647;
	min_int = -2147483648;
	if (num > max_int || num < min_int)
		return (1); // Indicating overflow or underflow (Based on user input).
	if (num * base_len > max_int || num * base_len < min_int)
		return (1); // Indicating overflow or underflow (After converting to desired base).
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to) // Converts a string number from one base to another base.
{
	char	*formatted_num; // Pointer to the resulting string in the target base.
	int		num; // Temporary variable for the number conversion (Avoid modifying the original value of "ori_num").
	int		formatted_num_len; // Length of the formatted string in desired base.

	if (validbase(base_from) == 0 || validbase(base_to) == 0) // Ensure both bases are valid. If not, return NULL.
		return (NULL);
	num = ft_atoi_base(nbr, base_from); // Convert ori_num from base_from to an integer.
	if (check_overflow(num, ft_strlen(base_to))) //  If overflow is detected, return NULL.
		return (NULL);
	formatted_num_len = num_len(num, base_to, 0); // Calculate the length of the formatted string.
	formatted_num = (char *)malloc(formatted_num_len + 1); // Allocate memory for the formatted string.
	if (formatted_num == NULL) // If memory allocation fails, return NULL.
		return (NULL);
	ft_putnbr_base(num, base_to, formatted_num); // Convert num to the desired base.
	formatted_num[formatted_num_len] = '\0'; // Ensure the formatted string is properly null-terminated.
	return (formatted_num); // Return the formatted string.
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
