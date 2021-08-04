/*
** EPITECH PROJECT, 2021
** strdup
** File description:
** strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    return (my_strcpy(dest, src));
}
