/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_functions_ba.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:34:15 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/28 10:02:39 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_element * *node_top_a, t_element * *node_top_b)
{
	if (node_top_a == NULL || node_top_b == NULL || *node_top_a == NULL || *node_top_b == NULL || (*node_top_a)->next == NULL || (*node_top_b)->next == NULL)
		return ;
	sa(node_top_a, 0);
	sb(node_top_b, 0);
	write(1, "ss\n", 3);
	operation_amount()[2]++;
}

void	rr(t_element * *node_top_a, t_element * *node_top_b)
{
	ra(node_top_a, 0);
	rb(node_top_b, 0);
	write(1, "rr\n", 3);
	operation_amount()[7]++;
}

void	rrr(t_element * *node_top_a, t_element * *node_top_b)
{
	rra(node_top_a, 0);
	rrb(node_top_b, 0);
	write(1, "rrr\n", 4);
	operation_amount()[10]++;
}
