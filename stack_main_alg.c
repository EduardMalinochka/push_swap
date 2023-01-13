/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:50:24 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/13 15:30:58 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butter_arg(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_norm	var;
	int		boo;

	var.count = 0;
	var.n = 1;
	if (size >= 50)
		var.n = ft_sqrt(size) + (ft_sqrt(size) * 2 / 5);
	while (stack_a->top >= 0)
	{
		if (stack_a->arr[stack_a->top] <= var.count)
		{
			push(stack_b, stack_a, "pb");
			if (var.count > 0)
				rotate(stack_b, 1, "rb");
			var.count++;
		}
		else if (stack_a->arr[stack_a->top] <= var.count + var.n)
		{
			push(stack_b, stack_a, "pb");
			var.count++;
		}
		else
			butter_stack_ra(stack_a, stack_b, var, &boo);
	}
	butter_return(stack_a, stack_b);
}

void	butter_stack_ra(t_stack *stack_a, t_stack *stack_b, t_norm var,
		int *boo)
{
	if (find_closest(stack_a->arr, stack_a->top, var.count
			+ var.n) > stack_a->top / 2)
	{
		if (*boo == 1 && stack_b->arr[stack_b->top] < stack_b->arr[stack_b->top
				- 1])
		{
			ss(stack_a, stack_b);
			*boo = 0;
		}
		else
		{
			rotate(stack_a, 1, "ra");
			*boo = 1;
		}
	}
	else
		butter_stack_rra(stack_a, stack_b, boo, var.count);
}

void	butter_stack_rra(t_stack *stack_a, t_stack *stack_b, int *boo,
		int count)
{
	int	b;

	b = find_max(stack_b);
	if (count > 1 && stack_b->arr[stack_b->top] < stack_b->arr[0])
	{
		if (b < stack_b->top / 2)
			while (--b >= -2)
				double_rotate(stack_a, stack_b, 0);
		else
			double_rotate(stack_a, stack_b, 0);
	}
	else
		rotate(stack_a, 0, "rra");
	*boo = 1;
}
