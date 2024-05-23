/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jessie <jessie@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 16:00:57 by jiajchen      #+#    #+#                 */
/*   Updated: 2023/12/13 13:52:59 by jiajchen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 100000

/* extract nextline from the line only before '\n' */
char	*nextline_from_line(char *line)
{
	int		len;
	int		j;
	char	*next_line;

	len = 0;
	if (ft_strlen(line) == 0)
		return (NULL);
	while (line[len] != '\n' && line[len])
		len++;
	if (line[len] == '\n')
		len++;
	next_line = (char *)malloc((len + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	j = 0;
	while (j < len)
	{
		next_line[j] = line[j];
		j++;
	}
	next_line[j] = '\0';
	return (next_line);
}

/* update the line (only after '\n') for the next call of get_next_line */
char	*new_line(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	new_line = ft_strdup(&line[i]);
	free(line);
	return (new_line);
}

/* keep reading from fd until '\n' and join them in 'line' */
char	*read_from_file(int fd, char *line)
{
	ssize_t	bytesread;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytesread = BUFFER_SIZE;
	while (!ft_strchr(line, '\n') && bytesread == BUFFER_SIZE)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		line = ft_strjoin_free(line, buffer);
	}
	free(buffer);
	return (line);
}

/* combine the four helper function together */
char	*get_next_line(int fd)
{
	static char	*line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_from_file(fd, line);
	if (!line)
		return (NULL);
	next_line = nextline_from_line(line);
	line = new_line(line);
	return (next_line);
}

// int	main(int argc, char *argv[])
// {
// 	int		file;
// 	char	*tmp;

// 	file = open(argv[1], O_RDONLY);
// 	while ((tmp = get_next_line(file)) != NULL)
// 	{
// 		printf("%s", tmp);
// 		free(tmp);
// 	}
// 	close(file);
// 	return (0);
// }
