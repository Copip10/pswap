/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leode-fr <leode-fr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:56:00 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/26 18:35:36 by leode-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

f_element * f_start_node(int number, int opt)
{
	f_element * new;

	new = malloc(sizeof(*new));
	if (opt == 0 || new == NULL)
		return (new);
	else
		new->i_number = number;
	new->next = NULL;
	return (new);
}

int	check_func_complex(double dis_ratio, int func_complex)
{
	if (dis_ratio < 0.2)
		return func_complex - 3;
	if (dis_ratio < 0.5)
		return func_complex - 2;
	
	return func_complex - 1;
	
}
double disorder(f_element **chain_a)
{
	f_element	*iterate_i;
	f_element	*iterate_j;
	double mistakes;
	double pairs;

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
		return 0;
	return mistakes/pairs;
}

int	start_resolve(f_element * *chain_a, f_element * *chain_b, int func_complex)
{
	if (func_complex % 10 == 4)
		func_complex = check_func_complex(disorder(chain_a), func_complex);
	
	if (func_complex % 10 == 1)
		extrac_min(chain_a, chain_b);
	if (func_complex % 10 == 2)
		chunk_based_sort(chain_a, chain_b);
	if (func_complex % 10 == 3)
		com_start_complex(chain_a, chain_b);

	if (func_complex >= 10)
		f_bench(chain_a, chain_b);

	printf("%d", func_complex);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	func_complex;

	func_complex = read_arg(argv);
	f_element * lst_top_a = NULL;
	f_element * lst_top_b = NULL;
	i = split_and_fill(argv, &lst_top_a);
	if (i != 1)
		write(2, "Error\n", 6);
	if (is_good_order(lst_top_a) == 1)
		return (0);
	start_resolve(&lst_top_a, &lst_top_b, func_complex);
	print_all_chain(lst_top_a);
	return (0);
}
