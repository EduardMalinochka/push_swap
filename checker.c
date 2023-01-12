/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:29:44 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/12 22:00:48 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	is_rule(char *rule)
{
	static char	*rules[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	int			i;

	i = 0;
	while (rules[i])
	{
		if (ft_strncmp(rules[i], rule, 5) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	choose_act(char *rule, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp("sa\n", rule, 4) == 0)
		c_swap(stack_a);
	else if (ft_strncmp("sb\n", rule, 4) == 0)
		c_swap(stack_b);
	else if (ft_strncmp("ss\n", rule, 4) == 0)
		c_ss(stack_a, stack_b);
	else if (ft_strncmp("pa\n", rule, 4) == 0)
		c_push(stack_a, stack_b);
	else if (ft_strncmp("pb\n", rule, 4) == 0)
		c_push(stack_b, stack_a);
	else if (ft_strncmp("ra\n", rule, 4) == 0)
		c_rotate(stack_a, 1);
	else if (ft_strncmp("rb\n", rule, 4) == 0)
		c_rotate(stack_b, 1);
	else if (ft_strncmp("rr\n", rule, 4) == 0)
		c_double_rotate(stack_a, stack_b, 1);
	else if (ft_strncmp("rra\n", rule, 5) == 0)
		c_rotate(stack_a, 0);
	else if (ft_strncmp("rrb\n", rule, 5) == 0)
		c_rotate(stack_b, 0);
	else if (ft_strncmp("rrr\n", rule, 5) == 0)
		c_double_rotate(stack_a, stack_a, 0);
}

void	check_and_apply(t_stack *stack_a)
{
	char	*res;
	t_stack	*stack_b;

	res = get_next_line(0);
	stack_b = malloc(sizeof(t_stack));
	stack_b->arr = malloc(stack_a->top * sizeof(int));
	while (res)
	{
		if (!is_rule(res))
		{
			free(stack_b->arr);
			free(stack_b);
			error();
		}
		choose_act(res, stack_a, stack_b);
		res = get_next_line(0);
	}
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
		str_to_tab(stack_a, init_tab, 1);
		rev_tab(stack_a);
		sorted_arr = insert_sort(stack_a->arr, stack_a->top + 1);
		val_to_ind(stack_a, sorted_arr);
		check_and_apply(stack_a);
		if (!sorted_stack(stack_a))
		{
			ft_putendl_fd("KO", 1);
			return (0);
		}
		ft_putendl_fd("OK", 1);
	}
}
