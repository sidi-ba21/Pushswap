/*
** EPITECH PROJECT, 2021
** list.h
** File description:
** list.h
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

typedef struct linked_list
{
        int data;
        struct linked_list *next;
        struct linked_list *prev;
} linked_list;

typedef struct my_list
{
    char *instruction;
    linked_list *l_a;
    linked_list *l_b;
}my_list;

my_list *my_ra(my_list *list, int k);
void my_push_front(linked_list **a, linked_list **b);
linked_list  *params_to_list(int ac, char *const *av);
int get_size(linked_list *head);
void printlist(linked_list *head);
linked_list *push(linked_list **head, int new_data);
void radix(my_list *list);
void pa_action(my_list *list, int size);
void _ra(my_list *list, int k);
void _pb(my_list *list, int k);
