/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_functions_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:32:21 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/26 14:32:21 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(f_element * *node_top, int print)
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
		write(1, "sb\n", 3);
}

void	pb(f_element * *node_top_a, f_element * *node_top_b)
{
	f_element * tmp;
	if (*node_top_a == NULL)
		return ;
	tmp = *node_top_a;
	*node_top_a = (*node_top_a)->next;
	tmp->next = *node_top_b;
	*node_top_b = tmp;
	write(1, "pb\n", 3);
}

void	rb(f_element * *node_top_b, int print)
{
	f_element * first;
	f_element * iterate;
	if (*node_top_b == NULL || (*node_top_b)->next == NULL)
		return ;
	first = (*node_top_b);
	(*node_top_b) = (*node_top_b)->next;
	first->next = NULL;
	iterate = *node_top_b;
	while (iterate->next != NULL)
		iterate = iterate->next;
	iterate->next = first;
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rrb(f_element * *node_top_b, int print)
{
	f_element * tmp;
	f_element * iterate;
	if (*node_top_b == NULL || (*node_top_b)->next == NULL)
		return ;
	tmp = *node_top_b;
	iterate = *node_top_b;
	while (iterate->next->next != NULL)
		iterate = iterate->next;
	*node_top_b = iterate->next;
	iterate->next = NULL;
	(*node_top_b)->next = tmp;
	if (print == 1)
		write(1, "rrb\n", 4);
}
