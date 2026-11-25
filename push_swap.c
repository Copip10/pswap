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


int	main(int argc, char **argv)
{

	int i ;
	
	f_element *lst_top_a = NULL;
	f_element *lst_top_b = NULL;

	i = split_and_fill(argc, argv, &lst_top_a);
    
	if (i != 1)
    {
		printf("Error\n");
    }

	if (is_good_order(lst_top_a) == 1)
		return (0);
	
	extrac_min(&lst_top_a, &lst_top_b);
	
	print_all_chain(lst_top_a);
	
	return 1;
}
