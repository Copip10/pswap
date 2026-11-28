/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmacha <antmacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:32:32 by antmacha          #+#    #+#             */
/*   Updated: 2026/11/28 17:44:28 by antmacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_element
{

	int					i_number;
	struct s_element	*next;
	int					index;

}	t_element;

int	start_resolve(t_element * *chain_a, t_element * *chain_b, int func_complex);

int	is_good_order(t_element * chain_a);
int	check_arg(char *argv);
int	read_arg(char **argv);
int	clean(char **str);

int	check_double(t_element * *chain);
int	start_fill(long number, t_element * *chain, int (*func)(t_element * *, t_element * *));
int	split_and_fill(char **av, t_element * *mychain);

char	**ft_split(char const *s, char c);

int		ft_strcmp(char *s1, char *s2);
char	*ft_strstr(char *haystack, char *needle);
t_element * f_start_node(int number, int opt);

int		ft_strlen(char *str);
long	ft_atoi(char *str);
void	ft_putnbr(int n, int fd);
void	ft_putstr(char *str, int fds);
void	ft_putdouble(double n, int fd);

void	sa(t_element * *node_top, int print);
void	pa(t_element * *node_top_a, t_element * *node_top_b);
void	ra(t_element * *node_top_a, int print);
void	rra(t_element * *node_top_a, int print);

void	sb(t_element * *node_top, int print);
void	pb(t_element * *node_top_a, t_element * *node_top_b);
void	rb(t_element * *node_top_b, int print);
void	rrb(t_element * *node_top_b, int print);

void	ss(t_element * *node_top_a, t_element * *node_top_b);
void	rr(t_element * *node_top_a, t_element * *node_top_b);
void	rrr(t_element * *node_top_a, t_element * *node_top_b);

int		lst_size(t_element * lst);
void	extrac_min(t_element * *a, t_element * *b);

void	chunk_based_sort(t_element * *a, t_element * *b);

void	com_start_complex(t_element * *chain_a, t_element * *chain_b);

int		check_func_complex(double dis_ratio, int func_complex);
double	f_disorder(t_element * *chain_a);
void	f_bench(double disorder, int func_complex);
int		*operation_amount(void);
int		total_ops(void);

void	print_ops(void);

void	free_split(char **str);
void	free_list(t_element * *lst);

#endif
