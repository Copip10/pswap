/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leode-fr <leode-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:47:05 by leode-fr          #+#    #+#             */
/*   Updated: 2026/11/23 17:56:31 by leode-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int clean(int argc, char**argv)
{
    int j;

    while(argc - 1 >= 1)
    {
        j = 0;
        while (argv[argc - 1][j] != '\0')
        {
            if (argv[argc - 1][j] == '+' || argv[argc - 1][j] == '-')
            {
                j++;
                while (argv[argc - 1][j] != ' ' && argv[argc - 1][j] != '\0')
                {
					
                    if (argv[argc - 1][j] < '0' || argv[argc - 1][j] > '9')
                        return (0);
                    j++;
                }
				return (1);
            }
            if ((argv[argc - 1][j] < '0' || argv[argc - 1][j] > '9') && argv[argc - 1][j] != '\0')
			{
				printf("test\n");
				return 0;
			}
            j++;
        }
        argc--;
    }
    return (1);
}

int	f_add_node(f_element **chain, f_element **node)
{
	f_element	*iterate;
	iterate = (*chain);
	while (iterate->next != NULL)
		iterate = iterate->next;
	
	iterate->next = (*node);
	return 1;
}

int	start_fill(int number, f_element **chain)
{
	f_element	*tmp;

	tmp = f_start_node(number);
	f_add_node(chain, &tmp);
	return 1;
}
int	split_and_fill(int ac, char **av, f_element **mychain)
{

	int j;

	j = 1;

	while (av[j])
	{
		
		start_fill(ft_atoi(av[j]), mychain);
		j++;
	}


	return 1;
}
int	main(int argc, char **argv)
{
	f_element *lst_top_a;
	
	lst_top_a= f_start_node(5);
	
	split_and_fill(argc, argv, &lst_top_a);
	
	print_all_chain(lst_top_a);
}