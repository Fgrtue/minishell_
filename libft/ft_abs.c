/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/24 15:08:36 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/11/30 14:38:52 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int x)
{
	if (x >= 0)
		return (x);
	return (-1 * x);
}

int	ft_max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

int	ft_min(int x, int y)
{
	if (x <= y)
		return (x);
	return (y);
}
