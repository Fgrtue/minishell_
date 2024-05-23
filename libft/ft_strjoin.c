/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jessie <jessie@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 16:09:33 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/12/12 11:44:08 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates and returns a new string, which is
** result of the concatenation of 's1' and 's2'
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	int		i;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	sjoin = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!sjoin)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		sjoin[i] = s1[i];
	while (s2[i - ft_strlen(s1)] != '\0')
	{
		sjoin[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	sjoin[i] = '\0';
	return (sjoin);
}

// int	main(void)
// {
// 	char	s1[] = "abcde";
// 	char	s2[] = "";

// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }