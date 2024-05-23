/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 14:53:03 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/16 12:37:20 by kkopnev       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	get_env_size(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**create_env(char **envp)
{
	int		i;
	int		j;
	char	**env;

	i = get_env_size(envp);
	j = -1;
	if (!envp)
		return (NULL);
	env = malloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	while (++j < i)
	{
		env[j] = ft_strdup(envp[j]);
		if (!env[j])
			return (free_arr(env));
	}
	env[j] = NULL;
	return (env);
}

int	check_quotes(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '\"')
		{
			while (str[++i] && str[i] != '\"')
				continue ;
			if (!str[i])
				return (0);
		}
		else if (str[i] == '\'')
		{
			while (str[++i] && str[i] != '\'')
				continue ;
			if (!str[i])
				return (0);
		}
	}
	return (1);
}
