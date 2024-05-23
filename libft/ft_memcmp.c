/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 10:58:26 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/10 16:35:45 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
compares the first n bytes (unsigned char) of memory areas s1 and s2
different from strncmp: it does not stop comparing after finding a
null character.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str1[] = "abcdefg";
// 	char	str2[] = "abcdefghijk";

// 	printf("%d\n", ft_memcmp(str1, str2, sizeof(str1)-1));
// 	printf("%d\n", memcmp(str1, str2, sizeof(str1)-1));
// 	return (0);
// }
