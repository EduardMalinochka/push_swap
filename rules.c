/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:21:57 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/11 16:50:18 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(ft_stack *stack)
{
	int	temp;

	if (stack->top > 0)
	{
		temp = stack->arr[stack->top - 1];
		stack->arr[stack->top - 1] = stack->arr[stack->top];
			stack->arr[stack->top] = temp;
	}
}

void	ss(ft_stack *a, ft_stack *b)
{
	swap(a);
	swap(b);
}

void	push(ft_stack *to, ft_stack *from)
{
	// if (from->top > 0)
	to->top++;
	to->arr[to->top] = from->arr[from->top];
	from->top--;
}

void	rotate(ft_stack *stack, int up) // if up is 1 that rotate up, if up is 0 than reverse rotate
{
	int	temp;
	int	i;

	if (up == 1)
	{
		temp = stack->arr[stack->top];
		i = stack->top;
		while (i > 0)
		{
			stack->arr[i] = stack->arr[i - 1];
			i--;
		}
		stack->arr[0] = temp;
	}
	else
	{
		temp = stack->arr[0];
		i = 0;
		while (i < stack->top)
		{
			stack->arr[i] = stack->arr[i + 1];
			i++;
		}
		stack->arr[stack->top] = temp;
	}
}

void	double_rotate(ft_stack *a, ft_stack *b, int up)
{
	rotate(a, up);
	rotate(b, up);
}
