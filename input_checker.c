/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 12:03:12 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/28 17:53:37 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_good_order(t_element * chain_a)
{
	while (chain_a != NULL && chain_a->next != NULL)
	{
		if (chain_a->i_number > chain_a->next->i_number)
			return (0);
		chain_a = chain_a->next;
	}
	return (1);
}

int	check_arg(char *argv)
{
	if (ft_strcmp(argv, "--simple") == 0 || ft_strcmp(argv, "--medium") == 0
			|| ft_strcmp(argv, "--complex") == 0 || ft_strcmp(argv, "--adaptive") == 0
	|| ft_strcmp(argv, "--bench") == 0)
	return (1);
	return (0);
}

int	which_arg(char *argv)
{
	if (ft_strstr(argv, "--simple") != NULL)
		return (1);
	if (ft_strstr(argv, "--medium") != NULL)
		return (2);
	if (ft_strstr(argv, "--complex") != NULL)
		return (3);
	if (ft_strstr(argv, "--adaptive") != NULL)
		return (4);
	if (ft_strstr(argv, "--bench") != NULL)
		return (5);
	return (0);
}

int	read_arg(char **argv)
{
	int	i;
	int	func_complexity;
	int	bench_indicator;
	int	check_val;

	check_val = 0;
	bench_indicator = 0;
	func_complexity = 4;
	i = 0;
	while (argv[i])
	{
		check_val = which_arg(argv[i]);
		if (check_val == 5)
			bench_indicator = 10;
		else if (check_val != 0)
			func_complexity = check_val;
		i++;
	}
	return (bench_indicator + func_complexity);
}

int	clean(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (str == NULL || str[i] == NULL)
		return (0);
	while (str[i])
	{
		j = 0;
		if (check_arg(str[i]) != 1)
		{
			if (str[i][j] == '-' || str[i][j] == '+')
				j++;
			if (str[i][j] == '\0')
				return (0);
			while (str[i][j])
			{
				if (str[i][j] < '0' || str[i][j] > '9')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}
