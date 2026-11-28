/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:02:06 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/28 10:13:29 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_element * lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static int	find_min_pos(t_element * lst)
{
	int	min;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	min = lst->i_number;
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

void	extrac_min(t_element * *a, t_element * *b)
{
	int	pos;
	int	size;

	while (*a)
	{
		size = lst_size(*a);
		pos = find_min_pos(*a);
		if (pos <= size / 2)
			while (pos > 0)
			{
				ra(a, 1);
				pos--;
			}
		else
			while (pos < size)
			{
				rra(a, 1);
				pos++;
			}
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}
