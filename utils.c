/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:30:59 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/12 20:18:09 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	res;

	res = 2;
	while ((n / res) != res)
		res++;
	return (res);
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	check_edge(char *str)
{
	if (str[1] == '\0')
		if (str[0] == 43 || str[0] == 45)
			error();
}

int	ft_ps_atoi(const char *str)
{
	long	i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] != '\0')
	{
		while (str[i] >= 9 & str[i] <= 13 || str[i] == 32)
			i++;
		if (str[i] == 43 || str[i] == 45)
			if (str[i++] == 45)
				sign *= -1;
		while (str[i] >= 48 && str[i] <= 57)
		{
			res = res * 10 + (str[i++] - 48) * sign;
			if (res > 2147483647 || res < -2147483648)
				error();
		}
		if (!((str[i] >= 48 && str[i] <= 57) || str[i] == '\0'))
			error();
	}
	return (res);
}
