/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 18:24:18 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/12 14:57:39 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** applies function 'f' on each char of the string
** Each character is passed by address to 'f' to be modified
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// void	ft_test(unsigned int i, char *s)
// {
// 	*s = ft_toupper(*s);
// }

// int	main(void)
// {
// 	char	input[] = "This is a sample string!";

// 	ft_striteri(input, ft_test);
// 	printf("%s\n", input);
// 	return (0);
// }