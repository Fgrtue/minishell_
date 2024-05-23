/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 13:09:13 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/11 09:54:44 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
converts the initial portion of the string pointed to by nptr to int
does not detect errors
*/

int	ft_atoi(const char *nptr)
{
	int		flag;
	int		num;
	char	*p;

	flag = 1;
	num = 0;
	p = (char *)nptr;
	while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r' || *p == '\f'
		|| *p == '\v')
		p++;
	if (*p == '-')
		flag = -1;
	if (*p == '+' || *p == '-')
		p++;
	while (*p <= '9' && *p >= '0')
	{
		num = num * 10 + (*p - '0');
		p++;
	}
	return (flag * num);
}

// int	main(void)
// {
// 	char	buffer[] = "  -214748364899 92   +100f";

// 	printf("%d\n", atoi(buffer));
// 	printf("%d\n", ft_atoi(buffer));
// 	return (0);
// }
