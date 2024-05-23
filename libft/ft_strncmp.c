/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 16:25:08 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/12/20 21:41:49 by kkopnev       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i] || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	char	str1[6] = "happy";
// 	char	str2[9] = "happy123";
// 	char	str3[9] = "";

// 	printf("%d\n", strncmp(str2, str3, 5));
// 	printf("%d\n", ft_strncmp(str2, str3, 5));
// 	return (0);
// }