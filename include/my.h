/*
** EPITECH PROJECT, 2018
** My Hunter
** File description:
** my.h
*/

int my_put_nbr(int nb);

char *my_strupcase (char *str);

void my_putchar(char c);

int my_strlen(char const *str);

int my_putstr(char const *str);

int char_to_int (char *str);

void my_sort_int_array(int *tab, int size);

int my_get_nbr(char const *str);

sfTexture *create_texture(char *filepath);

sfSprite *create_sprite(char *filepath);

int speed_level(int x);

int shoot_duck();

sfVector2f set_viseur_pos();

sfVector2f set_duck_pos();

sfIntRect update_duck_sprite();

void display_stats();



