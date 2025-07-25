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
static int	*build_from_split(char *str)
{
	char	**split;
	int		*arr;
	int		i;
	int		size_of_arr;

	size_of_arr = ft_count_word(str, ' ');
	arr = ft_calloc(size_of_arr, sizeof(int));
	if (!arr)
		return (NULL);
	split = ft_split(str, ' ');
	if (!split)
		return (free(arr), NULL);
	i = -1;
	while (split[++i])
		arr[i] = ft_atol(split[i]);
	free_split(split);
	return (arr);
}

static int	*build_from_args(int ac, char **av)
{
	int	i;
	int	j;
	int	*arr;

	arr = ft_calloc(ac - 1, sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	j = 1;
	while (i < ac - 1)
		arr[i++] = ft_atol(av[j++]);
	return (arr);
}

static t_stack	*build_from_string(char **av)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->arr = build_from_split(av[1]);
	if (!stack->arr)
		return (free(stack), NULL);
	stack->sorted_arr = build_from_split(av[1]);
	if (!stack->sorted_arr)
		return (free(stack), NULL);
	stack->size = ft_count_word(av[1], ' ');
	quicksort(stack->sorted_arr, 0, stack->size - 1);
	stack->chunk_size = ft_sqrt(stack->size) * 2;
	stack->top = 0;
	stack->len = stack->size;
	return (stack);
}

static t_stack	*build_from_ac(int ac, char **av)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->arr = build_from_args(ac, av);
	if (!stack->arr)
		return (free(stack), NULL);
	stack->sorted_arr = build_from_args(ac, av);
	if (!stack->sorted_arr)
		return (free(stack), NULL);
	stack->size = ac - 1;
	quicksort(stack->sorted_arr, 0, stack->size - 1);
	stack->chunk_size = ft_sqrt(stack->size) * 2;
	stack->top = 0;
	stack->len = stack->size;
	return (stack);
}

t_stack	*build_stack(int ac, char **av)
{
	t_stack	*stack;

	stack = NULL;
	if (ac == 2)
	{
		stack = build_from_string(av);
		if (!stack)
			return (NULL);
	}
	else
	{
		stack = build_from_ac(ac, av);
		if (!stack)
			return (NULL);
	}
	return (stack);
}
