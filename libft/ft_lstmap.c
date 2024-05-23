/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 15:34:27 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/11/14 15:30:28 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates 'lst' and applies 'f' on the content of each node.
** Creates a new list resulting of the successive applications of 'f'.
** 'del': to delete the content of a node if needed
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;
	void	*head;

	newlst = NULL;
	head = NULL;
	while (lst != NULL)
	{
		head = f(lst->content);
		if (!head)
		{
			del(head);
			return (NULL);
		}
		temp = ft_lstnew(head);
		if (!temp)
		{
			del(head);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, temp);
		lst = lst->next;
	}
	return (newlst);
}

// void	*ft_strupper(void *s)
// {
// 	char	*p;
// 	int		i;

// 	p = ft_strdup((char *)s);
// 	i = 0;
// 	while (p[i] != '\0')
// 	{
// 		p[i] = ft_toupper(p[i]);
// 		i++;
// 	}
// 	return (p);
// }

// void	delete_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*elem = NULL;
// 	t_list	*temp;
// 	t_list	*newlst;

// 	ft_lstadd_back(&elem, ft_lstnew(ft_strdup("good")));
// 	ft_lstadd_back(&elem, ft_lstnew(ft_strdup("luck")));
// 	newlst = ft_lstmap(elem, ft_strupper, delete_content);
// 	while (elem)
// 	{
// 		printf("Content in elem: %s\n", (char *)(elem->content));
// 		temp = elem;
// 		elem = elem -> next;
// 		free(temp -> content);
// 		free(temp);
// 	}
// 	while (newlst)
// 	{
// 		printf("Content in new: %s\n", (char *)(newlst->content));
// 		temp = newlst;
// 		newlst = newlst -> next;
// 		free(temp -> content);
// 		free(temp);
// 	}
// 	return (0);
// }
