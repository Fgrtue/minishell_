/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/29 17:03:26 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/23 15:40:39 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Function sets exit code to 1, writes an error message and returns nothing */
int	ft_error(t_global *global, char *error_msg, int exit_c)
{
	if (errno && error_msg)
		perror(error_msg);
	else
		ft_putendl_fd(error_msg, 2);
	if (exit_c == -1)
	{
		free_arr(global->env);
		free_global(global);
		exit(EXIT_FAILURE);
	}
	free_global(global);
	global->exit_c = exit_c;
	return (1);
}

void	ft_unlink(t_cmd *cmds)
{
	while (cmds)
	{
		if (cmds->heredoc && !access(cmds->heredoc, F_OK))
			unlink(cmds->heredoc);
		cmds = cmds->next;
	}
}

void	check_sig(t_global *global)
{
	if (g_sig == SIGINT)
		global->exit_c = 130;
	else if (g_sig == SIGQUIT)
		global->exit_c = 131;
}

/*
	Function prints an error message, if there is one, is case of here_doc mode
	it unlinks all the hererdocs, and then cleans all the commands
		+ lexer. Finally
	depending on the mode it either cleans environment or not.
 */
void	free_global(t_global *global)
{
	if (!global)
		return ;
	ft_unlink(global->cmds);
	if (global->cmds)
		ft_cmdclean(global->cmds);
	if (global->lexer)
		ft_lexclean(global->lexer);
	global->cmds = NULL;
	global->lexer = NULL;
	check_sig(global);
}
