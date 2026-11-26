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

void	print_all_chain(f_element * node_top)
{
	f_element * iter;
	iter = node_top;
	while (iter)
	{
		printf("[%d] ", iter->i_number);
		iter = iter->next;
	}
	printf("\n");
}

int	start_resolve(f_element * *chain_a, f_element * *chain_b, int func_complex)
{
	if (func_complex % 10 == 1)
		extrac_min(chain_a, chain_b);
	if (func_complex % 10 == 3)
		com_start_complex(chain_a, chain_b);
	printf("%d", func_complex);
	return (1);
}

// int	main(int argc, char **argv)
// {
// 	int	i;
// 	int	func_complex;

// 	func_complex = read_arg(argv);
// 	f_element * lst_top_a = NULL;
// 	f_element * lst_top_b = NULL;
// 	i = split_and_fill(argv, &lst_top_a);
// 	if (i != 1)
// 		write(2, "Error\n", 6);
// 	if (is_good_order(lst_top_a) == 1)
// 		return (0);
// 	start_resolve(&lst_top_a, &lst_top_b, func_complex);
// 	print_all_chain(lst_top_a);
// 	return (0);
// }
