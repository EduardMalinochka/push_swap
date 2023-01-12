/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:17:45 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/12 17:37:09 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_sack
{
	int	*arr;
	int	top;
}		t_stack;

int		sort_control(int *tab, int size);
void	sort_3_elem(t_stack *stack_a);
void	sort_5_elem(t_stack *stack_a, t_stack *stack_b, int step);
int		ft_sqrt(int n);
void	swap(t_stack *stack, char *s);
void	ss(t_stack *a, t_stack *b);
void	push(t_stack *to, t_stack *from, char *s);
void	rotate(t_stack *stack, int up, char *s);
void	double_rotate(t_stack *a, t_stack *b, int up, char *s);
int		*insert_sort(int *tab, int size);
void	val_to_ind(t_stack *stack_a, int *sort_tab);
int		sort_control(int *tab, int size);
int		dub_control(int *arr, int size);
int		sorted_stack(t_stack *stack_a);
int		ft_ps_atoi(const char *str);
int		find_mid(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
void	error(void);
void	check_edge(char *str);
void	butter_arg(t_stack *stack_a, t_stack *stack_b, int size);
void	chose_act(t_stack *stack_a, t_stack *stack_b);

/*
typedef enum e_intruc
{
	sa,
	sb,
	ss	
}		t_intruc;
*/
#endif