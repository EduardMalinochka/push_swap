/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:50:24 by elukutin          #+#    #+#             */
/*   Updated: 2022/12/29 17:09:56 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>



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

void	butter_arg(ft_stack *stack_a, ft_stack *stack_b, int size)
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
			write(1, "pb\n", 3);
			rotate(stack_b, 1);
			write(1, "rb\n", 3);
			count++;
		}
		else if (stack_a->arr[stack_a->top] <= count + n)
		{
			push(stack_b, stack_a);
			write(1, "pb\n", 3);
			i = stack_a->top;
			count++;
		}
		else
		{
			rotate(stack_a, 1);
			write(1, "ra\n");
		}
	}
	while (stack_b->top >= 0)
	{
		if (stack_b->arr[stack_b->top] ==  stack_b->top)
		{
			push(stack_a, stack_b);
			write(1, "pa\n", 3);
		}
	}
}

void sort_3_elem(ft_stack *stack_a) //assuming that sorted array won't go here, I don't do swaps I just print the steps for the bot 
{
	if (stack_a->arr[0] == 1 && stack_a->arr[1] == 0)
	{
		rotate(stack_a->arr, 0);
		write(1, "rra\n", 4);
	}
	if (stack_a->arr[0] == 2 && stack_a->arr[1] == 1)
	{	
		rotate(stack_a->arr, 1);
		write(1, "ra\n", 3);}
	if (stack_a->arr[0] == 0)
	{	
		write(1, "sa\n", 3);
		return ;
	}
	if (stack_a->arr[0] == 1)
		write(1, "ra/n", 3);
	if (stack_a->arr[0] == 2)
		write(1, "rra\n");
}
