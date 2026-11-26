/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 10:59:31 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/26 18:10:44 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i) < nb)
	{
		i++;
	}
	return (i);
}

static int	find_index_min_pos(f_element * lst)
{
	int	min;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	min = lst->index;
	while (lst != NULL)
	{
		if (lst->i_number < min)
		{
			min = lst->i_number;
			pos = i;
		}
		lst = lst->next;
		i++;
	}
	return (pos);
}

void	fill_index(f_element * *a)
{
	f_element * curr;
	f_element * checking;
	int	index;

	curr = *a;
	while (curr)
	{
		index = 0;
		checking = *a;
		while (checking)
		{
			if (curr->i_number > checking->i_number)
				index++;
			curr->index = index;
			checking = checking->next;
		}
		curr = curr->next;
	}
}

void	chunk_based_sort(f_element * *a, f_element * *b)
{
	int	chunk;
	int	sqrt;
	int	i;
	int	j;
	int	pos;

	fill_index(a);
	i = 0;
	j = 0;
	chunk = ft_sqrt(lst_size(*a));
	sqrt = chunk;
	while (*a)
	{
		while (i < chunk && *a)
		{
			if ((*a)->index >= i && (*a)->index < chunk)
				pb(a, b);
			i++;
		}
		chunk += sqrt;
	}
	while (*b)
		pa(a, b);
}
