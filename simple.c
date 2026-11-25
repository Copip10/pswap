/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leode-fr <leode-fr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:02:06 by leode-fr          #+#    #+#             */
/*   Updated: 2026/11/25 11:12:58 by leode-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	lst_size(f_element *lst)
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
static int	find_min_pos(f_element *lst)
{
	
	int min;
	int pos;
	int i;

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

void	extrac_min(f_element **a, f_element **b)
{
	int pos;
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
int	main(int argc, char **argv)
{

	// if (argc < 2)
	// 	return (0);
	int i ;
	
	f_element *lst_top_a = NULL;
	f_element *lst_top_b = NULL;

	//lst_top_a = f_start_node(0, 0);
	i = split_and_fill(argc, argv, &lst_top_a);
	if (i != 1)
		printf("Error\n");

	if (is_good_order(lst_top_a) == 1)
		return (0);
	
	extrac_min(&lst_top_a, &lst_top_b);
	
	print_all_chain(lst_top_a);
	
	return 1;
}