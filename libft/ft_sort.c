/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:37:38 by trupham           #+#    #+#             */
/*   Updated: 2025/07/14 12:21:07 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* @brief: check whether an int array is sorted in ascending order
 * @return: true if sorted, false if not
 */
bool is_sorted(int *arr, int size)
{
	int i = 0;
	int j = 0;

	if (size <= 1)
		return true;
	while (i < size - 1)
	{
		j = i + 1;
		if (arr[i] > arr[j])
			return false;
		i++;
	}
	return true;
}

static void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
	int j = low;

	while (j <= high - 1)
	{
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
		j++;
	}
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int *arr, int low, int high) {
	int pi;

    if (low < high) {
		pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void bubblesort(int *arr, int size)
{
	int i;
	int j;
	int temp;

	temp = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}
