/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 09:09:00 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/12 09:39:14 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates and returns a new node.
** The member variable 'content' is initialized with the value of the
** parameter 'content'. The variable 'next' is initialized to NULL*/

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

// int	main(void)
// {
// 	t_list	*elem;

// 	elem = ft_lstnew("you dont know me");
// 	printf("Content: %s\n", (char *)(elem -> content));
// 	free(elem);
// 	return (0);
// }