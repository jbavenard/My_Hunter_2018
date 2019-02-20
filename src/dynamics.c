/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** dynamics
*/
https :  // www.qwant.com/?client=brz-moz&q=gestionnavy+des+singnaux+c
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/macros.h"

         extern int duck_shoot;
extern sfIntRect rect;
extern sfVector2f duck_pos;
extern sfVector2f viseur_pos;
extern sfVector2i viseur_posi;
extern int shoot_count;
extern int click_count;
int crash = 0;

int shoot_duck(void)
{
    if (viseur_pos.x+60 > duck_pos.x  && viseur_pos.x+60 < duck_pos.x + 130 \
    && duck_shoot == 1){
        if (viseur_pos.y+60 > duck_pos.y && viseur_pos.y+60 < duck_pos.y + 94){
            my_putstr("You shot him : ");
            my_put_nbr(shoot_count);
            my_putstr(" time(s). \n");
            shoot_count++;
            crash = 1;
        }
    }

}

int speed_level(int x)
{
    if (crash == 0){
        x = x + shoot_count;
    }
    return (x);
}

sfVector2f set_viseur_pos(void)
{
    viseur_pos.x = viseur_posi.x - 60;
    viseur_pos.y = viseur_posi.y - 60;
    return (viseur_pos);
}

sfIntRect update_duck_sprite(void)
{
    if (rect.left < 220){
    rect.left += 130;
    }
    else
        rect.left = 0;
    return (rect);
}

sfVector2f set_duck_pos(void)
{
    int duck_shoot = shoot_duck();
    duck_pos.x = speed_level(duck_pos.x);
    if (duck_pos.x > WINDOW_WIDTH){
        duck_pos.x = -130;
        duck_pos.y = rand() % 701;
        shoot_count = 1;
        duck_shoot = 0;
        my_putstr("Missed...\n");
    }
    if (duck_pos.y > WINDOW_HEIGHT){
        duck_pos.x = -130;
        duck_pos.y = rand() % 701;
        crash = 0;
    }
    if (crash == 1 && duck_pos.y <= WINDOW_HEIGHT){
        duck_pos.y += 20;
    }
    return (duck_pos);
}
