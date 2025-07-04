/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:39:23 by trupham           #+#    #+#             */
/*   Updated: 2025/07/04 14:39:34 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_word(const char *s, char c)
{
	int	word_count;
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	word_count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			word_count++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (word_count);
}
