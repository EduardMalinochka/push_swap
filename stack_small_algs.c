/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_small_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:42:42 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/13 14:43:33 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butter_return(t_stack *stack_a, t_stack *stack_b)
{
	int	b;

	while (stack_b->top >= 0)
	{
		if (stack_b->arr[stack_b->top] != stack_b->top)
		{
			b = find_max(stack_b);
			if (b >= stack_b->top / 2)
			{
				b = stack_b->top - b + 1;
				while (--b > 0)
					rotate(stack_b, 1, "rb");
			}
			else
			{
				while (--b >= -2)
					rotate(stack_b, 0, "rrb");
			}
		}
		else
			push(stack_a, stack_b, "pa");
	}
}

void	sort_3_elem(t_stack *stack_a)
{
	if (!sorted_stack(stack_a))
	{
		if (stack_a->arr[2] == stack_a->arr[find_min(stack_a)])
			swap(stack_a, "sa");
		if (stack_a->arr[0] == stack_a->arr[find_min(stack_a)]
			&& stack_a->arr[1] == stack_a->arr[find_mid(stack_a)])
			rotate(stack_a, 1, "ra");
		if (stack_a->arr[0] == stack_a->arr[find_max(stack_a)])
			swap(stack_a, "sa");
		if (stack_a->arr[0] == stack_a->arr[find_mid(stack_a)])
			rotate(stack_a, 1, "ra");
		if (stack_a->arr[0] == stack_a->arr[find_min(stack_a)])
			rotate(stack_a, 1, "rra");
	}
}

void	sort_5_elem(t_stack *stack_a, t_stack *stack_b, int step)
{
	int	max;
	int	min;

	max = find_max(stack_a);
	min = find_min(stack_a);
	if (max > min)
	{
		max = stack_a->top - max + 1;
		while (--max > 0)
			rotate(stack_a, 1, "ra");
	}
	else
	{
		min = stack_a->top - min + 1;
		while (--min > 0)
			rotate(stack_a, 1, "ra");
	}
	push(stack_b, stack_a, "pb");
	if (step == 1)
		sort_5_elem(stack_a, stack_b, 0);
	if (step == 0)
	{
		sort_3_elem(stack_a);
		chose_act(stack_a, stack_b);
	}
}

void	chose_act(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->arr[stack_b->top] == 0)
		swap(stack_b, "sb");
	if (stack_b->arr[stack_b->top] == 4)
	{
		push(stack_a, stack_b, "pa");
		rotate(stack_a, 1, "ra");
	}
	if (stack_b->arr[stack_b->top] == 1)
		push(stack_a, stack_b, "pa");
	if (stack_b->arr[stack_a->top] == 3)
	{
		push(stack_a, stack_b, "pa");
		rotate(stack_a, 1, "ra");
		push(stack_a, stack_b, "pa");
		rotate(stack_a, 1, "ra");
	}
	if (stack_b->arr[stack_b->top] == 0)
		push(stack_a, stack_b, "pa");
}
