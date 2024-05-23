/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 17:53:14 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/10 12:24:12 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The	bzero(void) function erases the data in the n bytes
of the memory starting at the location pointed to by s,
by writing zeros (bytes containing '\0') to that area.
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p++ = '\0';
		n--;
	}
}

// int	main(void)
// {
// 	char	str[] = "This is a sample string";

// 	bzero(str, 6);
// 	printf("%s\n", &str[5]);
// 	printf("%s\n", &str[6]);
// 	return (0);
// }
