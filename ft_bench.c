/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 16:11:37 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/28 17:57:28 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_func_complex(double dis_ratio, int func_complex)
{
	if (dis_ratio < 0.2)
		return (func_complex - 3);
	if (dis_ratio < 0.5)
		return (func_complex - 2);
	return (func_complex - 1);
}

double	f_disorder(t_element * *chain_a)
{
	t_element * iterate_i;
	t_element * iterate_j;
	double	mistakes;
	double	pairs;

	iterate_i = *chain_a;
	mistakes = 0;
	pairs = 0;
	while (iterate_i && iterate_i->next)
	{
		iterate_j = iterate_i->next;
		while (iterate_j)
		{
			if (iterate_i->i_number > iterate_j->i_number)
				mistakes += 1;
			pairs += 1;
			iterate_j = iterate_j->next;
		}
		iterate_i = iterate_i->next;
	}
	if (pairs == 0)
		return (0);
	return (mistakes / pairs);
}

void	f_bench(double disorder, int func_complex)
{
	ft_putdouble(disorder, 2);
	write(2, "\n", 1);
	if (func_complex % 10 == 1)
		ft_putstr("Simple : max/min O(n^2)", 2);
	else if (func_complex % 10 == 2)
		ft_putstr("Medium : chunk sort O(n*(n^0.5))", 2);
	else
		ft_putstr("Complex : radix O(n log n)", 2);
	write(2, "\n", 1);
	ft_putstr("totals_ops : ", 2);
	ft_putnbr(total_ops(), 2);
	write(2, "\n", 1);
	print_ops();
}

int	*operation_amount(void)
{
	static int	counts[11];

	return (counts);
}

int	total_ops(void)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 11)
	{
		total += operation_amount()[i];
		i++;
	}
	return (total);
}
