#include "push_swap.h"


void    sa(f_element *node_top)
{
    int tmp;
    if (node_top == NULL)
        return ;
    tmp = node_top->i_number;
    node_top->i_number = node_top->next->i_number;
    node_top->next->i_number = tmp;

}

void    sb(f_element *node_top)
{
    int tmp;
    if (node_top == NULL)
        return ;
    tmp = node_top->i_number;
    node_top->i_number = node_top->next->i_number;
    node_top->next->i_number = tmp;
}


void    ss(f_element *node_top_a, f_element *node_top_b)
{
    if (node_top_a == NULL || node_top_b == NULL)
        return ;
    sa(node_top_a);
    sb(node_top_b);
}


void    pa(f_element **node_top_a, f_element **node_top_b)
{
    f_element   *tmp;

    if (*node_top_b == NULL)
        return ;
    
    tmp = *node_top_a;
    *node_top_a = *node_top_b;
    (*node_top_a)->next = tmp;

    (*node_top_b) = (*node_top_b)->next;
    
}

void    pb(f_element **node_top_a, f_element **node_top_b)
{
    f_element   *tmp;

    if (*node_top_a == NULL)
        return ;
    
    tmp = *node_top_b;
    *node_top_b = *node_top_a;
    (*node_top_b)->next = tmp;

    (*node_top_a) = (*node_top_a)->next;
    
}

void    ra(f_element **node_top_a)
{
    f_element   *first;
    f_element   *iterate;
    if (*node_top_a == NULL || (*node_top_a)->next == NULL)
        return ;
    
    first = (*node_top_a);
    (*node_top_a) = (*node_top_a)->next;
    first->next = NULL;
    iterate = *node_top_a;
    while (iterate->next != NULL)
        iterate = iterate->next;

    iterate->next = first;
}

void    rb(f_element **node_top_b)
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
}

void    rr(f_element **node_top_a, f_element **node_top_b)
{
    ra(node_top_a);
    rb(node_top_b);
}

void    rra(f_element **node_top_a)
{
    f_element   *tmp;
    f_element   *iterate;
    if (*node_top_a == NULL || (*node_top_a)->next == NULL)
        return ;

    tmp = *node_top_a;
    iterate = *node_top_a;
    while (iterate->next->next != NULL)
        iterate = iterate->next;
    
    *node_top_a = iterate->next;
    iterate->next = NULL;
    (*node_top_a)->next = tmp;
    
}

void    rrb(f_element **node_top_b)
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
    
}

void    rrr(f_element **node_top_a, f_element **node_top_b)
{
    rra(node_top_a);
    rrb(node_top_b);
}