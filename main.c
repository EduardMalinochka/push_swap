/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:16:23 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/03 13:14:22 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_handler(ft_stack *stack_a, int size, char **args)
{
	int	i;
	int	j;
	int arg_tab[size];
	int *dub_tab[size];

	// i = 1;
	j = 0;
	i = size - 1;
	stack_a->arr = malloc(size * sizeof(int)); // maybe I won't need to mallocate the array here. I will create an array, check it, convert it to an array of indexes and then mallocate indexes
	if (!stack_a->arr)
		return (0);
	// while (j <= size)
	while (i > 0)
	{
		if (!ft_isdigit(args[i]))				// in case of norminette problems I can write some deleting function
		{
			free(stack_a->arr);
			free(stack_a);
			return (0);
		}
		stack_a->arr[j] = ft_atoi(args[i]); // probably I will store original values in arg_tab, and I won't fill the arr in stack untill every check is done, so it will be arg_tab[j] = ...
		i--;
		j++; // So I'm filling the stack in reverse order. My first element will actually be on top
	}
	// If I will return sorted integer tab, than I will mallocate it on this step i guess
	if (!dub_control(&dub_tab, i))
		{
			free(stack_a->arr);
			free(stack_a);
			return (0);
		}
	stack_a->top = size - 1;
	alg_choice(stack_a, size - 1); // if everything went smoothly send the stack further
	return (1);          // 1 is succes, no Error
}

void alg_choice(ft_stack *stack_a, int size)
{
	// probably i will create stack b here
	if (size == 3)
	{
		sort_3_elem(stack_a);
		return ;
	}
	if (size <= 10)
	{	// probably I will use choice arg
		return ;
	}
	// send to the main arg
}

int	main(int ac, char **av)
{
	ft_stack *stack_a;

	if (ac > 2)
	{
		stack_a = malloc(sizeof(stack_a));
		ps_handler(stack_a, av, ac - 1);
		// some function here to handle char** and atoi values. And ac-1 as a size of stack
		if (!ps_handler)
		{
			ft_putstr_fd("Error", 1);
			return (0);
		}
	}
	else
		ft_putstr_fd("Error", 1);
	return (0);
}
