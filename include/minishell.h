/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jiajchen <jiajchen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 10:10:35 by jiajchen      #+#    #+#                 */
/*   Updated: 2024/01/24 13:48:20 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* standard headers */
# include "../libft/libft.h"
# include "struct.h"
# include <dirent.h> // opendir readdir closedir
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h> // signal kill sigaction sigemptyset sigaddset
# include <stdio.h>
# include <stdlib.h>
# include <string.h>   // strerror
# include <sys/stat.h> // stat lstat fstat
# include <sys/wait.h>
# include <termio.h> // tcsetattr tcgetattr
# include <unistd.h>
# include <unistd.h> // getcwd chdir / isatty ttyname ttyslot

/* main */
char	**create_env(char **envp);
int		check_eq(char *str);
int		check_quotes(char *str);
int		get_env_size(char **env);
int		check_quotes(char *str);

/* error */
int		ft_error(t_global *global, char *error_msg, int exit_c);
void	ft_unlink(t_cmd *cmds);
void	free_global(t_global *global);
void	check_sig(t_global *global);

/* signal */
void	signals_handler(t_mode mode);

/* lexer */
void	ft_lexer(char *str, t_global *global);
int		word_len(char *str);
t_lexer	*lexer_tokenizer(t_lexer **lexer, char *str);
char	*handle_sntx(char *str, t_lexer **lexer, int token);
char	*handle_dredir(char *str, t_lexer **lexer, int token);
char	*handle_redir(char *str, t_lexer **lexer, int token);
char	*handle_word(char *str, t_lexer **lexer, int token);
t_lexer	*ft_lexnew(char *content, int token);
void	ft_lexaddfront(t_lexer **lexer, t_lexer *new);
void	ft_lexaddback(t_lexer **lexer, t_lexer *new);
t_lexer	*ft_lexlast(t_lexer *lexer);
void	ft_lexdel(t_lexer *node);
void	ft_lexclean(t_lexer *lexer);
void	ft_lexinsert(t_lexer **lexer, t_lexer *prev, t_lexer *next,
			t_lexer *node);
t_lexer	*ft_lexretract(t_lexer **lexer, t_lexer *node);
void	add_empty(t_lexer **lexer);
int		is_env(t_lexer *node);
void	set_env(t_lexer *lexer);
void	polish_lexer(t_lexer **lexer);
int		check_lexer(t_global *global);

/* paser and polisher */
int		expand_env(t_lexer *lex, t_global *global);
int		polish_lex(t_lexer **lst);
int		get_cmds(t_global *global);

/* t_cmd link list utils*/
t_cmd	*ft_cmdnew(void);
void	ft_cmdaddfront(t_cmd **cmd, t_cmd *new);
void	ft_cmdaddback(t_cmd **cmd, t_cmd *new);
t_cmd	*ft_cmdlast(t_cmd *cmd);
void	ft_cmddel(t_cmd *node);
void	ft_cmdclean(t_cmd *cmd);

/* executor */
int		executor(t_global *global);
int		pipe_exe(t_global *global);
void	process_cmd(t_cmd *cmd, t_global *global, int pipe[]);
char	*find_variable(char *var, t_global *global);
int		check_redirection(t_cmd *cmd);
int		set_redir(t_cmd *cmd, char *inf, char *outf);
char	*redir_out(t_cmd *cmd, t_lexer *redir);
char	*redir_in(t_cmd *cmd, t_lexer *redir);
void	here_doc(char *heredoc, char *inf);
int		process_here_doc(char *count, t_lexer *redir, t_global *global);
int		create_heredoc(t_global *global);
void	close_fd(int fd[]);
int		ft_wait(t_cmd *cmd);
int		check_directory(char *path);
int		specify_builtins(t_cmd *cmd, char ***env);

/* builtins */
int		ft_echo(t_cmd *cmd, t_global *global);
int		ft_env(t_cmd *cmd, t_global *global);
int		ft_exit(t_cmd *cmd, t_global *global);
int		ft_export(t_cmd *cmd, t_global *global);
int		ft_unset(t_cmd *cmd, t_global *global);
int		ft_pwd(t_cmd *cmd, t_global *global);
int		ft_cd(t_cmd *cmd, t_global *global);

char	**ft_del_env(char *var, char **env);
void	ft_move_env(char **env, char **tmp, int pos);
char	**ft_change_env(char *var, char *str, t_global *global);
int		get_env_size(char **env);
int		ft_find_key(char *var, char **env);

void	print_args(char **args);
void	print_lex(t_lexer *lexer);
void	print_cmd(t_cmd *cmd);

#endif