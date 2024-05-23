/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 15:22:51 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/12/05 17:24:18 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
returns a pointer to a new string which is a duplicate of s
*/

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// int	main(void)
// {
// 	char	*s1 = "Bonjour!";
// 	char	*s2;

// 	s2 = ft_strdup(s1);
// 	printf("%s\n", s2);
// 	printf("%c\n", s2[7]);
// 	free(s2);
// 	return (0);
// }
