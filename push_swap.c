#include "push_swap.h"

static f_element   *f_start_node(int number)
{
    f_element   *new;

    new = malloc(sizeof(*new));
    new->i_number = number;
    new->next = NULL;
    new->previous = NULL;
    return new;
}


static void *print_all_chain(f_element  *node_top)
{
    f_element   *iter;
    iter = node_top;

    while (iter)
    {
        printf("[%d] ", iter->i_number);
        iter = iter->next;
    }
    printf("\n");
}


static int  generate_chain(char **argv)
{

    

}
int main(int argc, char **argv)
{
    f_element *monmaillon;
    f_element *monmaillon1;
    f_element *monmaillon2;
    f_element *monmaillon3;

    monmaillon = f_start_node(3);
    monmaillon1 = f_start_node(5);
    monmaillon2 = f_start_node(6);
    monmaillon3 = f_start_node(7);
    monmaillon->next = monmaillon1;
    monmaillon1->next = monmaillon2;

    print_all_chain(monmaillon);
    ////////////////////////////////////////////////////////////////////

    sa(monmaillon);
    print_all_chain(monmaillon);

    ///////////////////////////////////////////////////////////////////

    pa(&monmaillon, &monmaillon3);
    print_all_chain(monmaillon);

    ///////////////////////////////////////////////////////////////////
    
    ra(&monmaillon);
    print_all_chain(monmaillon);

    ///////////////////////////////////////////////////////////////////
    
    rra(&monmaillon);
    print_all_chain(monmaillon);

    return 1;
}

// int main(int argc, char **argv)
// {
//     f_element *monmaillon;
//     f_element *monmaillon1;
//     f_element *monmaillon2;
//     f_element *monmaillon3;
//     monmaillon = f_start_node(3);
//     monmaillon1 = f_start_node(5);
//     monmaillon2 = f_start_node(6);
//     monmaillon3 = f_start_node(7);
//     monmaillon->next = monmaillon1;
//     monmaillon1->next = monmaillon2;
//     print_all_chain(monmaillon);
//     ////////////////////////////////////////////////////////////////////
//     sa(monmaillon);
//     print_all_chain(monmaillon);
//     ///////////////////////////////////////////////////////////////////
//     pa(&monmaillon, &monmaillon3);
//     print_all_chain(monmaillon);
//     /////////////////////////////////////////////////////////////////// 
//     ra(&monmaillon);
//     print_all_chain(monmaillon);
//     ///////////////////////////////////////////////////////////////////
//     rra(&monmaillon);
//     print_all_chain(monmaillon);
//     return 1;
// }