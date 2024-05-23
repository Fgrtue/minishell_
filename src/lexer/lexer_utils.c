/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkopnev <kkopnev@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/15 14:48:02 by kkopnev       #+#    #+#                 */
/*   Updated: 2024/01/22 16:21:18 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	polish_lexer(t_lexer **lexer)
{
	t_lexer	*lex;
	t_lexer	*tmp;

	lex = *lexer;
	while (lex)
	{
		if ((lex->token == QUOTE || lex->token == DOUBLE_QUOTE)
			&& lex->state == GENERAL)
		{
			tmp = lex;
			lex = lex->next;
			ft_lexdel(ft_lexretract(lexer, tmp));
		}
		else if ((lex->token == REDIR_IN || lex->token == REDIR_OUT
				|| lex->token == DREDIR_OUT || lex->token == HERE_DOC)
			&& lex->next && lex->next->token == WHITE_SPACE
			&& lex->next->state == GENERAL)
		{
			tmp = lex->next;
			ft_lexdel(ft_lexretract(lexer, tmp));
		}
		else
			lex = lex->next;
	}
}

t_lexer	*find_next_quote(t_lexer *node)
{
	t_lexer	*next_quote;

	if (!node)
		return (NULL);
	next_quote = node->next;
	while (next_quote && next_quote->token != node->token)
		next_quote = next_quote->next;
	return (next_quote);
}

void	add_empty(t_lexer **lexer)
{
	t_lexer	*lex_ptr;
	t_lexer	*tmp;

	if (!*lexer)
		return ;
	lex_ptr = *lexer;
	while (lex_ptr)
	{
		if (lex_ptr->token == QUOTE || lex_ptr->token == DOUBLE_QUOTE)
		{
			tmp = find_next_quote(lex_ptr);
			if (tmp && lex_ptr->next == tmp)
				ft_lexinsert(lexer, lex_ptr, tmp, ft_lexnew(ft_strdup("\0"),
						WORD));
			lex_ptr = tmp;
			if (lex_ptr)
				lex_ptr = lex_ptr->next;
		}
		else
			lex_ptr = lex_ptr->next;
	}
}

int	is_env(t_lexer *node)
{
	char	*content;

	content = node->content;
	if (content && ft_strlen(content) == 1)
		return (WORD);
	while (*content)
	{
		if (*content == ENV)
			return (ENV);
		content++;
	}
	return (WORD);
}

void	set_env(t_lexer *lexer)
{
	int	flag;

	flag = 0;
	while (lexer)
	{
		if (lexer->token == WORD && lexer->state != IN_QUOTE && flag == 0)
			lexer->token = is_env(lexer);
		if (lexer->token != WHITE_SPACE)
			flag = 0;
		if (lexer->token == HERE_DOC)
			flag = 1;
		lexer = lexer->next;
	}
}
