/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_free.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 11:45:07 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/12/15 14:29:48 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* concatenate the line with buffer (buffer cannot be NULL) */
/* s2 not being freed and can not be NULL*/
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*sjoin;
	size_t	i;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	sjoin = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!sjoin)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i] != '\0')
		sjoin[i] = s1[i];
	while (s2[i - ft_strlen(s1)] != '\0')
	{
		sjoin[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	sjoin[i] = '\0';
	free(s1);
	return (sjoin);
}

/* free s1 and s2 */
char	*ft_strjoin_free_d(char *s1, char *s2)
{
	char	*sjoin;

	sjoin = ft_strjoin_free(s1, s2);
	if (!sjoin)
	{
		free(s2);
		return (NULL);
	}
	if (s2)
		free(s2);
	return (sjoin);
}
