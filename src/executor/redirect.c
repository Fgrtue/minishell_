/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirect.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 15:15:43 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/24 15:44:44 by kkopnev       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*

	in case of a redirection we have to close the previous file for input/output
	in ft_io, and open a different file.

	in case if we encounter a here_doc redirection we go to
	a function here_doc.



	, we start reading lines
	and check wheather we encounter a delimiter that was provided to us.
	once we find a delimiter -- we finish reading,
		save the file and then proceed
	to the command.

*/

/*
	Function must: for every command it checks wheather there is a here doc.
	If there is at least one,
		it increases the static counter and starts the process
	of opening here_docs. There will be basicaly one here_doc file for every 
	command.
	If there are more here_doc redirections,
		this file will be just truncated and then
	rewritten again. So once we found a heredoc, we start a child process,
		where we'll be
	opening heredocs. This is done in order to be able to track the signal. 
	We'll always wait for all the here_docs to be finished for one command,
		and then record the exit code. If
	exit code is 130, then we finish the function,
		change the value of here_doc_exit in
	our struct and leave the building, getting back to readline.
*/

int	process_here_doc(char *count, t_lexer *redir, t_global *global)
{
	int	pid;
	int	status;

	status = 0;
	if (!redir || !redir->next)
		return (1);
	pid = fork();
	if (pid == -1)
		ft_error(global, "Fork", -1);
	signal(SIGINT, SIG_IGN);
	if (pid == 0)
	{
		signals_handler(HEREDOC);
		here_doc(count, redir->next->content);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		return (130);
	return (0);
}

int	create_heredoc(t_global *global)
{
	t_cmd		*cmd;
	t_lexer		*redir;
	static int	hd;

	cmd = global->cmds;
	while (cmd)
	{
		redir = cmd->redir;
		if (redir)
			cmd->heredoc = ft_itoa(++hd);
		while (redir)
		{
			if (redir->token == HERE_DOC && process_here_doc(cmd->heredoc,
					redir, global))
				return (130);
			redir = redir->next;
		}
		cmd = cmd->next;
	}
	return (0);
}

char	*redir_out(t_cmd *cmd, t_lexer *redir)
{
	if (redir->token == REDIR_OUT)
	{
		cmd->dr_bool = 0;
		close(open(redir->next->content, O_CREAT, 0644));
		return (redir->next->content);
	}
	else if (redir->token == DREDIR_OUT)
	{
		cmd->dr_bool = 1;
		close(open(redir->next->content, O_CREAT, 0644));
		return (redir->next->content);
	}
	else
		return (NULL);
}

/* return 1 if there is error */
int	set_redir(t_cmd *cmd, char *inf, char *outf)
{
	if (inf && (cmd->fd_io)[0] != 0)
		close((cmd->fd_io)[0]);
	if (outf && (cmd->fd_io)[1] != 1)
		close((cmd->fd_io)[1]);
	if (outf && cmd->dr_bool == 1)
		(cmd->fd_io)[1] = open(outf, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (outf && cmd->dr_bool == 0)
		(cmd->fd_io)[1] = open(outf, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if ((cmd->fd_io)[1] == -1)
		perror(outf);
	if (inf)
		(cmd->fd_io)[0] = open(inf, O_RDONLY);
	if ((cmd->fd_io)[0] == -1)
		perror(inf);
	if (cmd->heredoc && access(cmd->heredoc, F_OK) == 0)
		unlink(cmd->heredoc);
	if ((cmd->fd_io)[0] == -1 || (cmd->fd_io)[1] == -1)
		return (1);
	return (0);
}

/* if error return 1 */
int	check_redirection(t_cmd *cmd)
{
	t_lexer	*redir;
	char	*inf;
	char	*outf;

	inf = NULL;
	outf = NULL;
	redir = cmd->redir;
	while (redir)
	{
		errno = 0;
		if (redir->token == REDIR_IN)
			inf = redir->next->content;
		if (redir->token == HERE_DOC)
			inf = cmd->heredoc;
		if (redir->token == REDIR_OUT || redir->token == DREDIR_OUT)
			outf = redir_out(cmd, redir);
		redir = redir->next->next;
	}
	return (set_redir(cmd, inf, outf));
}

// in case when redir token is here_doc use here_doc function in order to
// open the here_doc ++ un.link it in the end
