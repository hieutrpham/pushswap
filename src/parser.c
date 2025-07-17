/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:25:39 by trupham           #+#    #+#             */
/*   Updated: 2025/07/17 08:19:01 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*@brief: build an int array from argv. exit early if already sorted
 */
static int *build_from_str(char *str)
{
	char **split;
	int *arr;
	int i;
	int size_of_arr;

	size_of_arr = ft_count_word(str, ' ');
	arr = ft_calloc(size_of_arr, sizeof(int));
	if (!arr)
		exit(EXIT_FAILURE);
	split = ft_split(str, ' ');
	if (!split)
		exit(EXIT_FAILURE);
	i = -1;
	while (split[++i])
		arr[i] = ft_atol(split[i]);
	if (is_sorted(arr, size_of_arr))
		exit(EXIT_SUCCESS);
	free_split(split);
	return arr;
}

static int *build_from_args(int ac, char **av)
{
	int i;
	int j;
	int *arr;

	arr = ft_calloc(ac - 1, sizeof(int));
	if (!arr)
		exit(EXIT_FAILURE);
	i = 0;
	j = 1;
	while (i < ac - 1)
		arr[i++] = ft_atol(av[j++]);
	if (is_sorted(arr, ac - 1))
		exit(EXIT_SUCCESS);
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
		return NULL;
	if (ac == 2)
	{
		stack->arr = build_from_str(av[1]);
		stack->sorted_arr = build_from_str(av[1]);
		stack->size = ft_count_word(av[1], ' ');
	}
	else if (ac > 2)
	{
		stack->arr = build_from_args(ac, av);
		stack->sorted_arr = build_from_args(ac, av);
		stack->size = ac - 1;
	}
	quicksort(stack->sorted_arr, 0, stack->size - 1);
	stack->chunk_size = ft_sqrt(stack->size);
	stack->top = 0;
	stack->len = stack->size;
	return stack;
}
/*@brief: to build stack b
 */
t_stack *build_empty_stack(unsigned int size)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return NULL;
	stack->arr = ft_calloc(size, sizeof(int));
	if (!stack->arr)
		return NULL;
	stack->size = size;
	stack->top = -1;
	stack->len = 0;
	stack->chunk_size = 0;
	return stack;
}
