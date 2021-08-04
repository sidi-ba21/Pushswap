/*
** EPITECH PROJECT, 2021
** radix.c
** File description:
** radix.c
*/

#include "list.h"

void radix(my_list *list)
{
    int z = 0;
    int k = 0;

    for (int x = 0; x < 32; x++) {
        int size = get_size(list->l_a);
        z = (x == 31) ? 1 : 0;
        for (int i = 0; i < size; i++) {
            if ((((list->l_a->data >> x) & 1) == z)) {
                _pb(&(*list), k);
                k = 1;
            }
            else {
                _ra(&(*list), k);
                k = 1;
            }
        }
        size = get_size(list->l_b);
        pa_action(&(*list), size);
    }
}

void pa_action(my_list *list, int size)
{
    for (int i = 0; i < size; i++) {
        my_putchar(' ');
        write(1, "pa", 2);
        my_push_front(&list->l_b, &list->l_a);
    }
}

void _ra(my_list *list, int k)
{
    list = my_ra(list, k);
    k = 1;
}

void _pb(my_list *list, int k)
{
    if (k == 1)
        my_putchar(' ');
    write(1, "pb", 2);
    my_push_front(&list->l_a, &list->l_b);
    k = 1;
}
