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
	// if (!check_errors(ac, av))
	// 	return EXIT_FAILURE;
	check_errors(ac, av);
	int arr[] = {2,1,3,6, 5, 4};
	ft_printf("%d\n", check_dup(arr, 6));
	return EXIT_SUCCESS;
}
