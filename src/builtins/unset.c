/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/27 12:25:33 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/22 16:02:34 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_del_env(char *var, char **env)
{
	int		i;
	int		size;
	char	**tmp;

	i = ft_find_key(var, env);
	if (i == -1)
		return (env);
	tmp = env;
	size = get_env_size(env) - 1;
	env = ft_calloc(size + 1, sizeof(char *));
	if (!env)
		return (NULL);
	ft_move_env(env, tmp, i);
	env[size] = NULL;
	free(tmp[i]);
	free(tmp);
	return (env);
}

int	ft_unset(t_cmd *cmd, t_global *global)
{
	global->env = ft_del_env((cmd->args)[1], global->env);
	if (!global->env)
		ft_error(global, "malloc", -1);
	return (EXIT_SUCCESS);
}
