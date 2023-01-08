/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:16:23 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/08 13:33:43 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*init_parse(char **args, int size) // seemingly it's ok (except the leaks in strjoin)
{
	char	*tab;
	int		i;

	i = 1;
	tab = args[i];
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
	// mallocate the stack I guess
	split = ft_split(tab, ' ');
	while (split[i])
		i++;
	stack_a->arr = malloc(i * sizeof(int));
	i = 0;
	while (split[i])
	{
		stack_a->arr[i] = ft_ps_atoi(split[i]); //atoi checks for integers out of size and for garbage values
		i++;
	}
	if (!dub_control(stack_a->arr, i))
		error();
	if (!sort_control(stack_a->arr,  i))
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

// void alg_choice(ft_stack *stack_a, int size)
// {
// 	// probably i will create stack b here
// 	if (size == 3)
// 	{
// 		sort_3_elem(stack_a);
// 		return ;
// 	}q
// 	if (size <= 10)
// 	{	// probably I will use choice arg
// 		return ;
// 	}
// 	// send to the main arg
// }

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
		sorted_arr = insert_sort(stack_a->arr, stack_a->top);
		val_to_ind(stack_a, sorted_arr);
	}
	return (0);
}
