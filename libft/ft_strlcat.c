/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 13:20:59 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/13 09:12:07 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
appends the nul-term src to the end of dst
append at most size-strlen(dst)-1, nul-term the result
return: if size<length(dst) return size+length(src)
		else length(dst+src)
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	while (src[i] && i < size - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}

// int	main(void)
// {
// 	char	dest1[25] = "What a nice day!";
// 	char	dest2[25] = "What a nice day!";
// 	char	*src = "dadas";

// 	size_t len1 = strlcat(dest1, src, 4);
// 	size_t len2 = ft_strlcat(dest2, src, 4);
// 	printf("return: %zu; dest1: %s\n", len1, dest1);
// 	printf("return: %zu; dest2: %s\n", len2, dest2);
// 	return (0);
// }
