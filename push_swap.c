#include "push_swap.h"

f_element   *f_start_node(int number, int opt)
{
    f_element   *new;

    new = malloc(sizeof(*new));
    if (opt == 0)
        return new;
    else
        new->i_number = number;
    new->next = NULL;
    return new;
}


void print_all_chain(f_element  *node_top)
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


// int	main(int argc, char **argv)
// {
// 	int i ;
	
// 	f_element *lst_top_a;

// 	//lst_top_a = f_start_node(0, 0);
// 	i = split_and_fill(argc, argv, &lst_top_a);
// 	if (i != 1)
// 		printf("Error\n");

	
// 	print_all_chain(lst_top_a);
	
// 	return 1;
// }

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