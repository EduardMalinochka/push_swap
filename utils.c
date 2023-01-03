/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elukutin <elukutin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:30:59 by elukutin          #+#    #+#             */
/*   Updated: 2023/01/03 18:30:07 by elukutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int *inset_sort(int *tab, int size) // I will use buble sort to small sort arrays, fuck it, I will change it so insert sort
{
    int temp;
    int i;
    int j;

    i = 1;
    while (i < size - 1)
    {
        j = i;
        while (j > 0 && tab[j] < tab[j - 1])
        {
            temp = tab[j];
            tab[j] = tab[i - 1];
            tab[j + 1] = temp;
            j--;
        }
        i++;
    }
    return (tab);
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
