/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 12:44:11 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/12 14:23:03 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** deletes and frees the given node and every successor of it
** finally the pointer to the list must be set to NULL
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	if (!lst || !*lst)
		return ;
	while (*lst != NULL)
	{
		elem = *lst;
		*lst = (*lst)->next;
		del(elem->content);
		free(elem);
	}
}

// void	delete_content(void *content)
// {
// 	free(content);
// 	//free the content only when you use malloc for this content
// 	//eg. ft_strdup("one")
// }

// int	main(void)
// {
// 	t_list	*lst = NULL;
// 	t_list	*node1 = ft_lstnew(ft_strdup("one"));
// 	t_list	*node2 = ft_lstnew(ft_strdup("two"));

// 	ft_lstadd_back(&lst, node1);
// 	ft_lstadd_back(&lst, node2);
// 	ft_lstclear(&lst, delete_content);
// 	return (0);
// }