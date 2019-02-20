/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_putstr
*/

#include <unistd.h>

extern void my_putchar();
extern int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int index = 0;
    while (index < my_strlen(str))
    {
        my_putchar(str[index]);
        ++index;
    }
    return (0);
}
