/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_functions_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:32:21 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/28 10:02:37 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_element * *node_top, int print)
{
	t_element * first;
	t_element * second;
	if (node_top == NULL || *node_top == NULL || (*node_top)->next == NULL)
		return ;
	first = *node_top;
	second = (*node_top)->next;
	first->next = second->next;
	second->next = first;
	*node_top = second;
	if (print == 1)
	{
		write(1, "sb\n", 3);
		operation_amount()[1]++;
	}
}

void	pb(t_element * *node_top_a, t_element * *node_top_b)
{
	t_element * tmp;
	if (*node_top_a == NULL)
		return ;
	tmp = *node_top_a;
	*node_top_a = (*node_top_a)->next;
	tmp->next = *node_top_b;
	*node_top_b = tmp;
	write(1, "pb\n", 3);
	operation_amount()[4]++;
}

void	rb(t_element * *node_top_b, int print)
{
	t_element * first;
	t_element * iterate;
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
	{
		write(1, "rb\n", 3);
		operation_amount()[6]++;
	}
}

void	rrb(t_element * *node_top_b, int print)
{
	t_element * tmp;
	t_element * iterate;
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
	{
		write(1, "rrb\n", 4);
		operation_amount()[9]++;
	}
}
