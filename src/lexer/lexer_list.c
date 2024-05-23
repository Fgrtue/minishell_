/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkopnev <kkopnev@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 12:50:39 by kkopnev       #+#    #+#                 */
/*   Updated: 2024/01/22 16:20:37 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_lexer	*ft_lexlast(t_lexer *lexer)
{
	if (lexer == NULL)
		return (NULL);
	while (lexer->next != NULL)
		lexer = lexer->next;
	return (lexer);
}

void	ft_lexdel(t_lexer *node)
{
	free(node->content);
	free(node);
}

/* clearn from beginning */
void	ft_lexclean(t_lexer *lexer)
{
	t_lexer	*temp;

	while (lexer && lexer->prev)
		lexer = lexer->prev;
	while (lexer)
	{
		temp = lexer;
		lexer = lexer->next;
		ft_lexdel(temp);
	}
}

void	ft_lexinsert(t_lexer **lexer, t_lexer *prev, t_lexer *next,
		t_lexer *node)
{
	if (!node)
		return ;
	if (!prev && !next)
		return ;
	else if (!prev)
		ft_lexaddfront(lexer, node);
	else if (!next)
		ft_lexaddback(lexer, node);
	else
	{
		prev->next = node;
		node->prev = prev;
		node->next = next;
		next->prev = node;
	}
}

t_lexer	*ft_lexretract(t_lexer **lexer, t_lexer *node)
{
	if (!node)
		return (NULL);
	if (node->prev != NULL && node->next != NULL)
	{
		(node->prev)->next = node->next;
		(node->next)->prev = node->prev;
	}
	else if (node->next == NULL && node->prev != NULL)
		(node->prev)->next = NULL;
	else if (node->prev == NULL && node->next != NULL)
	{
		(node->next)->prev = NULL;
		*lexer = node->next;
	}
	else
		*lexer = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
