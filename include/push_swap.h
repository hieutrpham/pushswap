/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 07:45:38 by trupham           #+#    #+#             */
/*   Updated: 2025/07/06 15:14:58 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "../libft/libft.h"
#include <limits.h>
void quicksort(int arr[], int low, int high);

//======errors.c======//
bool is_correct_input(int ac, char **av);
bool check_dup(int *arr, int size);
bool is_valid_int_limit(char *str);

//======utils.c======//
void usage();
#endif
