/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 10:58:05 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/11/10 09:29:44 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns the last node of the list
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while ((lst->next) != NULL)
		lst = lst->next;
	return (lst);
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
// 	temp = ft_lstlast(elem);
// 	printf("%s\n", (char *)(elem -> content));
// 	while (elem)
// 	{
// 		temp = elem;
// 		elem = elem -> next;
// 		free(temp);
// 	}
// 	return (0);
// }