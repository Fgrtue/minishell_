/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 10:41:22 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/12 10:57:48 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** counts the number of nodes in a list
*/

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

// int	main(void)
// {
// 	t_list	*elem = NULL;
// 	t_list	*new1;
// 	t_list	*new2;
// 	t_list	*temp;

// 	new1 = ft_lstnew("know me");
// 	new2 = ft_lstnew("you dont");
// 	ft_lstadd_front(&elem, new1);
// 	ft_lstadd_front(&elem, new2);
// 	printf("%d\n", ft_lstsize(elem));
// 	while (elem)
// 	{
// 		temp = elem;
// 		elem = elem -> next;
// 		free(temp);
// 	}
// 	return (0);
// }