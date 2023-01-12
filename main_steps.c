/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:16:50 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/12 22:00:09 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*init_parse(char **args, int size)
{
	char	*tab;
	int		i;

	i = 1;
	tab = ft_strdup(args[i]);
	while (++i < size)
	{
		tab = ft_strjoin_gnl(tab, " ");
		tab = ft_strjoin_gnl(tab, args[i]);
	}
	return (tab);
}

void	str_to_tab(t_stack *stack_a, char *tab, int checker)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(tab, ' ');
	while (split[i])
		i++;
	stack_a->arr = malloc(i * sizeof(int));
	i = 0;
	while (split[i])
	{
		check_edge(split[i]);
		stack_a->arr[i] = ft_ps_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	if (!dub_control(stack_a->arr, i))
		error();
	if (checker == 0 && (!sort_control(stack_a->arr, i) || i == 1))
		exit(0);
	stack_a->top = i - 1;
}

void	rev_tab(t_stack *stack_a)
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
