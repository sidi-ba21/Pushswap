/*
** EPITECH PROJECT, 2021
** instruction.c
** File description:
** instruction.c
*/

#include "list.h"

void del_node(linked_list **a)
{
    linked_list *ptr = (*a)->prev;

    if ((*a) == (*a)->next)
        (*a) = NULL;
    else {
        ptr->next = (*a)->next;
        ptr->next->prev = ptr;
        *a = (*a)->next;
    }
}

void my_push_front(linked_list **a, linked_list **b)
{
    linked_list *new = *a;
    linked_list *first = *b;
    linked_list *last = NULL;

    del_node(&(*a));
    if (*b == NULL) {
        *b = new;
        (*b)->next = new;
        (*b)->prev = new;
        return;
    }
    last = (*b)->prev;
    first->prev = new;
    last->next = new;
    new->prev = last;
    new->next = first;
    *b = (*b)->prev;
}

my_list *my_ra(my_list *list, int k)
{
    list->l_a = list->l_a->next;
    if (k == 0)
        write(1, "ra", 2);
    else if (k == 1)
        write(1, " ra", 3);
    return (list);
}
