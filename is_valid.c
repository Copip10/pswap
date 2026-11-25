/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leode-fr <leode-fr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:03:12 by leode-fr          #+#    #+#             */
/*   Updated: 2026/11/25 11:12:38 by leode-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_good_order(f_element *chain_a)
{
	while (chain_a->next != NULL)
	{
		if (chain_a->i_number > chain_a->next->i_number)
			return (0);
		chain_a = chain_a->next;
	}
	return (1);
}