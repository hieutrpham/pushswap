/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:15:49 by trupham           #+#    #+#             */
/*   Updated: 2025/07/04 14:39:29 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static int	ft_free(char **arr, char **curr)
{
	int	i;

	i = 0;
	if (*curr == NULL)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		return (1);
	}
	return (0);
}

static const char	*get_next_word(const char *s, char c, int *len)
{
	const char	*start;
	int			i;

	i = 0;
	*len = 0;
	while (s[i] == c)
		i++;
	start = &s[i];
	while (s[i] && s[i] != c)
	{
		(*len)++;
		i++;
	}
	if (*len > 0)
		return (start);
	return (NULL);
}

static char	**split(char const *s, char c, char ***arr)
{
	const char	*start;
	char		**curr;
	int			len;

	curr = *arr;
	while (*s)
	{
		start = get_next_word(s, c, &len);
		if (start != NULL)
		{
			*curr = ft_substr(start, 0, len);
			if (ft_free(*arr, &(*curr)))
				return (NULL);
			curr++;
			s = start + len;
		}
		else
			s++;
	}
	return (*arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = ft_calloc((ft_count_word(s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	return (split(s, c, &arr));
}
