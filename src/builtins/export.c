/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkopnev <kkopnev@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/23 14:37:22 by kkopnev       #+#    #+#                 */
/*   Updated: 2024/01/23 16:02:22 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_print_exp(t_cmd *cmd, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		write((cmd->fd_io)[1], env[i], ft_strlen(env[i]));
		write((cmd->fd_io)[1], "\n", 1);
	}
	return (0);
}

static void	export_cmd(char *arg, t_global *global)
{
	int		len;
	char	*ptr_eq;
	char	*key;

	ptr_eq = ft_strchr(arg, '=');
	if (!ptr_eq && ft_find_key(arg, global->env) != -1)
		return ;
	if (!ptr_eq)
		len = ft_strlen(arg);
	else
		len = ptr_eq - arg;
	key = ft_calloc(len + 1, sizeof(char));
	if (key == NULL)
		ft_error(global, "malloc", -1);
	ft_memcpy(key, arg, len);
	global->env = ft_change_env(key, ft_strdup(arg), global);
	free(key);
}

int	ft_export(t_cmd *cmd, t_global *global)
{
	int	i;

	i = 0;
	if (!(cmd->args)[1])
		return (ft_print_exp(cmd, global->env));
	while ((cmd->args)[++i])
	{
		if (!cmd->args[i][0] || (!ft_strchr(cmd->args[i], '=')
				&& ft_strchr(cmd->args[i], ' ')))
		{
			ft_putstr_fd("minishell: export: \"", STDERR_FILENO);
			ft_putstr_fd(cmd->args[i], STDERR_FILENO);
			ft_putendl_fd("\": not a valid identifier", STDERR_FILENO);
		}
		else
			export_cmd(cmd->args[i], global);
	}
	return (0);
}
