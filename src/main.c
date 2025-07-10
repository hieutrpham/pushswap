/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:40:05 by trupham           #+#    #+#             */
/*   Updated: 2025/07/06 15:11:53 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int main(int ac, char **av) 
{
	check_input(ac, av);
	t_stack *stack_a;

	stack_a = build_stack(ac, av);
	printf("stack size: %d\n", stack_a->size);
	for (int i = 0; i < stack_a->size; i++)
	{
		printf("%d\n", stack_a->arr[i]);
	}
	destroy_stack(stack_a);
	return EXIT_SUCCESS;
}
