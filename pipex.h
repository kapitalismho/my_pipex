/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 04:09:37 by salee             #+#    #+#             */
/*   Updated: 2022/02/27 03:30:41 by salee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

void	handling_error(void);
void	do_cmd(char *argv, char **envp);
void	*ft_calloc(size_t count, size_t size);
void	*ft_bzero(void *s, size_t n);
void	free_heaps(char *path, char **args, char **paths);
char	**get_args(char *argv);
char	*get_path(char *argv, char **envp);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	**cal_path(char **envp);
size_t	ft_strlen(const char *str);

#endif
