/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 11:31:58 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/06 16:42:32 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
copies size-1 from nul-ter src to dst
nul-terminate the result
return: total length of string, aka src
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	int		len1;
// 	int		len2;
// 	char	str[] = "Tha";
// 	char	dest1[10];
// 	char	dest2[10];

// 	len1 = strlcpy(dest1, str, 2);
// 	printf("strlcpy\nCopied '%s' into '%s', length %d\n", str, dest1, len1);
// 	len2 = ft_strlcpy(dest2, str, 2);
// 	printf("ft_strlcpy\nCopied '%s' into '%s', length %d\n", str, dest2, len2);
// }
