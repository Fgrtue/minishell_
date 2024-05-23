/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 14:37:38 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/11/14 15:28:16 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates memory for an array of nmemb elements of size bytes
** initializes all its bits to zero
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	byte_size;

	byte_size = nmemb * size;
	if (size != 0 && byte_size / size != nmemb)
		return (NULL);
	p = malloc(byte_size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, byte_size);
	return (p);
}

// int	main(void)
// {
// 	char	*p;

// 	p = ft_calloc(10, sizeof(char));
// 	printf("%s\n", p);
// 	for (int n = 0; n < 10; n++)
// 			printf("%d ", p[n]);
// 	free(p);
// 	return (0);
// }
