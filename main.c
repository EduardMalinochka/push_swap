/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:16:23 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/12 22:00:31 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_choice(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = malloc(sizeof(t_stack));
	stack_b->top = -1;
	if (stack_a->top == 1)
	{
		ft_putstr_fd("sa\n", 1);
		return ;
	}
	if (stack_a->top == 2)
	{
		sort_3_elem(stack_a);
		return ;
	}
	stack_b->arr = malloc((stack_a->top + 1) * sizeof(int));
	if (stack_a->top == 4)
	{
		sort_5_elem(stack_a, stack_b, 1);
		return ;
	}
	butter_arg(stack_a, stack_b, stack_a->top + 1);
	free(stack_b->arr);
	free(stack_b);
}

int	main(int ac, char **av)
{
	char	*init_tab;
	int		*sorted_arr;
	t_stack	*stack_a;

	if (ac > 1)
	{
		init_tab = init_parse(av, ac);
		stack_a = malloc(sizeof(t_stack));
		str_to_tab(stack_a, init_tab, 0);
		rev_tab(stack_a);
		sorted_arr = insert_sort(stack_a->arr, stack_a->top + 1);
		val_to_ind(stack_a, sorted_arr);
		alg_choice(stack_a);
	}
	return (0);
}
