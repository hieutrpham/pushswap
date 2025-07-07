/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:15:01 by trupham           #+#    #+#             */
/*   Updated: 2025/07/06 16:38:41 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* @brief: check if a string can be converted to interger
 */
bool check_digit(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}
bool check_split(char *str)
{
	char **split;
	int i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (false);
	split = ft_split(str, ' ');
	if (!split)
		return false;
	while (split[i])
	{
		if (!check_digit(split[i]))
			return (ft_putendl_fd("Error", 2), false);
		i++;
	}
	free_split(split);
	return true;
}
// @brief: check for existance of duplicates
// @return: false if there are dups, true if not
bool check_dup(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1) 
	{
		j = i + 1;
		while (j <size)
		{
			if (arr[i] == arr[j])
				return false;
			j++;
		}
		i++;
	}
	return true;
}
bool check_errors(int ac, char **av)
{
	if (ac == 2)
	{
		if (!check_split(av[1]))
			return false;
	}
	else if (ac > 2)
	{
		while (ac >= 2)
		{
			if (!check_digit(av[ac - 1]))
				return (ft_putendl_fd("Error", 2), false);
			ac--;
		}
	}
	else
		return false;
	return true;
}
