/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_algs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:53:46 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/09 16:07:21 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_control(int *tab, int size) // return 0 if array is sorted
{
	int i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	*insert_sort(int *tab, int size)
{
	int	*copy;
	int	temp;
	int	i;
	int	j;

	i = 1;
	copy = malloc(size * sizeof(int));
	if (!copy)
		return (0);
	copy = ft_memcpy(copy, tab, size * sizeof(int));
	while (i < size)
	{
		j = i;
		while (j > 0 && copy[j] < copy[j - 1])
		{
			temp = copy[j];
			copy[j] = copy[j - 1];
			copy[j - 1] = temp;
			j--;
		}
		i++;
	}
	return (copy);
}

void	val_to_ind(ft_stack *stack_a, int *sort_tab)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stack_a->top)
	{
		j = 0;
		while (stack_a->arr[i] != sort_tab[j])
			j++;
		stack_a->arr[i] = j;
		i++;
	}
}

int	dub_control(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}