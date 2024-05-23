/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 09:39:31 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/12 10:41:03 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** adds the node 'new' at the beginning of the list
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
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
// 	while (elem)
// 	{
// 		printf("Content: %s\n", (char *)(elem->content));
// 		temp = elem;
// 		elem = elem -> next;
// 		free(temp);
// 	}
// 	return (0);
// }