/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 11:13:37 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/12 14:12:55 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** adds the one 'new' at the end of the list
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while ((temp->next) != NULL)
		temp = temp->next;
	temp->next = new;
}

// int	main(void)
// {
// 	t_list	*elem = NULL;
// 	t_list	*new1;
// 	t_list	*new2;
// 	t_list	*temp;

// 	new1 = ft_lstnew("know me");
// 	new2 = ft_lstnew("you dont");
// 	ft_lstadd_back(&elem, new1);
// 	ft_lstadd_back(&elem, new2);
// 	while (elem)
// 	{
// 		printf("Content: %s\n", (char *)(elem->content));
// 		temp = elem;
// 		elem = elem -> next;
// 		free(temp);
// 	}
// 	return (0);
// }