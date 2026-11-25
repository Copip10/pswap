#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct f_element
{

    int i_number;
    struct f_element   *next;

}   f_element;



void    sa(f_element *node_top, int print);
void    sb(f_element *node_top, int print);

void    ss(f_element *node_top_a, f_element *node_top_b);
void    pa(f_element **node_top_a, f_element **node_top_b);
void    pb(f_element **node_top_a, f_element **node_top_b);
void    ra(f_element **node_top_a, int print);
void    rb(f_element **node_top_b, int print);
void    rr(f_element **node_top_a, f_element **node_top_b);
void    rra(f_element **node_top_a, int print);
void    rrb(f_element **node_top_b, int print);
void    rrr(f_element **node_top_a, f_element **node_top_b);

int	is_good_order(f_element *chain_a);
int	check_arg(char *argv);
char	**ft_split(char const *s, char c);
int	ft_atoi(char *str);
f_element   *f_start_node(int number, int opt);
void print_all_chain(f_element  *node_top);
int	check_double(f_element **chain);
int	split_and_fill(int ac, char **av, f_element **mychain);
void	extrac_min(f_element **a, f_element **b);
int	start_fill(int number, f_element **chain, int (*func)(f_element **, f_element **));
int read_arg(char **argv);
char	*ft_strstr(char *haystack, char *needle);
int	ft_strcmp(char *s1, char *s2);

#endif