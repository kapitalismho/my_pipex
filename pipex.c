/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:01:05 by salee             #+#    #+#             */
/*   Updated: 2022/02/27 03:24:24 by salee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **envp, int *pipefd)
{
	int		filein;
	char	*path;
	char	**args;

	close(pipefd[0]);
	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		handling_error();
	path = get_path(argv[2], envp);
	args = get_args(argv[2]);
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	if (execve(path, args, envp) == -1)
	{
		free_heaps(path, args, NULL);
		handling_error();
	}
}

void	parent(char **argv, char **envp, int *pipefd)
{
	int		fileout;
	char	*path;
	char	**args;

	close(pipefd[1]);
	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		handling_error();
	path = get_path(argv[3], envp);
	args = get_args(argv[3]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	if (execve(path, args, envp) == -1)
	{
		free_heaps(path, args, NULL);
		handling_error();
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		status;
	pid_t	pid;

	if (argc != 5)
	{
		write(2, "Error: invalid args\n", 21);
		exit(1);
	}
	if (pipe(pipefd) == -1)
		handling_error();
	pid = fork();
	if (pid == -1)
		handling_error();
	else if (pid == 0)
		child(argv, envp, pipefd);
	else
	{
		waitpid(pid, &status, WNOHANG);
		parent(argv, envp, pipefd);
	}
	return (0);
}
