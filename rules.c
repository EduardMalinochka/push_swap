/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:21:57 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/13 14:08:05 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *s)
{
	int	temp;

	if (stack->top > 0)
	{
		temp = stack->arr[stack->top - 1];
		stack->arr[stack->top - 1] = stack->arr[stack->top];
			stack->arr[stack->top] = temp;
	}
	ft_putendl_fd(s, 1);
}

void	ss(t_stack *a, t_stack *b)
{
	c_swap(a);
	c_swap(b);
	ft_putendl_fd("ss", 1);
}

void	push(t_stack *to, t_stack *from, char *s)
{
	to->top++;
	to->arr[to->top] = from->arr[from->top];
	from->top--;
	ft_putendl_fd(s, 1);
}

void	rotate(t_stack *stack, int up, char *s)
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
		ft_putendl_fd(s, 1);
	}
	else
	{
		temp = stack->arr[0];
		i = -1;
		while (++i < stack->top)
			stack->arr[i] = stack->arr[i + 1];
		stack->arr[stack->top] = temp;
		ft_putendl_fd(s, 1);
	}
}

void	double_rotate(t_stack *a, t_stack *b, int up)
{
	c_rotate(a, up);
	c_rotate(b, up);
	if (up == 1)
	{
		ft_putendl_fd("rr", 1);
		return ;
	}
	ft_putendl_fd("rrr", 1);
}
