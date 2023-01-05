/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:16:23 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/05 20:24:44 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*init_parse(char **args, int size)
{
	char	*tab;
	int		i;

	i = 1;
	tab = ft_memcpy(tab, args[i], ft_strlen(args[i]));
	while (++i <= size - 1)
	{
		tab = ft_strjoin(tab, " ");
		tab = ft_strjoin(tab, args[i]);
	}
	return (tab);
}

char	*split_and_check(char *tab)
{
	int		i;
	char	**res;

	i = 0;
	while (tab[i])
	{
		if (ft_isdigit(tab[i]) || tab[i] == ' ')
			i++;
		else
		{
			ft_putstr_fd("Error", 1);
			exit(1);
		}
	}
}

int	ps_handler(ft_stack *stack_a, int size, char **args)
{
	int	i;
	int	j;
	int	init_tab[size];
	int	*sorted_tab;

	i = size;
	j = 0;
	while (i > 0)
	{
		if (!ft_isdigit(args[i]))
			return (0);
		init_tab[j] = ft_atoi(args[i]);
		i--;
		j++;
			// So I'm filling the stack in reverse order. My first element will actually be on top
	}
	if (!dub_control(init_tab, size))
		return (0);
	// do something about potentially sorted array
	if (!sort_control(init_tab, size))
		return (1);
	sorted_tab = insert_sort(init_tab, size);
	stack_a->arr = malloc(size * sizeof(int));
	stack_a->arr = val_to_ind(init_tab, sorted_tab, size);
	free(sorted_tab);
	//alg_choice(stack_a, size);
		// if everything went smoothly send the stack further
	return (1); // 1 is succes, no Error
}

// void alg_choice(ft_stack *stack_a, int size)
// {
// 	// probably i will create stack b here
// 	if (size == 3)
// 	{
// 		sort_3_elem(stack_a);
// 		return ;
// 	}
// 	if (size <= 10)
// 	{	// probably I will use choice arg
// 		return ;
// 	}
// 	// send to the main arg
// }

int	main(int ac, char **av)
{
	ft_stack	*stack_a;

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
