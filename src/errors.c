/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:15:01 by trupham           #+#    #+#             */
/*   Updated: 2025/07/14 12:08:01 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* @brief: check string can be converted to a valid int within bound
 */
static bool	is_valid_int_limit(char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (false);
	return (true);
}

/* @brief: check if a string can be converted to interger
 */
static bool	is_valid_int_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (!is_valid_int_limit(str))
		return (false);
	return (true);
}

/* @brief: if ac == 2, split the string argv and check for error
 */
static bool	is_valid_split(char *str)
{
	char	**split;
	int		i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (false);
	split = ft_split(str, ' ');
	if (!split)
		return (false);
	while (split[i])
	{
		if (!is_valid_int_str(split[i]))
			return (free_split(split), false);
		i++;
	}
	free_split(split);
	return (true);
}

// @brief: check for existance of duplicates in an int array
// @return: exit the program if there is dup
void	check_dup(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->arr[i] == stack->arr[j])
			{
				destroy_stack(stack);
				exit_error();
			}
			j++;
		}
		i++;
	}
}

/* @brief: loop through the argv to check acceptable inputs
 */
void	check_input(int ac, char **av)
{
	if (ac == 2 && !is_valid_split(av[1]))
		exit_error();
	else if (ac > 2)
	{
		while (ac >= 2)
		{
			if (!is_valid_int_str(av[ac - 1]))
				exit_error();
			ac--;
		}
	}
	else if (ac == 1)
		exit(EXIT_SUCCESS);
	else
		return ;
}
