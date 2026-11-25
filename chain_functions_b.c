#include "push_swap.h"

void    sb(f_element *node_top, int print)
{
    int tmp;
    if (node_top == NULL)
        return ;
    tmp = node_top->i_number;
    node_top->i_number = node_top->next->i_number;
    node_top->next->i_number = tmp;
    if (print == 1)
     write(1, "sb\n", 3);
}

void    pb(f_element **node_top_a, f_element **node_top_b)
{
    f_element   *tmp;

    if (*node_top_a == NULL)
        return ;
    
     tmp = *node_top_a;
    *node_top_a = (*node_top_a)->next;
    tmp->next = *node_top_b;
    *node_top_b = tmp;
    write(1, "pb\n", 3);
}

void    rb(f_element **node_top_b, int print)
{
    f_element   *first;
    f_element   *iterate;
    if (*node_top_b == NULL || (*node_top_b)->next == NULL)
        return ;
    
    first = (*node_top_b);
    (*node_top_b) = (*node_top_b)->next;
    first->next = NULL;
    iterate = *node_top_b;
    while (iterate->next != NULL)
        iterate = iterate->next;
    iterate->next = first;
    if (print == 1)
        write(1, "rb\n", 3);
}

void    rrb(f_element **node_top_b, int print)
{
    f_element   *tmp;
    f_element   *iterate;
    if (*node_top_b == NULL || (*node_top_b)->next == NULL)
        return ;

    tmp = *node_top_b;
    iterate = *node_top_b;
    while (iterate->next->next != NULL)
        iterate = iterate->next;
    
    *node_top_b = iterate->next;
    iterate->next = NULL;
    (*node_top_b)->next = tmp;
    if (print == 1)
        write(1, "rrb\n", 4);
}
