/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:15:01 by trupham           #+#    #+#             */
/*   Updated: 2025/07/06 15:14:58 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*check if a string can be converted to interger
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

bool check_errors(int ac, char **av)
{
	char **split;
	int i;

	i = 0;
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return 0;
		while (split[i])
		{
			if (!check_digit(split[i]))
				return (ft_putendl_fd("Error", 2), false);
			i++;
		}
		free_split(split);
	}
	else
		usage();
	return true;
}
