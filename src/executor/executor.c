/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 15:05:45 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/24 12:36:28 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_path(char *cmd, char **env)
{
	char	**patharr;
	char	*path;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	patharr = ft_split(env[i] + 5, ':');
	i = -1;
	while (patharr[++i])
	{
		path = ft_strjoin(patharr[i], "/");
		path = ft_strjoin_free(path, cmd);
		if (access(path, F_OK) == 0)
		{
			free_arr(patharr);
			return (path);
		}
		free(path);
	}
	free_arr(patharr);
	return (NULL);
}

void	execute_cmd(t_cmd *cmd, char **env, t_global *global)
{
	char	*path;

	if (check_redirection(cmd))
		exit(1);
	dup2((cmd->fd_io)[0], STDIN_FILENO);
	dup2((cmd->fd_io)[1], STDOUT_FILENO);
	if (!cmd->args[0])
		exit(EXIT_SUCCESS);
	if (cmd->builtin != NULL)
		exit(cmd->builtin(cmd, global));
	close_fd(cmd->fd_io);
	if (check_directory(cmd->args[0]))
		exit(126);
	if (access(cmd->args[0], X_OK) == 0)
		path = (cmd->args)[0];
	else
		path = get_path((cmd->args)[0], env);
	if (path)
		execve(path, cmd->args, env);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd((cmd->args)[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}

void	process_cmd(t_cmd *cmd, t_global *global, int pipe[])
{
	cmd->pid = fork();
	if (cmd->pid == -1)
		ft_error(global, "Fork", -1);
	if (cmd->pid == 0)
	{
		close(pipe[0]);
		if (pipe[1] != cmd->fd_io[1])
			close(pipe[1]);
		execute_cmd(cmd, global->env, global);
	}
	else
		close_fd(cmd->fd_io);
}

int	pipe_exe(t_global *global)
{
	int		fd[2];
	t_cmd	*cmd;

	cmd = global->cmds;
	while (cmd)
	{
		if (pipe(fd) == -1 && cmd->next)
			ft_error(global, "Pipe", -1);
		if (cmd->next)
			(cmd->fd_io)[1] = fd[1];
		process_cmd(cmd, global, fd);
		if (cmd->next)
			(cmd->next->fd_io)[0] = fd[0];
		cmd = cmd->next;
	}
	close_fd(fd);
	return (0);
}

int	executor(t_global *global)
{
	if (!global->cmds)
		return (0);
	if (create_heredoc(global))
	{
		ft_unlink(global->cmds);
		return (130);
	}
	signals_handler(EXECUTE);
	if (!global->cmds->next && global->cmds->builtin)
	{
		if (check_redirection(global->cmds))
			return (EXIT_FAILURE);
		global->exit_c = global->cmds->builtin(global->cmds, global);
	}
	else
	{
		pipe_exe(global);
		global->exit_c = ft_wait(global->cmds);
	}
	return (global->exit_c);
}
