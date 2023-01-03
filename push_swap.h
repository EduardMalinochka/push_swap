/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:17:45 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/03 20:44:20 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_tack
{
	int	*arr;
	int top; // top will hold the index of the variable on top of the stack
	int	mid;
	// that will be the index of the value that should be in the middle (i will find that by initailly sorting)
}		ft_stack;

int		sort_control(int *tab, int size);
void	sort_3_elem(ft_stack *stack_a);
int		ft_sqrt(int n);
void	swap(ft_stack *stack);
void	ss(ft_stack *a, ft_stack *b);
void	push(ft_stack *to, ft_stack *from);
void	rotate(ft_stack *stack, int up);
void	double_rotate(ft_stack *a, ft_stack *b, int up);
int		*inset_sort(int *tab, int size);
int	*val_to_ind(int *val_tab, int *sort_tab, int size);

/*
typedef enum e_intruc
{
	sa,
	sb,
	ss	
}		t_intruc;
*/
#endif