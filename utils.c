/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:30:59 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/06 17:46:43 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int dub_control(int *arr, int size) // I want to have a smart dublication control, using in like a dict in python. Not sure tho how I will implement it
{
    int i;
    int j;

    i = 0;
    while (i <= size - 1)
    {   
        j = i + 1;
        while (j <= size)
        {
            if (arr[i] == arr[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int sort_control(int *tab, int size) // return 0 if array is sorted
{
    int i = 0;
    while (i <= size - 1)
    {
        if (tab[i] < tab[i + 1])
            return (1);
        i++; 
    }
    return (0);
}

int *insert_sort(int *tab, int size)
{
    int *copy;
    int temp;
    int i;
    int j;

    i = 1;
    copy = malloc(size * sizeof(int));
    if (!copy)
        return (0);
    copy = ft_memcpy(copy, tab, size * sizeof(int));
    while (i < size - 1)
    {
        j = i;
        while (j > 0 && copy[j] < copy[j - 1])
        {
            temp = copy[j];
            copy[j] = copy[i - 1];
            copy[j + 1] = temp;
            j--;
        }
        i++;
    }
    return (copy);
}

int *val_to_ind(int *val_tab, int *sort_tab, int size)
{
    int i;
    int j;
    int res[size];

    i = 0;
    while (i <= size)
    {
        j = 0;
        while (val_tab[i] != sort_tab[j])
            j++;
        res[i] = j;
        i++;
    }
    return (res);
}

int ft_sqrt(int n) // probably I can start from the bigger number, depending on the lowest input I would to an alg
{
    int res;

    res = 2;
    while (n / res != res)
        res++;
    return (res);
}

int ft_ps_atoi (const char *str)
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
			{	
                ft_putstr("Error", 1);
                exit(1);
            }
		}
	}
	return (res);
}
