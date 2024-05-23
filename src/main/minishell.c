/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 16:11:54 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/24 16:20:53 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_readline(t_global *global)
{
	char	*prompt;
	char	*line;

	prompt = ft_strdup("minishell:");
	prompt = ft_strjoin_free_d(prompt, find_variable("PWD", global));
	prompt = ft_strjoin_free(prompt, "$ ");
	signals_handler(INTERACTIVE);
	line = readline(prompt);
	free(prompt);
	if (line == NULL)
	{
		rl_clear_history();
		ft_exit(NULL, global);
	}
	if (line && *line)
		add_history(line);
	if (!check_quotes(line))
	{
		ft_putendl_fd("minishell: wrong quotes!", STDERR_FILENO);
		free(line);
		line = ft_readline(global);
	}
	return (line);
}

int	main(int argc, char **argv, char **envp)
{
	char			*line;
	static t_global	global;

	global.env = create_env(envp);
	while (argc && argv)
	{
		free_global(&global);
		line = ft_readline(&global);
		check_sig(&global);
		ft_lexer(line, &global);
		free(line);
		if (global.lexer == NULL)
			continue ;
		if (expand_env(global.lexer, &global) || get_cmds(&global))
			continue ;
		global.exit_c = executor(&global);
	}
	return (0);
}

/*
void	print_lex(t_lexer *lexer)
{
	printf("################################\n");
	while (lexer)
	{
		printf("LEXER: %p\n", lexer);
		printf("################################\n");
		printf("content:%s\n", lexer->content);
		printf("len: %i\n", lexer->len);
		printf("token: %i\n", lexer->token);
		printf("state: %i\n", lexer->state);
		printf("prev: %p\n", lexer->prev);
		printf("next: %p\n", lexer->next);
		printf("################################\n");
		lexer = lexer->next;
	}
	printf("################################\n");
}

void	print_args(char **args)
{
	int	i;

	i = 0;
	printf("The content:\n");
	while (args && args[i])
	{
		printf("    %d. %s\n", i, args[i]);
		i++;
	}
}

void	print_cmd(t_cmd *cmd)
{
	printf("************************************\n");
	while (cmd)
	{
		printf("CMD: %p\n", cmd);
		printf("************************************\n");
		print_args(cmd->args);
		printf("The num of redir: %d\n", cmd->num_redir);
		printf("\nRedir: %p\n", cmd->redir);
		print_lex(cmd->redir);
		printf("\nprev: %p\n", cmd->prev);
		printf("next: %p\n", cmd->next);
		printf("************************************\n");
		cmd = cmd->next;
	}
}
*/