/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/macros.h"

int duck_shoot = 0;
sfIntRect rect = {0, 0, 130, 94};
sfVector2f duck_pos = {-1.f, -1.f};
sfVector2f viseur_pos;
sfVector2i viseur_posi;
int shoot_count = 1;
int click_count = 0;

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, "My Hunter", sfResize | sfClose, NULL);
    if (!window)
        return NULL;
    sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return (window);
}

void display_description(int argc, char **argv)
{
    if (argc > 1){
        if (argv[1][0] == '-' && argv[1][1] == 'h'){
my_putstr("\n\n\nWelcome to My Hunter ! \n\
In this game you must, with your mouse, shoot the monster \
that flies on your screen.\n\
Use any button on your mouse to shoot.\n\
With each successful shot, the monster flies faster.\n\
If you miss it, you go back to the first level.\n\n ENJOY !");
        }
        else my_putstr("Error: Command not found.");
    }
}

int main(int argc, char **argv)
{
    display_description(argc, argv);
    if (argc > 1)
        return (0);
    sfClock *clock;
    sfTime time;
    float seconds;
    clock = sfClock_create();
    sfRenderWindow *window = create_window();
    sfSprite *duck = create_sprite("./data/monster.png");
    sfTexture *duck_texture = create_texture("./data/monster.png");
    sfSprite *viseur = create_sprite("./data/viseur.png");
    sfTexture *viseur_texture = create_texture("./data/viseur.png");
    sfSprite *background = create_sprite("./data/background3.png");
    sfTexture *background_texture = create_texture("./data/background3.png");
    sfEvent event;
    while (sfRenderWindow_isOpen(window))
    {
        sfSprite_setTextureRect(duck, rect);
        sfSprite_setPosition(duck, duck_pos);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.1){
            sfIntRect rect = update_duck_sprite();
            sfClock_restart(clock);
        }
        set_duck_pos();
        duck_shoot = 0;
        sfSprite_setPosition(viseur, viseur_pos);
        viseur_posi = sfMouse_getPositionRenderWindow(window);
        set_viseur_pos();
        while (sfRenderWindow_pollEvent(window, &event)){
            if (event.type == sfEvtClosed){
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtMouseButtonPressed){
                duck_shoot = 1;
                click_count++;
            }
        }
        sfRenderWindow_drawSprite(window, background, NULL);
        sfRenderWindow_drawSprite(window, duck, NULL);
        sfRenderWindow_drawSprite(window, viseur, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(background);
    sfTexture_destroy(background_texture);
    sfRenderWindow_destroy(window);
    return (0);
}