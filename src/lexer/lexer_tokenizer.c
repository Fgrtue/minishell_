/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_tokenizer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkopnev <kkopnev@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 12:27:46 by kkopnev       #+#    #+#                 */
/*   Updated: 2024/01/22 16:18:35 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		word_len(char *str);
char	*handle_sntx(char *str, t_lexer **lexer, int token);
char	*handle_dredir(char *str, t_lexer **lexer, int token);
char	*handle_redir(char *str, t_lexer **lexer, int token);
char	*handle_word(char *str, t_lexer **lexer, int token);

int	word_len(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (i);
	if (str[i] == '$')
		i++;
	if (str[i] == '?')
		return (i + 1);
	while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '\"'
		&& str[i] != '>' && str[i] != '<' && str[i] != '|' && str[i] != '$')
		i++;
	return (i);
}

char	*handle_sntx(char *str, t_lexer **lexer, int token)
{
	char	*content;

	content = NULL;
	if (*str == WHITE_SPACE)
		content = ft_strdup(" ");
	else if (*str == QUOTE)
		content = ft_strdup("\'");
	else if (*str == DOUBLE_QUOTE)
		content = ft_strdup("\"");
	else if (*str == PIPE_LINE)
		content = ft_strdup("|");
	ft_lexaddback(lexer, ft_lexnew(content, token));
	return (str + 1);
}

char	*handle_dredir(char *str, t_lexer **lexer, int token)
{
	char	*content;

	content = NULL;
	if (*str == REDIR_OUT && *(str + 1) == REDIR_OUT)
		content = ft_strdup(">>");
	else if (*str == REDIR_IN && *(str + 1) == REDIR_IN)
		content = ft_strdup("<<");
	ft_lexaddback(lexer, ft_lexnew(content, token));
	return (str + 2);
}

char	*handle_redir(char *str, t_lexer **lexer, int token)
{
	char	*content;

	content = NULL;
	if (*str == REDIR_IN)
		content = ft_strdup("<");
	else if (*str == REDIR_OUT)
		content = ft_strdup(">");
	ft_lexaddback(lexer, ft_lexnew(content, token));
	return (str + 1);
}

char	*handle_word(char *str, t_lexer **lexer, int token)
{
	char	*content;
	size_t	len;

	len = word_len(str);
	content = ft_calloc(len + 1, sizeof(char));
	if (content == NULL)
		perror("calloc");
	ft_memcpy(content, str, len);
	ft_lexaddback(lexer, ft_lexnew(content, token));
	return (str + len);
}
