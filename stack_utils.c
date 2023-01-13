/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:35:51 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/13 14:47:12 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 1;
	min = 0;
	while (i <= stack->top)
	{
		if (stack->arr[i] < stack->arr[min])
			min = i;
		i++;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 1;
	max = 0;
	while (i <= stack->top)
	{
		if (stack->arr[i] > stack->arr[max])
			max = i;
		i++;
	}
	return (max);
}

int	find_mid(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (i != find_min(stack) && i != find_max(stack))
			return (i);
		i++;
	}
	return (i);
}

int	sorted_stack(t_stack *stack_a)
{
	int	i;

	i = stack_a->top;
	while (i > 0)
	{
		if (stack_a->arr[i] > stack_a->arr[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	find_closest(int *arr, int top, int val)
{
	int	i;

	i = top;
	while (i >= 0)
	{
		if (arr[i] <= val)
			return (i);
		i--;
	}
	return (0);
}
