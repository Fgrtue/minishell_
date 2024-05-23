/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 16:12:36 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/11 16:25:54 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
returns a pointer to the *last* occurrence of the c in s
mind the difference with strchr
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (len > 0)
	{
		len--;
		if (s[len] == (char)c)
			return ((char *)s + len);
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "This is a sample string";
// 	char	*pch;
// 	char	*pch2;

// 	pch = ft_strrchr(str, 'a'+256);
// 	pch2 = strrchr(str, 'a'+256);
// 	printf("%c\n", 'a' + 256);
// 	printf("found last 's' at %ld\n", pch-str+1);
// 	printf("found last 's' at %ld\n", pch2-str+1);
// 	return (0);
// }
