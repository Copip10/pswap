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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_arg(char *argv)
{
	if (ft_strcmp(argv, "--simple") == 0 || ft_strcmp(argv, "--medium") == 0 || ft_strcmp(argv, "--complex") == 0 
	|| ft_strcmp(argv, "--adaptive") == 0 || ft_strcmp(argv, "--bench") == 0 )
		return 1;
	return 0;
}