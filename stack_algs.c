/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:50:24 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/12 13:52:45 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	midpoint_alg(ft_stack *stack_a, ft_stack *stack_b, int size)
// {
// 	while (stack_a -> top > 2 || (stack_a->arr[0] == size && sort_control(stack_a->arr, stack_a->top))) // first element equals to size, because I've turned an array to an indexes
//     {    
//         stack_a->mid = stack_a->top / 2;
//         from_a_to_b(&stack_a, &stack_b);        
//     }
//     while (stack_a -> top != size && stack_a->arr[stack_a->top] != 0)
//         // send from b to a
//     return ;
// }

// void	from_a_to_b(ft_stack *stack_a, ft_stack *stack_b)
// {
// 	while (stack_a->mid > stack_b->top)
// 	{
// 		while (stack_a->arr[stack_a->top] < stack_a->arr[stack_a->mid])
// 		{
// 			push(stack_b, stack_a);
// 			write(1, "pb\n", 3);
// 		}
// 		while (stack_a->arr[0] < stack_a->arr[stack_a->mid])
// 		{
// 			rotate(stack_a, 0);
// 			write(1, "rra\n", 4);
// 			push(stack_b, stack_a);
// 			write(1, "pb\n", 3);
// 		}
// 		while (stack_a->arr[0] > stack_a->arr[stack_a->mid])
// 		{
// 			rotate(stack_a, 1);
// 			write(1, "ra\n", 3);
// 		}
// 	}
// }

// void	choose_arg(ft_stack *stack_a, ft_stack *stack_b)
// {
// }

void	butter_arg(ft_stack *stack_a, ft_stack *stack_b, int size) // if needed in future I can avoid
// sending int size and just use stack->top+1 instead
{
	int n;
	//int i;
	int count;
	int b;

	count = 0;
	n = ft_sqrt(size) + (ft_sqrt(size) * 2 / 5); // for optimization purposes
	//n = 15;
	//if (size > 150)
	//	n = 30;  // from 30 to 36
	while (stack_a->top >= 0)
	{
		if (stack_a->arr[stack_a->top] <= count) // don't forget to check if stack_a top can go to -1. It should
		{
			push(stack_b, stack_a);
			ft_putstr_fd("pb\n", 1);
			if (count > 0)
			{
				rotate(stack_b, 1);
				ft_putstr_fd("rb\n", 1);
			}
			count++;
		}
		else if (stack_a->arr[stack_a->top] <= count + n)
		{
			push(stack_b, stack_a);
			ft_putstr_fd("pb\n", 1);
			//i = stack_a->top; no idea why I added this
			count++;
		}
		else
		{
			rotate(stack_a, 1);
			ft_putstr_fd("ra\n", 1);
		}
	}
	while (stack_b->top >= 0)
	{
		if (stack_b->arr[stack_b->top] != stack_b->top)
		{
			b = find_max(stack_b);
			if (b >= stack_b->top / 2)
			{
				b = stack_b->top - b; 
				while (b > 0)
				{
					rotate(stack_b, 1);
					ft_putstr_fd("rb\n", 1);
					b--;
				}
			}
			else
			{
				while (b >= -1)
				{
					rotate(stack_b, 0);
					ft_putstr_fd("rrb\n", 1);
					b--;
				}
			}
		}
		else
		{
			push(stack_a, stack_b);
			ft_putstr_fd("pa\n", 1);
		}
	}
}

int find_min(ft_stack *stack)
{
	int i;
	int min;

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

int find_max(ft_stack *stack) // ind to understand where thax maximum value lies 
{
	int i;
	int max;

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

int find_mid(ft_stack *stack) // if mid was not found iters, it means its on top
{
	int i;

	i = 0;
	while (i < stack->top)
	{
		if (i != find_min(stack) && i != find_max(stack))
			return (i);
		i++;
	}
	return (i);
}

int sorted_stack(ft_stack *stack_a) // top value should be the lowest, if sorted
{
	int i;

	i = stack_a->top;
	while (i > 0)
	{
		if (stack_a->arr[i] > stack_a->arr[i - 1])
			return (0);
	}
	return (1);
}

void sort_3_elem(ft_stack *stack_a) 
{
	// maybe i will need a condition that checks for sorted status
	if (stack_a->arr[2] == stack_a->arr[find_min(stack_a)])
	{
		swap(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	if (stack_a->arr[0] == stack_a->arr[find_min(stack_a)] 
	&& stack_a->arr[1] == stack_a->arr[find_mid(stack_a)])
	{
		rotate(stack_a, 1);
		ft_putstr_fd("ra\n", 1);
	}
	if (stack_a->arr[0] == stack_a->arr[find_max(stack_a)])
	{
		swap(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	if (stack_a->arr[0] == stack_a->arr[find_mid(stack_a)])
	{
		rotate(stack_a, 1);
		ft_putstr_fd("ra\n", 1);
	}
	if (stack_a->arr[0] == stack_a->arr[find_min(stack_a)])
	{
		rotate(stack_a, 1);
		ft_putstr_fd("rra\n", 1);
	}
}

void sort_5_elem(ft_stack *stack_a, ft_stack *stack_b, int step)
{
	int max;
	int min;

	max = find_max(stack_a);
	min = find_min(stack_a);
	if (max > min)
	{
		max = stack_a->top - max;
		while (max > 0)
		{
			rotate(stack_a, 1);
			ft_putstr_fd("ra\n", 1);
			max--;
		}
	}
	else
	{
		min = stack_a->top - min;
	 	while (min > 0)
		{
			rotate(stack_a, 1);
			ft_putstr_fd("ra\n", 1);
			min--;
		}
	}
	push(stack_b, stack_a);
	ft_putstr_fd("pb\n", 1);
	if (step == 1)
		sort_5_elem(stack_a, stack_b, 0);
	if (step == 0)
	{
		sort_3_elem(stack_a);
		chose_act(stack_a, stack_b);
	}
}

void chose_act(ft_stack *stack_a, ft_stack *stack_b)
{
	if (stack_b->arr[stack_b->top] == 0)
	{
		swap(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	if (stack_b->arr[stack_b->top] == 4)
	{	
		push(stack_a, stack_b);	
		ft_putstr_fd("pa\n", 1);
		rotate(stack_a, 1);
		ft_putstr_fd("ra\n", 1);
	}
	if (stack_b->arr[stack_b->top] == 1)
	{
		push(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);
	}
	if (stack_b->arr[stack_a->top] == 3)
	{
		push(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);
		rotate(stack_a, 1);
		ft_putstr_fd("ra\n", 1);
		push(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);
		rotate(stack_a, 1);
		ft_putstr_fd("ra\n", 1);
	}
	if (stack_b ->arr[stack_b->top] == 0)
	{ //at this point it means I have only 1 in b, so I can just push it
		push(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);
	} 
}

// /4 3/ /0 1/ /0 4/ 4 0/
//              0     0 
