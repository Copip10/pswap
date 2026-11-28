/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:56:00 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/28 17:57:24 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start_resolve(t_element * *chain_a, t_element * *chain_b, int func_complex)
{
	double	disorder_nbr;

	disorder_nbr = f_disorder(chain_a);
	if (func_complex % 10 == 4)
		func_complex = check_func_complex(disorder_nbr, func_complex);
	if (func_complex % 10 == 1)
		extrac_min(chain_a, chain_b);
	if (func_complex % 10 == 2)
		chunk_based_sort(chain_a, chain_b);
	if (func_complex % 10 == 3)
		com_start_complex(chain_a, chain_b);
	if (func_complex >= 10)
		f_bench(disorder_nbr, func_complex);
	return (1);
}

int	main(int argc, char **argv)
{
	int			i;
	int			func_complex;
	t_element	*lst_top_a;
	t_element	*lst_top_b;

	lst_top_a = NULL;
	lst_top_b = NULL;
	if (argc < 2)
		return (0);
	func_complex = read_arg(argv);
	i = split_and_fill(argv, &lst_top_a);
	if (i != 1)
	{
		free_list(&lst_top_a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_good_order(lst_top_a) != 1)
		start_resolve(&lst_top_a, &lst_top_b, func_complex);
	free_list(&lst_top_a);
	free_list(&lst_top_b);
	return (0);
}
