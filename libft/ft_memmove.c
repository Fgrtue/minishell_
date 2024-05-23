/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 10:21:26 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/10 12:14:49 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
same as memcpy except the memory areas may overlap
the difference from memcpy is to copy from the end of src
*/

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	if (dst > src)
	{
		while (n > 0)
		{
			n--;
			*((unsigned char *)dst + n) = *((unsigned char *)src + n);
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char str[] = "memmove can be very useful......";

// 	memmove (str+20,str+15,11);
// 	puts (str);
//	return (o);
// }
