/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 11:09:00 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/22 15:34:58 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	lexer_setstate(t_lexer *lexer)
{
	while (lexer)
	{
		if (lexer->token == DOUBLE_QUOTE)
		{
			lexer = lexer->next;
			while (lexer && lexer->token != DOUBLE_QUOTE)
			{
				lexer->state = IN_DQUOTE;
				lexer = lexer->next;
			}
		}
		else if (lexer->token == QUOTE)
		{
			lexer = lexer->next;
			while (lexer && lexer->token != QUOTE)
			{
				lexer->state = IN_QUOTE;
				lexer = lexer->next;
			}
		}
		if (lexer)
			lexer = lexer->next;
	}
}

t_lexer	*lexer_tokenizer(t_lexer **lexer, char *str)
{
	while (*str)
	{
		if (*str == WHITE_SPACE || *str == QUOTE || *str == DOUBLE_QUOTE
			|| *str == PIPE_LINE)
			str = handle_sntx(str, lexer, *str);
		else if (*str == REDIR_OUT && *(str + 1) == REDIR_OUT)
			str = handle_dredir(str, lexer, DREDIR_OUT);
		else if (*str == REDIR_IN && *(str + 1) == REDIR_IN)
			str = handle_dredir(str, lexer, HERE_DOC);
		else if (*str == REDIR_OUT)
			str = handle_redir(str, lexer, REDIR_OUT);
		else if (*str == REDIR_IN)
			str = handle_redir(str, lexer, REDIR_IN);
		else
			str = handle_word(str, lexer, WORD);
	}
	return (*lexer);
}

void	ft_lexer(char *str, t_global *global)
{
	if (!str || !*str)
		return ;
	global->lexer = lexer_tokenizer(&global->lexer, str);
	if (!global->lexer)
		perror("failed lexer: ");
	add_empty(&global->lexer);
	lexer_setstate(global->lexer);
	set_env(global->lexer);
	polish_lexer(&global->lexer);
	check_lexer(global);
}
