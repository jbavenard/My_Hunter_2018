/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** textures
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../include/my.h"

sfTexture *create_texture(char *filepath)
{
    sfTexture *texture;
    texture = sfTexture_createFromFile(filepath, NULL);
    if (!texture)
        return (NULL);
    return (texture);
}
