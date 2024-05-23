/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 15:37:16 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/11/23 13:37:43 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
returns a pointer to the *first* occurence of the c in s
c means character
*/

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	if (!s)
		return (NULL);
	while (*p && *p != (char)c)
		p++;
	if (*p == (char)c)
		return (p);
	return (NULL);
}

// int	main(void)
// {
// 	char	*str = NULL;
// 	char	*pch;

// 	pch = strchr(str, 's');
// 	while (pch)
// 	{
// 		printf("found 's' at %ld\n", pch-str+1);
// 		pch = strchr(pch+1, 's');
// 	}
// 	return (0);
// }
