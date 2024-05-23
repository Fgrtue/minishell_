/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkopnev <kkopnev@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 16:44:19 by kkopnev       #+#    #+#                 */
/*   Updated: 2024/01/24 14:52:24 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*

	Exit the shell, returning a status of n to the shell’s parent.
	If n is omitted, the exit status is that of the last command executed.
	Any trap on EXIT is executed before the shell terminates.

*/

static int	ft_isnumb(char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

// int ft_exit(t_cmd* cmd, char ***env)
int	ft_exit(t_cmd *cmd, t_global *global)
{
	if (!cmd || (cmd && cmd->pid == -2))
		write(STDOUT_FILENO, "exit\n", 5);
	if (!cmd || !(cmd->args[1]))
		global->exit_c = 0;
	else if (!ft_isnumb(cmd->args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(cmd->args[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		global->exit_c = 2;
	}
	else if (cmd->args[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
		if (ft_isnumb(cmd->args[1]))
			return (1);
	}
	else
		global->exit_c = ft_atoi(cmd->args[1]);
	free_arr(global->env);
	free_global(global);
	return (exit(global->exit_c), global->exit_c);
}

// exit abc
// exit
// bash: exit: abc: numeric argument required

// exit 1 2
// not exit
// exit
// bash: exit: too many arguments

// exit abd abd