/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:39:30 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/26 18:03:45 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int	*com_create_tab(void)
{
int	*tab;
int	i;

i = 0;
tab = malloc(sizeof(int) * 11);
while (i < 11)
{
tab[i] = 0;
i++;
}
tab[i] = '\0';
return (tab);
}

int	com_recover_digit(int full_number, int digit_index)
{
int	i;

if (full_number < power(10, digit_index))
return (0);
else
i = 0;
while (i < digit_index)
{
full_number = full_number / 10;
i++;
}
return (full_number % 10);
}

int	*com_recover_values(f_element * *chain, int *tab, int digit_index)
{
f_element * iterate;
iterate = *chain;
int	i;

i = 0;
while (iterate && iterate->next)
{
tab[i] = com_recover_digit(iterate->i_number, digit_index);
i++;
iterate = iterate->next;
}
return (tab);
}
*/

void	com_fill_index(f_element * *chain)
{
	f_element * iterate;
	int	to_stock;

	f_element * curr;
	iterate = *chain;
	curr = iterate;
	while (curr)
	{
		to_stock = 0;
		iterate = *chain;
		while (iterate)
		{
			if (curr->i_number > iterate->i_number)
				to_stock += 1;
			iterate = iterate->next;
		}
		curr->index = to_stock;
		curr = curr->next;
	}
}

int	com_get_bit(int index, int bit)
{
	return ((index >> bit) & 1);
}

void	com_one_pass(f_element * *a, f_element * *b, int size, int bit)
{
	int	count;

	count = 0;
	while (count < size)
	{
		if (com_get_bit((*a)->index, bit) == 0)
			pb(a, b);
		else
			ra(a, 1);
		count++;
	}
	while (*b)
		pa(a, b);
}

int	com_maxbits(int size)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		size = size >> 1;
		i++;
	}
	return (i);
}

void	com_start_complex(f_element * *chain_a, f_element * *chain_b)
{
	int	size;
	int	max_bits;
	int	bit;

	size = lst_size(*chain_a);
	max_bits = com_maxbits(size - 1);
	com_fill_index(chain_a);
	bit = 0;
	while (bit < max_bits)
	{
		com_one_pass(chain_a, chain_b, size, bit);
		bit++;
	}
}
