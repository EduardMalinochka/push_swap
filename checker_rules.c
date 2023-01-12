/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:21:57 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/12 20:37:31 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	c_swap(t_stack *stack)
{
	int	temp;

	if (stack->top > 0)
	{
		temp = stack->arr[stack->top - 1];
		stack->arr[stack->top - 1] = stack->arr[stack->top];
			stack->arr[stack->top] = temp;
	}
}

void	c_ss(t_stack *a, t_stack *b)
{
	c_swap(a);
	c_swap(b);
}

void	c_push(t_stack *to, t_stack *from)
{
	to->top++;
	to->arr[to->top] = from->arr[from->top];
	from->top--;
}

void	c_rotate(t_stack *stack, int up)
{
	int	temp;
	int	i;

	if (up == 1)
	{
		temp = stack->arr[stack->top];
		i = stack->top + 1;
		while (--i > 0)
			stack->arr[i] = stack->arr[i - 1];
		stack->arr[0] = temp;
	}
	else
	{
		temp = stack->arr[0];
		i = -1;
		while (++i < stack->top)
			stack->arr[i] = stack->arr[i + 1];
		stack->arr[stack->top] = temp;
	}
}

void	c_double_rotate(t_stack *a, t_stack *b, int up)
{
	c_rotate(a, up);
	c_rotate(b, up);
}
