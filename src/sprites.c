/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** sprites
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../include/my.h"

sfSprite *create_sprite(char *filepath)
{
    sfSprite *sprite;
    sfTexture *texture = create_texture(filepath);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}