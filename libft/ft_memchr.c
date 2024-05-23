/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 10:07:06 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/10 16:37:38 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Searches within the first n bytes of the block of memory pointed
by s for the first occurrence of c (interpreted as an unsigned char)
and returns a pointer to it.
note** strchr takes string only
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return (&p[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*p;
// 	char	str[] = "Example";

// 	p = ft_memchr(str, 'p', 7);
// 	printf("found at : %ld\n", p-str+1);
// 	return (0);
// }
