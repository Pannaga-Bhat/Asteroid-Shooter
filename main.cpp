#include "main.h"

using namespace sf;

bool isCollide(Entity *a, Entity *b) {
    return (b->getX() - a->getX()) * (b->getX() - a->getX()) +
               (b->getY() - a->getY()) * (b->getY() - a->getY()) <
           (a->getR() + b->getR()) * (a->getR() + b->getR());
}

void keyPressEventHandler(RenderWindow *app, Animation *sBullet, std::list<Entity *> *entities, player *p, Event *event)
{
    if (event->type == Event::KeyPressed)
        if (event->key.code == Keyboard::Space)
        {
            bullet *b = new bullet();
            b->settings(*sBullet, p->getX(), p->getY(), p->getAngle(), 10);
            entities->push_back(b);
        }

    if (Keyboard::isKeyPressed(Keyboard::Right))
        p->setAngle((p->getAngle() + 3));
    if (Keyboard::isKeyPressed(Keyboard::Left))
        p->setAngle((p->getAngle() - 3));
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        p->setThrust(true);
        p->setDir(1);
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        p->setThrust(true);
        p->setDir(-1);
    }
    else
    {
        p->setThrust(false);
    }
}

void bulletAsteroidCollisionHandler(Entity *a, Entity *b, Animation *sExplosion, Animation *sRock_small, std::list<Entity *> *entities)
{
    a->setLife(false);
    b->setLife(false);

    Entity *e = new Entity();
    e->settings(*sExplosion, a->getX(), a->getY());
    e->setName("explosion");
    entities->push_back(e);

    for (int i = 0; i < 2; i++)
    {
        if (a->getR() == 15)
            continue;
        Entity *e = new asteroid();
        e->settings(*sRock_small, a->getX(), a->getY(), rand() % 360, 15);
        entities->push_back(e);
    }
}

void playerAsteroidCollisionHandler(player *p, Entity *a, Entity *b, Animation *sExplosion_ship, Animation *sPlayer, std::list<Entity *> *entities)
{
    b->setLife(false);
    Entity *e = new Entity();
    e->settings(*sExplosion_ship, a->getX(), a->getY());
    e->setName("explosion");
    entities->push_back(e);
    p->settings(*sPlayer, W / 2, H / 2, 0, 20);
    p->setDx(0);
    p->setDy(0);
}

void handleUserAction(Event &event, RenderWindow &app, Animation &sBullet, std::list<Entity *> &entities, player *p, bool &game_over, bool &paused, Sprite &background, int &score, sf::Text &text){
    if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Q)){
        app.close();
    }
        
    if (game_over && event.type == Event::KeyPressed && event.key.code == sf::Keyboard::R){
        game_over = !game_over;
        app.draw(background);
        text.setString("Score: " + std::to_string(score));
        app.draw(text);
    }

// Toggle pause if the user presses the 'P' key
    if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::P){
        paused = !paused;
    }
    
    // Handle user actions if the game is not over and not paused
    if (!game_over && !paused){
        keyPressEventHandler(&app, &sBullet, &entities, p, &event);
    }
}

// Function to check for collisions between entities
void checkCollisions(std::list<Entity*> &entities, player *p, Animation &sExplosion, Animation &sRock_small, Animation &sRock, Animation &sExplosion_ship, Animation &sPlayer, RenderWindow &app, int &score, sf::Text &text, bool &game_over){
    for (auto a : entities){
        for (auto b : entities){
            if (a->getName() == "asteroid" && b->getName() == "bullet")
                if (isCollide(a, b))
                {
                    score++;
                    bulletAsteroidCollisionHandler(a, b, &sExplosion, &sRock_small, &entities);
                    text.setString("Score: " + std::to_string(score));
                }

            if (a->getName() == "player" && b->getName() == "asteroid")
                if (isCollide(a, b))
                {
                    playerAsteroidCollisionHandler(p, a, b, &sExplosion_ship, &sPlayer, &entities);
                    text.setString("Game Over!!!\nYour Score Was: " + std::to_string(score) + "\nPress R to restart...");
                    score = 0;
                    for (auto e : entities){
                        if (e->getName() == "bullet" || e->getName() == "asteroid"){
                            e->setLife(0);
                        }
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        asteroid *a = new asteroid();
                        a->settings(sRock, rand() % W, rand() % H, rand() % 360, 25);
                        entities.push_back(a);
                    }
                    game_over = true;
                    app.draw(text);
                }
        }
    }
}


void updateEntities(std::list<Entity*> &entities){
    for (auto i = entities.begin(); i != entities.end();)
    {
        Entity *e = *i;

        e->update();
        Animation tmpAnim = e->getAnim();
        tmpAnim.update();
        e->setAnim(tmpAnim);

        if (e->getLife() == false)
        {
            i = entities.erase(i);
            delete e;
        }
        else
            i++;
    }
}


int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(W, H), "Asteroids!");
    app.setFramerateLimit(60);

    Texture t1, t2, t3, t4, t5, t6, t7;
    t1.loadFromFile("images/spaceship.png");
    t2.loadFromFile("images_updated/background.jpg");
    t3.loadFromFile("images/explosions/type_C.png");
    t4.loadFromFile("images/rock.png");
    t5.loadFromFile("images/fire_red.png");
    t6.loadFromFile("images/rock_small.png");
    t7.loadFromFile("images/explosions/type_B.png");

    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite background(t2);

    Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
    Animation sRock(t4, 0, 0, 64, 64, 16, 0.2);
    Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);
    Animation sBullet(t5, 0, 0, 32, 64, 16, 0.8);
    Animation sPlayer(t1, 40, 0, 40, 40, 1, 0);
    Animation sPlayer_go(t1, 40, 40, 40, 40, 1, 0);
    Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);

    int score = 0;
    bool game_over = false;
    bool paused = false;
    bool start = false; // !TODO
    
    // Set font properties
    sf::Text text;
    sf::Font font;
    font.loadFromFile("./subatomic.ttf");
    text.setFont(font); // font is a sf::Font
    text.setString("Score: " + std::to_string(score));
    text.setCharacterSize(24);
    text.setPosition(W/2 - 100, 10);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    std::list<Entity *> entities;

    for (int i = 0; i < 15; i++)
    {
        asteroid *a = new asteroid();
        a->settings(sRock, rand() % W, rand() % H, rand() % 360, 25);
        entities.push_back(a);
    }

    player *p = new player();
    p->settings(sPlayer, 200, 200, 0, 20);
    entities.push_back(p);

    /////main loop/////
    Event event;

    while (app.isOpen())
    {
        
        while (app.pollEvent(event))
        {
            handleUserAction(event, app, sBullet, entities, p, game_over, paused, background, score, text);
        }
        
        if (!paused && !game_over)
        {
            checkCollisions(entities, p, sExplosion, sRock_small, sRock, sExplosion_ship, sPlayer, app, score, text, game_over);
            
            if (p->getThrust())
                p->setAnim(sPlayer_go);
            else
                p->setAnim(sPlayer);

            for (auto e : entities){
                if (e->getName() == "explosion"){
                    if (e->getAnim().isEnd())
                        e->setLife(0);
                }
            }

            if (rand() % 150 == 0)
            {
                asteroid *a = new asteroid();
                a->settings(sRock, 0, rand() % H, rand() % 360, 25);
                entities.push_back(a);
            }
            updateEntities(entities);
        }

        //////draw//////
        app.draw(background);
        for (auto i : entities)
            i->draw(app);
        app.draw(text);
        app.display();
    }

    return 0;
}
