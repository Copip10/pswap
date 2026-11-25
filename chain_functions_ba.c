#include "push_swap.h"

void    ss(f_element *node_top_a, f_element *node_top_b)
{
    if (node_top_a == NULL || node_top_b == NULL)
        return ;
    sa(node_top_a, 0);
    sb(node_top_b, 0);
    write(1, "ss\n", 3);
}

void    rr(f_element **node_top_a, f_element **node_top_b)
{
    ra(node_top_a, 0);
    rb(node_top_b, 0);
    write(1, "rr\n", 3);
}

void    rrr(f_element **node_top_a, f_element **node_top_b)
{
    rra(node_top_a, 0);
    rrb(node_top_b, 0);
    write(1, "rrr\n", 4);
}
