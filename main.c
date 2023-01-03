/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:16:23 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/03 20:45:04 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ps_handler(ft_stack *stack_a, int size, char **args)
{
	int	i;
	int	j;
	int init_tab[size];
	int *sorted_tab;

	j = 0;
	i = size - 1;
	while (i > 0)
	{
		if (!ft_isdigit(args[i]))
			return (0);
		init_tab[j] = ft_atoi(args[i]);
		i--;
		j++; // So I'm filling the stack in reverse order. My first element will actually be on top
	}
	if (!dub_control(init_tab, size))
			return (0);
	// do something about potentially sorted array 
	sorted_tab = insert_sort(init_tab, size); //not sure if it will work, I might need to mallocate sorted tab
	stack_a->arr = malloc(size * sizeof(int));
	stack_a->arr = val_to_ind(init_tab, sorted_tab, size);
	alg_choice(stack_a, size); // if everything went smoothly send the stack further
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

int	main(int ac	, char **av)
{
	ft_stack *stack_a;

	if (ac > 2)
	{
		stack_a = malloc(sizeof(stack_a));
		ps_handler(stack_a, av, ac - 1);
		// some function here to handle char** and atoi values. And ac-1 as a size of stack
		if (!ps_handler)
		{
			free(stack_a);
			ft_putstr_fd("Error", 1);
			return (0);
		}
	}
	else
		ft_putstr_fd("Error", 1); // don't forget to consider for the two elems
	return (0);
}
