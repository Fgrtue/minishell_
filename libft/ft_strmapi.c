/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 16:29:42 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/10 16:36:09 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** applies the function 'f' to each character of the 's'
** passing its index as first argument to create a new string
** resulting from successive applications of 'f'
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (!s || !f)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	ft_test(unsigned int i, char c)
// {
// 	return (ft_toupper(c));
// }

// int	main(void)
// {
// 	char	input[] = "This is a sample string!";
// 	char	*result;

// 	result = ft_strmapi(input, ft_test);
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
