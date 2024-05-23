/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 11:49:17 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/11 16:37:33 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
locates the *first* occurrence of the nul-terminated *little* in *big*,
but not more than len characters are searched
**characters that appear after '\0' are not searched
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*p_little;
	char	*p_big;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i + ft_strlen(little) <= len && big + i)
	{
		p_little = (char *)little;
		p_big = (char *)big + i;
		while (*p_big == *p_little && *p_little && *p_big)
		{
			p_little++;
			p_big++;
		}
		if (*p_little == '\0')
			return ((char *)big + i);
		if (*p_big == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "This is a sample string.";

// 	printf("%s\n", ft_strnstr(str, "This", 4));
// 	printf("%s\n", strnstr(str, "This", 4));
// 	return (0);
// }
