/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:47:05 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/26 17:51:00 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(f_element * *chain)
{
	f_element * current;
	f_element * previus;
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

int	clean(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (str[i] == NULL)
		return (0);
	while (str[i])
	{
		j = 0;
		if (check_arg(str[i]) == 1)
			i++;
		else
		{
			if (str[i][j] == '-' || str[i][j] == '+')
				j++;
			while (str[i][j])
			{
				if (str[i][j] < '0' || str[i][j] > '9')
					return (0);
				j++;
			}
			i++;
		}
	}
	return (1);
}

int	f_add_node(f_element * *chain, f_element * *node)
{
	f_element * iterate;
	iterate = (*chain);
	while (iterate->next != NULL)
		iterate = iterate->next;
	iterate->next = (*node);
	return (1);
}

int	start_fill(int number, f_element * *chain, int (*func)(f_element * *, f_element * *))
{
	f_element * tmp;
	tmp = f_start_node(number, 1);
	if (*chain == NULL)
		*chain = tmp;
	else
		func(chain, &tmp);
	return (1);
}

int	split_and_fill(char **av, f_element * *chain)
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
		if (clean(str_mult_val) != 1)
			return (free(str_mult_val), 0);
		while (str_mult_val[i])
		{
			if (check_arg(str_mult_val[i]) == 0)
				start_fill(ft_atoi(str_mult_val[i]), chain, f_add_node);
			i++;
		}
		j++;
		free(str_mult_val);
	}
	if (check_double(chain) != 1)
		return (0);
	return (1);
}
