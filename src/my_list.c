/*
** EPITECH PROJECT, 2021
** mylist.c
** File description:
** mylist.c
*/

#include "list.h"

linked_list *push(linked_list **head, int new_data)
{
    linked_list* new_node = (linked_list *)
        malloc(sizeof(linked_list));
    if (*head == NULL) {
        new_node->data = new_data;
        new_node->next = new_node->prev = new_node;
        (*head) = new_node;
        return (*head);
    }
    linked_list *last = (*head)->prev;
    new_node->data = new_data;
    new_node->next = (*head);
    (*head)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
    return (*head);
}

linked_list *params_to_list(int ac, char *const *av)
{
    linked_list *list = NULL;
    int i = 1;

    while (i < ac) {
        list = push(&list, my_getnbr(av[i]));
        i++;
    }
    return (list);
}

void printlist(linked_list *head)
{
    linked_list *tmp = head;
    if (head == NULL) {
        my_putstr("list is empty\n");
        return;
    }
    do {
        printf("%d ", head->data);
        head = head->next;
    } while (head != tmp);
    printf("\n");
}

int get_size(linked_list *head)
{
    linked_list *a = head;
    int nb = 0;

    if (head != NULL) {
        do {
            a = a->next;
            nb++;
        } while (a != head);
    }

    return nb;
}
