/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jessie <jessie@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 21:55:08 by jessie        #+#    #+#                 */
/*   Updated: 2023/11/24 09:37:00 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates and returns a copy of 's1'
** with the characters 'set removed from
** the begining and the end of the 's1'
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	size_t	len;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	while (ft_strchr(set, *s1) != NULL && *s1 != '\0')
		s1++;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len - 1]) != NULL && len > 0)
		len--;
	strim = (char *)malloc((len + 1) * sizeof(char));
	if (!strim)
		return (NULL);
	ft_strlcpy(strim, s1, (len + 1));
	free((char *)s1);
	return (strim);
}

// int	main(void)
// {
// 	char	s[] = "! Hello World! !";
// 	char	set[] = ' !';
// 	char	*strim;

// 	strim = ft_strtrim(s, set);
// 	printf("%s\n", strim);
// 	free(strim);
// 	return (0);
// }