/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   polisher.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/11 12:35:21 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/23 15:27:07 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*ft_cmdnew(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->args = NULL;
	cmd->builtin = NULL;
	cmd->num_redir = 0;
	(cmd->fd_io)[0] = 0;
	(cmd->fd_io)[1] = 1;
	cmd->dr_bool = 0;
	cmd->heredoc = NULL;
	cmd->redir = NULL;
	cmd->prev = NULL;
	cmd->next = NULL;
	cmd->pid = -2;
	return (cmd);
}

void	ft_lexjoin_quotes(t_lexer **lst, t_lexer *lexer)
{
	t_lexer	*node;
	t_lexer	*track;
	char	*str;

	while (lexer)
	{
		str = NULL;
		if (lexer->state != GENERAL)
		{
			track = lexer;
			while (track && track->state != GENERAL)
			{
				str = ft_strjoin_free(str, track->content);
				track = track->next;
			}
			node = ft_lexnew(str, WORD);
			ft_lexinsert(lst, lexer->prev, lexer, node);
			while (node->next && node->next->state != GENERAL)
				ft_lexdel(ft_lexretract(lst, node->next));
			lexer = node;
		}
		lexer = lexer->next;
	}
}

void	ft_lexjoin_word(t_lexer **lst, t_lexer *lexer)
{
	t_lexer	*node;
	t_lexer	*track;
	char	*str;

	while (lexer)
	{
		str = NULL;
		if (lexer->token == WORD && lexer->next && lexer->next->token == WORD)
		{
			track = lexer;
			while (track && track->token == WORD)
			{
				str = ft_strjoin_free(str, track->content);
				track = track->next;
			}
			node = ft_lexnew(str, WORD);
			ft_lexinsert(lst, lexer->prev, lexer, node);
			while (node->next && node->next->token == WORD)
				ft_lexdel(ft_lexretract(lst, node->next));
			lexer = node;
		}
		lexer = lexer->next;
	}
}

int	polish_lex(t_lexer **lst)
{
	t_lexer	*lex;
	t_lexer	*tmp;

	ft_lexjoin_quotes(lst, *lst);
	ft_lexjoin_word(lst, *lst);
	lex = *lst;
	while (lex)
	{
		if (lex->token == WHITE_SPACE)
		{
			tmp = lex;
			lex = lex->next;
			ft_lexdel(ft_lexretract(lst, tmp));
		}
		else
			lex = lex->next;
	}
	return (0);
}
