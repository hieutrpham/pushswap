/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:25:39 by trupham           #+#    #+#             */
/*   Updated: 2025/07/06 14:26:42 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

int *build_from_str(char *str)
{
	char **split;
	int *arr;

	arr = malloc(sizeof(int) * ft_count_word(str, ' '));
	split = ft_split(str, ' ');
	if (!split)
		exit(EXIT_FAILURE);
	return arr;
}
/* if malloc fail, exit program right away since we can't do anything
 * without a stack as opposed to the usual return NULL
 */
t_stack *build_stack(int ac, char **av)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit(EXIT_FAILURE);
	if (ac == 2)
	{
		stack->arr = build_from_str(av[1]);
	}
	return stack;
}
