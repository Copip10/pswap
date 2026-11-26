/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_functions_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:16:35 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/26 14:33:24 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(f_element * *node_top, int print)
{
	f_element * first;
	f_element * second;
	if (node_top == NULL || *node_top == NULL || (*node_top)->next == NULL)
		return ;
	first = *node_top;
	second = (*node_top)->next;
	first->next = second->next;
	second->next = first;
	*node_top = second;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	pa(f_element * *node_top_a, f_element * *node_top_b)
{
	f_element * tmp;
	if (*node_top_b == NULL)
		return ;
	tmp = *node_top_b;
	*node_top_b = (*node_top_b)->next;
	tmp->next = *node_top_a;
	*node_top_a = tmp;
	write(1, "pa\n", 3);
}

void	ra(f_element * *node_top_a, int print)
{
	f_element * first;
	f_element * iterate;
	if (*node_top_a == NULL || (*node_top_a)->next == NULL)
		return ;
	first = (*node_top_a);
	(*node_top_a) = (*node_top_a)->next;
	first->next = NULL;
	iterate = *node_top_a;
	while (iterate->next != NULL)
		iterate = iterate->next;
	iterate->next = first;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rra(f_element * *node_top_a, int print)
{
	f_element * tmp;
	f_element * iterate;
	if (*node_top_a == NULL || (*node_top_a)->next == NULL)
		return ;
	tmp = *node_top_a;
	iterate = *node_top_a;
	while (iterate->next->next != NULL)
		iterate = iterate->next;
	*node_top_a = iterate->next;
	iterate->next = NULL;
	(*node_top_a)->next = tmp;
	if (print == 1)
		write(1, "rra\n", 4);
}
