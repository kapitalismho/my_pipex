/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 06:29:27 by salee             #+#    #+#             */
/*   Updated: 2022/02/27 03:31:27 by salee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cal_path(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	**program;
	char	*part_path;
	int		i;

	paths = cal_path(envp);
	program = ft_split(cmd, ' ');
	i = -1;
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, program[0]);
		if (access(path, F_OK) == 0)
		{
			free_heaps(part_path, program, paths);
			return (path);
		}
		free(path);
		free(part_path);
	}
	free_heaps(NULL, program, paths);
	handling_error();
	return (NULL);
}

char	**get_args(char *argv)
{
	char	**splited_arg2;

	splited_arg2 = ft_split(argv, ' ');
	return (splited_arg2);
}

void	free_heaps(char *path, char **args, char **paths)
{
	int	i;

	i = 0;
	if (path != NULL)
		free(path);
	i = 0;
	if (args != NULL)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	i = 0;
	if (paths != NULL)
	{
		while (paths[i])
		{
			free(paths[i]);
			i++;
		}
		free(paths);
	}
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	i = 1;
	if (!*s2)
		return ((char *)s1);
	len = ft_strlen(s2);
	if (n > ft_strlen(s1))
		n = ft_strlen(s1);
	while (len <= n--)
	{
		if (*s1 == *s2)
		{
			while (1)
			{
				if (i == len)
					return ((char *)s1);
				if (s1[i] != s2[i])
					break ;
				i++;
			}
		}
		s1++;
	}
	return (NULL);
}
