/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:37:38 by trupham           #+#    #+#             */
/*   Updated: 2025/07/05 11:38:09 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    printf("pivot: %d\n", pivot);
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            printf("arr[i]: %d, arr[j]: %d\n", arr[i], arr[j]);
            swap(&arr[i], &arr[j]);
        }
    }
    printf("i+1: %d, arr[i+1]: %d, arr[high]: %d\n", i+1, arr[i+1], arr[high]);
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
