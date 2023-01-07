/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:16:23 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/06 17:14:01 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*init_parse(char **args, int size)
{
	char	*tab;
	int		i;

	i = 1;
	tab = NULL;
	tab = ft_memcpy(tab, args[i], ft_strlen(args[i]));
	while (++i <= size - 1)
	{
		tab = ft_strjoin(tab, " ");
		tab = ft_strjoin(tab, args[i]);
	}
	return (tab);
}

void	check_num(char *tab)
{
	int		i;

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

ft_stack	*str_to_tab(char *tab)
{
	ft_stack *stack_a;
	char **split;
	int 	i;

	i = 0;
	// mallocate the stack I guess
	split = ft_split(tab, ' ');
	while (split[i])
	{
		stack_a->arr[i] = ft_atoi(split[i]); // !!rewrite atoi special for this project, so it will work with minimal and maximum integers
		if (stack_a->arr[i] > 2147483647 || stack_a->arr[i] < 2147483648)
		{
			free(stack_a->arr);
			free (stack_a);
			ft_putstr_fd("Error", 1); // maybe it would be better to rewrite this part
			exit(1);   // I can return NULL to indicate the fail and free in the main function
		}
		i++;
	}
	if (!dub_control(stack_a->arr, i))
	{	
		ft_putstr_fd("Error", 1); // maybe it would be better to rewrite this part
		exit(1);   // I can return NULL to indicate the fail and free in the main function}
	}
	if (!sort_control)
		exit(1);
	stack_a->top = i;
	return (stack_a);
}

ft_stack *rev_tab(ft_stack *stack_a)
{
	int i;
	int j;
	int temp;

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
	return (stack_a);
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
	char *init_tab;
	ft_stack *stack_a;

	if (ac > 1)
	{ 
		init_tab = init_parse(av, ac);
		check_num(init_tab);
		stack_a = malloc(sizeof(stack_a));
		stack_a = str_to_tab(init_tab);
		stack_a = rev_tab(stack_a);
		
	}
}
