/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spilt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 07:13:16 by salee             #+#    #+#             */
/*   Updated: 2022/02/26 08:50:58 by salee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	garbage_collect(char **result, int j)
{
	while (j >= 0)
	{
		free(result[j]);
		j--;
	}
	free(result);
	return (0);
}

static int	str_numbers_calculate(char *str, char c)
{
	int		i;
	int		result;
	int		str_flag;

	i = 0;
	result = 0;
	str_flag = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			str_flag = 1;
		}
		if (str[i] != c && str_flag == 1)
		{
			result++;
			str_flag = 0;
		}
		i++;
	}
	return (result);
}

static void	my_strncpy(char *dest, char *src, int src_len, int src_index)
{
	int		i;

	i = 0;
	while (src_len > 0)
	{
		dest[i] = src[src_index - src_len];
		src_len--;
		i++;
	}
	dest[i] = '\0';
}

static int	str_make(char **result, char c, char *str, int str_numbers)
{
	int		i;
	int		j;
	int		str_len;

	i = 0;
	j = 0;
	while (str[i] && j < str_numbers)
	{
		str_len = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			str_len++;
			i++;
		}
		result[j] = (char *)malloc(str_len + 1);
		if (result[j] == NULL)
			return (garbage_collect(result, j - 1));
		my_strncpy(result[j], str, str_len, i);
		j++;
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	int		str_numbers;
	int		malloc_exception_check;
	char	**result;

	str_numbers = str_numbers_calculate((char *)str, c);
	result = (char **)malloc(sizeof(char *) * (str_numbers + 1));
	if (result == NULL)
		return (NULL);
	malloc_exception_check = str_make(result, c, (char *)str, str_numbers);
	if (malloc_exception_check == 0)
		return (NULL);
	return (result);
}
