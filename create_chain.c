/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:47:05 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/28 11:12:38 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_element * *chain)
{
	t_element * current;
	t_element * previus;
	current = *chain;
	while (current)
	{
		previus = current->next;
		while (previus)
		{
			if (previus->i_number == current->i_number)
				return (0);
			previus = previus->next;
		}
		current = current->next;
	}
	return (1);
}

int	f_add_node(t_element * *chain, t_element * *node)
{
	t_element * iterate;
	iterate = (*chain);
	while (iterate->next != NULL)
		iterate = iterate->next;
	iterate->next = (*node);
	return (1);
}

int	start_fill(long number, t_element * *chain, int (*func)(t_element * *, t_element * *))
{
	t_element * tmp;
	number = (int) number;
	tmp = f_start_node(number, 1);
	if (*chain == NULL)
		*chain = tmp;
	else
		func(chain, &tmp);
	return (1);
}

int	is_it_int(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (check_arg(str[i]) == 0)
		{
			if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
				return (0);
		}
		i++;
	}
	return (1);
}

int	split_and_fill(char **av, t_element * *chain)
{
	int		j;
	int		i;
	char	**str_mult_val;

	i = 0;
	j = 1;
	while (av[j])
	{
		i = 0;
		str_mult_val = ft_split(av[j], ' ');
		if (clean(str_mult_val) != 1 || is_it_int(str_mult_val) != 1)
			return (free_split(str_mult_val), 0);
		while (str_mult_val[i])
		{
			if (check_arg(str_mult_val[i]) == 0)
				start_fill(ft_atoi(str_mult_val[i]), chain, f_add_node);
			i++;
		}
		j++;
		free_split(str_mult_val);
	}
	if (check_double(chain) != 1)
		return (0);
	return (1);
}
