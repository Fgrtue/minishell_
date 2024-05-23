/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 11:05:17 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/12/14 18:54:51 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates and returns an array of strings obtained by
** splitting 's' using 'c' as a delimiter
** the array must end with a NULL pointer
*/

/* get the length of the string array delimited by 'c' */
int	arr_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			len++;
		while (*s && *s != c)
			s++;
	}
	return (len);
}

/* get the length of the string */
static int	str_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

/* free the string array and all the memory being allocated */
char	**free_arr(char **str_arr)
{
	int	i;

	i = 0;
	if (!str_arr)
		return (NULL);
	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = arr_len(s, c);
	str_arr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!str_arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (*s && *s == c)
			s++;
		str_arr[i] = (char *)malloc(sizeof(char) * (str_len(s, c) + 1));
		if (!str_arr[i])
			return (free_arr(str_arr));
		ft_strlcpy(str_arr[i], s, (str_len(s, c) + 1));
		while (*s && *s != c)
			s++;
		i++;
	}
	str_arr[len] = NULL;
	return (str_arr);
}

// int	main(void)
// {
// 	char	s[] = "--1-2--3---4----5-----42";
// 	char	**str_arr;

// 	str_arr = ft_split(s, '-');
// 	for (int i = 0; str_arr[i]; i++)
// 	{
// 		printf("%d %s\n",i, str_arr[i]);
// 		free(str_arr[i]);
// 	}
// 	free(str_arr);
// 	return (0);
// }
