#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct f_element
{

    int i_number;
    struct f_element   *next;
    struct f_element    *previous;

}   f_element;



void    sa(f_element *node_top);
void    sb(f_element *node_top);
void    ss(f_element *node_top_a, f_element *node_top_b);
void    pa(f_element **node_top_a, f_element **node_top_b);
void    ra(f_element **node_top_a);
void    rb(f_element **node_top_b);
void    rr(f_element **node_top_a, f_element **node_top_b);
void    rra(f_element **node_top_a);
void    rrb(f_element **node_top_b);
void    rrr(f_element **node_top_a, f_element **node_top_b);

#endif