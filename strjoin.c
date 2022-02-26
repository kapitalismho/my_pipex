/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 06:40:35 by salee             #+#    #+#             */
/*   Updated: 2022/02/26 19:48:27 by salee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*s2;

	s2 = s;
	while (n--)
	{
		*s2++ = '\0';
	}
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	calculated_size;

	calculated_size = count * size;
	pointer = malloc(calculated_size);
	if (pointer == NULL)
	{
		return (NULL);
	}
	ft_bzero(pointer, calculated_size);
	return (pointer);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (str[i] == 0)
		{
			break ;
		}
		i++;
	}
	return (i);
}

static char	*my_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	dest_length;

	i = 0;
	dest_length = 0;
	while (dest[dest_length])
	{
		dest_length++;
	}
	while (src[i] != '\0')
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_string;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined_string = ft_calloc(size, 1);
	if (joined_string == NULL)
		return (NULL);
	joined_string = my_strcat(joined_string, (char *)s1);
	joined_string = my_strcat(joined_string, (char *)s2);
	return (joined_string);
}
