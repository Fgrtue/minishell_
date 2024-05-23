/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 14:23:47 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/10/12 16:17:34 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates the list and applies the 'f' on the content of each node
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// void	ft_strupper(void *s)
// {
// 	char	*p;

// 	p = (char *)s;
// 	while (*p != '\0')
// 	{
// 		*p = ft_toupper(*p);
// 		p++;
// 	}
// }

// int	main(void)
// {
// 	t_list	*elem = NULL;
// 	t_list	*temp;

// 	ft_lstadd_back(&elem, ft_lstnew(ft_strdup("good")));
// 	ft_lstadd_back(&elem, ft_lstnew(ft_strdup("luck")));
// 	ft_lstiter(elem, ft_strupper);
// 	while (elem)
// 	{
// 		printf("Content: %s\n", (char *)(elem->content));
// 		temp = elem;
// 		elem = elem -> next;
// 		free(temp -> content);
// 		free(temp);
// 	}
// 	return (0);
// }