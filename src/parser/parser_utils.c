/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 10:28:30 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/22 16:21:47 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_cmdaddfront(t_cmd **cmd, t_cmd *new)
{
	if (new == NULL)
	{
		return ;
	}
	new->next = *cmd;
	if (*cmd != NULL)
	{
		(*cmd)->prev = new;
	}
	*cmd = new;
}

void	ft_cmdaddback(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*last;

	last = NULL;
	if ((*cmd) == NULL)
		ft_cmdaddfront(cmd, new);
	else
	{
		last = ft_cmdlast(*cmd);
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	if (cmd == NULL)
		return (NULL);
	while (cmd->next != NULL)
		cmd = cmd->next;
	return (cmd);
}

void	ft_cmddel(t_cmd *node)
{
	if (node->redir)
	{
		ft_lexclean(node->redir);
	}
	if (node->args)
	{
		free_arr(node->args);
	}
	if (node->heredoc)
	{
		free(node->heredoc);
	}
	free(node);
}

/* change to *cmd clean from the beginning */
void	ft_cmdclean(t_cmd *cmd)
{
	t_cmd	*temp;

	temp = NULL;
	while (cmd && cmd->prev)
		cmd = cmd->prev;
	while (cmd)
	{
		temp = cmd;
		cmd = cmd->next;
		if (temp)
		{
			ft_cmddel(temp);
			temp = NULL;
		}
	}
}
