/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_list_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/22 16:19:22 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/23 13:37:53 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_lexer(t_global *global)
{
	t_lexer	*lex;

	lex = global->lexer;
	if (!lex || (lex->state == 0 && lex->token == PIPE_LINE)
		|| (ft_lexlast(lex)->state == 0 && ft_lexlast(lex)->token == PIPE_LINE))
		return (ft_error(global, "Syntax error", 2));
	while (lex)
	{
		if (lex->state == 0 && (lex->token == REDIR_IN || lex->token == 62
				|| lex->token == HERE_DOC || lex->token == DREDIR_OUT))
		{
			if (!lex->next || (lex->next->token != WORD
					&& lex->next->token != ENV))
				return (ft_error(global, "Syntax error", 2));
		}
		lex = lex->next;
	}
	return (0);
}

t_lexer	*ft_lexnew(char *content, int token)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(t_lexer));
	if (lexer == NULL)
		return (NULL);
	lexer->content = content;
	lexer->len = ft_strlen(content);
	lexer->token = token;
	lexer->state = GENERAL;
	lexer->prev = NULL;
	lexer->next = NULL;
	return (lexer);
}

void	ft_lexaddfront(t_lexer **lexer, t_lexer *new)
{
	if (new == NULL)
	{
		return ;
	}
	new->next = *lexer;
	if (*lexer != NULL)
	{
		(*lexer)->prev = new;
	}
	*lexer = new;
}

void	ft_lexaddback(t_lexer **lexer, t_lexer *new)
{
	t_lexer	*last;

	last = NULL;
	if ((*lexer) == NULL)
		ft_lexaddfront(lexer, new);
	else
	{
		last = ft_lexlast(*lexer);
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}
