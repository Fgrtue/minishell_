/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signal.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkopnev <kkopnev@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/17 15:39:55 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/24 13:48:55 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Ctrl+C sends SIGINT, Ctrl+\ sends SIGQUIT, and Ctrl+Q sends SIGCONT.
 *
 * ctrl-c: interrupt child process and continue to next iteration of while loop.
 * 			exit_code = 130
 * ctrl-d: interrupt all child processes and exit shell

 * ctrl-\: interrupt child process if ther is any. if it is in child process
	exit_c=131
 // ioctl(0, TIOCSTI, "\n");

 */

volatile int	g_sig;

void	interrupt_exe(int sig)
{
	if (sig == SIGINT)
	{
		write(STDERR_FILENO, "\n", 1);
		g_sig = SIGINT;
	}
	if (sig == SIGQUIT)
	{
		write(STDERR_FILENO, "Quit\n", 5);
		g_sig = SIGQUIT;
	}
}

void	interrupt_read(int sig)
{
	g_sig = sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	interrupt_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		write(STDERR_FILENO, "\n", 1);
		exit(130);
	}
}

void	signals_handler(t_mode mode)
{
	g_sig = 0;
	if (mode == INTERACTIVE)
	{
		signal(SIGINT, interrupt_read);
		signal(SIGQUIT, SIG_IGN);
	}
	if (mode == EXECUTE)
	{
		signal(SIGINT, interrupt_exe);
		signal(SIGQUIT, interrupt_exe);
	}
	if (mode == HEREDOC)
	{
		signal(SIGINT, interrupt_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
}
