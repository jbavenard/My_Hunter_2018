/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_put_nbr
*/

#include <unistd.h>

void my_put_nbr(int nb)
{
    char stockstr[5];
    int stock;
    if (nb < 0) {
        nb = nb * -1;
        write(1, "-", 1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    stock = nb % 10 + 48;
    write(1, &stock, 1);
}
