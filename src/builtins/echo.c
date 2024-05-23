/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkopnev <kkopnev@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 10:36:14 by kkopnev       #+#    #+#                 */
/*   Updated: 2024/01/23 15:56:04 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*

	Output the args, separated by spaces, terminated with a newline.
	The return status is 0 unless a write error occurs.
	If -n is specified, the trailing newline is suppressed.
	If the -e option is given, interpretation of the following
	backslash-escaped characters is enabled.
	The -E option disables the interpretation of these escape characters,
	even on systems where they are interpreted by default.
	The xpg_echo shell option may be used to dynamically determine
	whether or not echo expands these escape characters by default.
	echo does not interpret -- to mean the end of options.

*/

static int	check_option(char *arg)
{
	int	i;

	i = 0;
	if (arg[i++] != '-')
		return (1);
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_echo(t_cmd *cmd, t_global *global)
{
	int		mode;
	int		i;
	char	*line;

	i = 1;
	mode = 0;
	line = NULL;
	while (global && (cmd->args)[i] && check_option((cmd->args)[i]) != 1)
	{
		i++;
		mode = 1;
	}
	while ((cmd->args)[i])
	{
		line = ft_strjoin_free(line, (cmd->args)[i++]);
		if ((cmd->args)[i])
			line = ft_strjoin_free(line, " ");
	}
	write(cmd->fd_io[1], line, ft_strlen(line));
	write(cmd->fd_io[1], "\n", !mode);
	free(line);
	return (0);
}
