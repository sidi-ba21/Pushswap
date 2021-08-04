/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "list.h"

static int checker(linked_list *list);

int main(int ac, char **av)
{
    if (ac < 2)
        return (0);
    my_list list = {0};
    list.l_a = params_to_list(ac, av);
    if (ac == 2 || checker(list.l_a) == 0) {
        my_putchar('\n');
        return (0);
    }
    radix(&list);
    write(1, "\n", 1);
    return (0);
}

static int checker(linked_list *list)
{
    linked_list *temp = list;

    for (int i = 0; i < get_size(temp) - 1; i++) {
        if (temp->data > temp->next->data)
            return (temp->next->data);
        temp = temp->next;
    }
    return (0);
}
