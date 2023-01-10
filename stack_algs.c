/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:50:24 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/10 15:35:00 by elukutin         ###   ########.fr       */
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
	int i;
	int count;

	count = 0;
	n = ft_sqrt(size) + (ft_sqrt(size) * 2 / 5); // for optimization purposes
	while (stack_a->top >= 0)
	{
		if (stack_a->arr[stack_a->top] <= count) // don't forget to check if stack_a top can go to -1. It should
		{
			push(stack_b, stack_a);
			ft_putstr_fd("pb\n", 1);
			rotate(stack_b, 1);
			ft_putstr_fd("rb\n", 1);
			count++;
		}
		else if (stack_a->arr[stack_a->top] <= count + n)
		{
			push(stack_b, stack_a);
			ft_putstr_fd("pb\n", 1);
			i = stack_a->top;
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
		if (stack_b->arr[stack_b->top] ==  stack_b->top)
		{
			push(stack_a, stack_b);
			ft_putstr_fd("pa\n", 1);
		}
	}
}

int find_min(ft_stack *stack)
{
	int i;

	i = 0;
	while (stack->arr[i] != 0)
		i++;
	return (i);
}

int find_max(ft_stack *stack) // ind to understand where thax maximum value lies 
{
	int i;

	i = 0;
	while (stack->arr[i] != stack->top)
		i++;
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

void sort_3_elem(ft_stack *stack_a) //assuming that sorted array won't go here, I don't do swaps I just print the steps for the bot 
{
	// maybe i will need to add checking sort condition
	if (stack_a->arr[0] == 1 && stack_a->arr[1] == 0)
	{
		rotate(stack_a, 0);
		ft_putstr_fd("rra\n", 1);
	}
	if (stack_a->arr[0] == 2 && stack_a->arr[1] == 1)
	{	
		rotate(stack_a, 1);
		ft_putstr_fd("ra\n", 1);
	}
	if (stack_a->arr[0] == 0)
	{
		swap(stack_a);
		ft_putstr_fd("sa\n", 1);
		return ;
	}
	if (stack_a->arr[0] == 1)
	{	
		rotate(stack_a, 1);
		ft_putstr_fd("ra\n", 1);
	}
	if (stack_a->arr[0] == 2)
	{
		rotate(stack_a, 0);
		ft_putstr_fd("rra\n", 1);
	}
}

void sort_5_elem(ft_stack *stack_a, ft_stack *stack_b)
{
	int max;
	int min;

	max = find_max(stack_a);
	min = find_min(stack_a);
	if (max > min)
	{
		while (max < stack_a->top)
			max++;
		push(stack_b, stack_a);
		ft_putstr_fd("pb\n", 1);
		sort_3_elem(stack_a);
	}
	else
	{
	 	while (min < stack_a->arr)
			min++;
		push(stack_b, stack_a);
		ft_putstr_fd("pb\n", 1);
		sort_3_elem(stack_a);
	}
}

void chose_act(ft_stack *stack_a, ft_stack *stack_b)
{
	if (stack_b ->arr[stack_b->top] == 0)
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
		t_putstr_fd("pa\n", 1);
		rotate(stack_a, 1);
		ft_putstr_fd("ra\n", 1);
		push(stack_a, stack_b);
		t_putstr_fd("pa\n", 1);
		rotate(stack_a, 1);
		ft_putstr_fd("ra\n", 1);
	} 
	while (stack_a->top != -1)
	{ //at this point it means I have only 1 in b, so I can just push it
		push(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);
	} 
}

// /4 3/ /0 1/ /0 4/ 4 0/
//              0     0 
