/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 10:59:31 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/28 10:02:28 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i) < nb)
	{
		i++;
	}
	return (i);
}

static int	find_index_max_pos(t_element * lst)
{
	int	max;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	max = lst->index;
	while (lst != NULL)
	{
		if (lst->i_number > max)
		{
			max = lst->i_number;
			pos = i;
		}
		lst = lst->next;
		i++;
	}
	return (pos);
}

static void	fill_index(t_element * *a)
{
	t_element * curr;
	t_element * checking;
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

static void	fill_list_a(t_element * *a, t_element * *b)
{
	int	pos;

	while (*b)
	{
		pos = find_index_max_pos(*b);
		if (pos <= lst_size(*b) / 2)
			while (pos > 0)
			{
				rb(b, 1);
				pos--;
			}
		else if (pos > lst_size(*b) / 2)
			while (pos < lst_size(*b))
			{
				rrb(b, 1);
				pos++;
			}
		pa(a, b);
	}
}

void	chunk_based_sort(t_element * *a, t_element * *b)
{
	int	chunk;
	int	sqrt;
	int	i;

	fill_index(a);
	i = 0;
	chunk = ft_sqrt(lst_size(*a));
	sqrt = chunk;
	while (*a)
	{
		while (i < chunk && *a)
		{
			if ((*a)->index < chunk)
			{
				pb(a, b);
				i++;
			}
			else
				ra(a, 1);
		}
		chunk += sqrt;
	}
	fill_list_a(a, b);
}
