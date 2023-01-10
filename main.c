/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:16:23 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/10 18:26:03 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	*init_parse(char **args, int size) // seemingly it's ok (except the leaks in strjoin)
{
	char	*tab;
	int		i;

	i = 1;
	tab = ft_strdup(args[i]);
	while (++i < size)
	{
		tab = ft_strjoin_gnl(tab, " "); // i will need  to use strjoin from get next line to avoid leaks
		tab = ft_strjoin_gnl(tab, args[i]);

	}
	return (tab);
}

void	str_to_tab(ft_stack *stack_a, char *tab) //seemingly ok
{
	char		**split;
	int			i;

	i = 0;
	split = ft_split(tab, ' ');
	while (split[i])
		i++;
	stack_a->arr = malloc(i * sizeof(int));
	i = 0;
	while (split[i])
	{
		check_edge(split[i]);
		stack_a->arr[i] = ft_ps_atoi(split[i]); //atoi checks for integers out of size and for garbage values
		i++;
	}
	if (!dub_control(stack_a->arr, i))
		error();
	if (!sort_control(stack_a->arr, i) || i == 1)
		exit(0);
	stack_a->top = i - 1;
}

void	rev_tab(ft_stack *stack_a) //works ok
{
	int	i;
	int	j;
	int	temp;

	j = 0;
	i = stack_a->top;
	while (j < i)
	{
		temp = stack_a->arr[i];
		stack_a->arr[i] = stack_a->arr[j];
		stack_a->arr[j] = temp;
		i--;
		j++;
	}
}

void alg_choice(ft_stack *stack_a)
{
	ft_stack *stack_b;

	stack_b = malloc(sizeof(ft_stack));
	stack_b->top = -1;
	if (stack_a->top == 1)
	{
		ft_putstr_fd("sa\n", 1);
		return ;
	}
	if (stack_a->top == 2)
	{	sort_3_elem(stack_a);
		return ;
	}
	stack_b->arr = malloc((stack_a->top + 1) * sizeof(int));
	if (stack_a -> top == 4)
	{
		sort_5_elem(stack_a, stack_b, 1); 
		return ;
	}
	butter_arg(stack_a, stack_b, stack_a->top + 1);
}

int	main(int ac, char **av)
{
	char		*init_tab;	
	int			*sorted_arr;
	ft_stack	*stack_a;

	if (ac > 1)
	{
		init_tab = init_parse(av, ac);
		stack_a = malloc(sizeof(ft_stack));
		str_to_tab(stack_a, init_tab);
		rev_tab(stack_a); 
		sorted_arr = insert_sort(stack_a->arr, stack_a->top + 1);
		val_to_ind(stack_a, sorted_arr);
		alg_choice(stack_a);
	}
	return (0);
}
