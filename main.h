#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <cmath>
#include <string>

#include "Animation.h"
#include "Entity.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Player.h"

#ifndef MAIN_H
#define MAIN_H

bool isCollide(Entity *a, Entity *b);
void keyPressEventHandler(RenderWindow *app, Animation *sBullet, std::list<Entity *> *entities, player *p, Event *event);
void bulletAsteroidCollisionHandler(Entity *a, Entity *b, Animation *sExplosion, Animation *sRock_small, std::list<Entity *> *entities);
void playerAsteroidCollisionHandler(player *p, Entity *a, Entity *b, Animation *sExplosion_ship, Animation *sPlayer, std::list<Entity *> *entities);
void handleUserAction(Event &event, RenderWindow &app, Animation &sBullet, std::list<Entity *> &entities, player *p, bool &game_over, bool &paused, Sprite &background, int &score, sf::Text &text);
void checkCollisions(std::list<Entity*> &entities, player *p, Animation &sExplosion, Animation &sRock_small, Animation &sRock, Animation &sExplosion_ship, Animation &sPlayer, RenderWindow &app, int &score, sf::Text &text, bool &game_over);
void updateEntities(std::list<Entity*> &entities);

#endif // MAIN_H
