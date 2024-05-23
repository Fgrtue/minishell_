/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkopnev <kkopnev@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 16:36:50 by kkopnev       #+#    #+#                 */
/*   Updated: 2024/01/23 16:00:10 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(t_cmd *cmd, t_global *global)
{
	int		i;
	char	**env_tmp;

	i = -1;
	env_tmp = global->env;
	while (env_tmp[++i])
	{
		if (ft_strchr(env_tmp[i], '=') != NULL)
			ft_putendl_fd(env_tmp[i], (cmd->fd_io)[1]);
	}
	return (0);
}
