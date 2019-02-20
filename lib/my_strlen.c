/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int index;
    index = 0;

    while (str[index] != '\0'){
        ++index;
    }
    return (index);
}
