/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:44:40 by vlow              #+#    #+#             */
/*   Updated: 2024/09/04 20:46:01 by tstewart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cond(char c)
{
	int	iswsp;
	int	isnb;
	int	issn;
	int	isal;

	isnb = (c >= '0' && c <= '9');
	iswsp = (c == ' ' || (c >= 9 && c <= 13));
	issn = (c == '+' || c == '-' );
	isal = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	if (iswsp)
		return (1);
	if (issn)
		return (2);
	if (isnb)
		return (3);
	if (isal)
		return (4);
	return (0);
}

int	isvalid(char c, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx] != '\0')
	{
		if (c == base[idx])
			return (idx);
		idx++;
	}
	return (-1);
}

int	base_check(char *base)
{
	int	cnt;
	int	bcnt;

	bcnt = 0;
	if (base[0] == '\0')
		return (1);
	while (*base)
	{
		cnt = 0;
		while (*base == base[++cnt] && base[++cnt] != '\0')
			return (1);
		if (*base == '+' || *base == '-')
			return (1);
		bcnt++;
		base++;
	}
	return (bcnt);
}

void	parse_valid(char *str, char *base, int *amt)
{
	while (*str && (cond(*str) == 3 || cond(*str) == 4))
	{
		if (isvalid(*str, base) != -1)
		{
			*amt = *amt * base_check(base) + isvalid(*str, base);
			str++;
		}
		else
			break ;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	cnt;
	int	amt;

	if (base_check(base) <= 1)
		return (0);
	cnt = 0;
	amt = 0;
	while (*str && cond(*str) == 1)
		str++;
	while (*str && cond(*str) == 2)
	{
		if (*str == '-')
			cnt++;
		str++;
	}
	parse_valid(str, base, &amt);
	if (cnt % 2 == 1)
		return (-amt);
	else
		return (amt);
}

/*
#include <stdio.h>

int main(void)
{
    // Test cases
    char *str1 = "   --+--1234";
    char *str2 = "10101";
    char *str3 = "1a3b";
    char *str4 = "FF";
    char *str5 = "-10101";
    char *str6 = "  -+--7f";

    // Different bases
    char *base2 = "01";          // Binary
    char *base10 = "0123456789"; // Decimal
    char *base16 = "0123456789ABCDEF"; // Hexadecimal
    char *base8 = "01234567"; // Octal
    char *invalid_base = "01234+"; // Invalid base with '+'

    // Testing with valid base and strings
    printf("'%s' in base 10 is: %d\n", str1, ft_atoi_base(str1, base10));   // Expecting: -1234
    printf("'%s' in base 2 is: %d\n", str2, ft_atoi_base(str2, base2));     // Expecting: 21
    printf("'%s' in base 16 is: %d\n", str3, ft_atoi_base(str3, base16));   // Expecting: 67003
    printf("'%s' in base 16 is: %d\n", str4, ft_atoi_base(str4, base16));   // Expecting: 255
    printf("'%s' in base 2 is: %d\n", str5, ft_atoi_base(str5, base2));     // Expecting: -21
    printf("'%s' in base 16 is: %d\n", str6, ft_atoi_base(str6, base16));   // Expecting: -127

    // Testing with invalid base
    printf("'%s' in invalid base returns: %d\n", str2, ft_atoi_base(str2, invalid_base)); // Expecting: 0

    return 0;
}
*/
