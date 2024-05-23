/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 15:30:29 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/24 14:45:34 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 *  cd or cd ~ : cd HOME
 *  cd / : cd root directory
 *  cd .. : go to last direct of PWD
 *  cd ../.
 *  cd ../minishell/../minishell
 *  cd ~/Documents/../Documents/
 * 	cd - : change the dir to OLDPWD
 *  PWD=/home/jiajchen/Documents
 * change PWD and OLDPWD
 */

int	ft_find_key(char *var, char **env)
{
	int		i;
	char	*new_var;

	i = 0;
	new_var = ft_strjoin(var, "=");
	while (env[i] && ft_strncmp(env[i], new_var, ft_strlen(new_var)) != 0
		&& ft_strncmp(env[i], var, ft_strlen(env[i])) != 0)
		i++;
	free(new_var);
	if (env[i])
		return (i);
	return (-1);
}

void	ft_move_env(char **env, char **tmp, int pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp[j])
	{
		if (j == pos)
			j++;
		env[i] = tmp[j];
		i++;
		j++;
	}
}

/* str is malloced for env, should not be freed */
char	**ft_change_env(char *var, char *str, t_global *global)
{
	char	*tmp_str;
	char	**tmp;
	int		i;
	int		size;

	i = ft_find_key(var, global->env);
	if (i != -1)
	{
		tmp_str = global->env[i];
		global->env[i] = str;
		free(tmp_str);
		return (global->env);
	}
	tmp = global->env;
	size = get_env_size(global->env) + 1;
	global->env = ft_calloc(size + 1, sizeof(char *));
	if (!global->env)
		ft_error(global, "malloc", -1);
	ft_move_env(global->env, tmp, size);
	global->env[size - 1] = str;
	global->env[size] = NULL;
	return (free(tmp), global->env);
}

/* dir is not malloced */
char	*expand_dir(t_cmd *cmd, char *dir, t_global *global)
{
	char	*new;

	if (!dir)
		new = find_variable("HOME", global);
	else if (dir[0] == '~')
		new = ft_strjoin_free(find_variable("HOME", global), dir + 1);
	else if (dir[0] == '-' && !dir[1])
	{
		new = find_variable("OLDPWD", global);
		ft_putendl_fd(new, (cmd->fd_io)[1]);
	}
	else
		new = ft_strdup(dir);
	return (new);
}

int	ft_cd(t_cmd *cmd, t_global *global)
{
	char	*dir;
	char	*ptr;
	char	pwd[1024];

	if ((cmd->args)[1] && (cmd->args)[2])
	{
		ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	dir = expand_dir(cmd, (cmd->args)[1], global);
	if (chdir(dir) == -1)
	{
		free(dir);
		return (ft_error(global, (cmd->args)[1], 0));
	}
	ptr = (global->env)[ft_find_key("PWD", global->env)] + 4;
	global->env = ft_change_env("OLDPWD", ft_strjoin("OLDPWD=", ptr), global);
	global->env = ft_change_env("PWD", ft_strjoin("PWD=", getcwd(pwd,
					sizeof(pwd))), global);
	free(dir);
	if (!global->env)
		return (ft_error(global, "malloc", -1));
	return (EXIT_SUCCESS);
}
