/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 14:17:02 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/10 17:18:42 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates and returns a string representing the int received as an argument.
** negative number must be handled
*/

/* count the digit of integer n */
static int	count_digit(int n)
{
	int	digit;

	digit = 0;
	while (n != 0)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = (n <= 0) + count_digit(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_itoa(-481513);
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
