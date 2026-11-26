/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leode-fr <leode-fr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 10:59:31 by leode-fr          #+#    #+#             */
/*   Updated: 2026/11/26 11:22:33 by leode-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int lst_size(f_element *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i) <= nb)
	{
		i++;
	}
	return (i);
}
void	chunk_based_sort(f_element **a, f_element **b)
{
	int sqrt = lst_size(*a);
	int chunck = lst_size(*a) / sqrt;
}
int	main(int argc, char **argv)
{
	int i;
	int func_complex;

    func_complex = read_arg(argv);

	f_element *lst_top_a = NULL;
	f_element *lst_top_b = NULL;

	i = split_and_fill(argc, argv, &lst_top_a);
    
	if (i != 1)
		printf("Error\n");

	if (is_good_order(lst_top_a) == 1)
		return (0);
	
	// extrac_min(&lst_top_a, &lst_top_b);
	
	// print_all_chain(lst_top_a);
	int sqrt = ft_sqrt(lst_size(lst_top_a));
    printf("%d\n", sqrt);
	
	return 1;
}