/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 18:27:52 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/10 16:35:54 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
copies n bytes from src to dest.
The memory areas must not overlap
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char	str1[] = "almost every programmer should know memset!";
// 	char	str2[] = "who are you and how are you";

// 	ft_memcpy(str2, str1, 6);
// 	printf("%s\n", str2);
// }
