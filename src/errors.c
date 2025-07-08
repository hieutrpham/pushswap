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

/* @brief: check string can be converted to a valid int within bound
 */
bool is_valid_int_limit(char *str)
{
	long nbr;

	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return false;
	return true;
}

/* @brief: check if a string can be converted to interger
 */
bool is_valid_int_str(char *str)
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
	if (!is_valid_int_limit(str))
		return (false);
	return true;
}
/* @brief: if ac == 2, split the string argv and check for error
 */
bool is_valid_split(char *str)
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
		if (!is_valid_int_str(split[i]))
			return (ft_putendl_fd("Error", 2), false);
		i++;
	}
	free_split(split);
	return true;
}
// @brief: check for existance of duplicates
// @return: true if there are dups, false if not
void check_dup(int *arr, int size)
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
				exit_error();
			j++;
		}
		i++;
	}
}
/* @brief: loop through the argv to check acceptable inputs eg. 1 2 3 and "1 2 3"
 */
void check_input(int ac, char **av)
{
	if (ac == 2)
	{
		if (!is_valid_split(av[1]))
			exit(EXIT_FAILURE);
	}
	else if (ac > 2)
	{
		while (ac >= 2)
		{
			if (!is_valid_int_str(av[ac - 1]))
				exit_error();
			ac--;
		}
	}
	else
		exit(EXIT_FAILURE);
}
