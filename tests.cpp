#include <gtest/gtest.h>
#include "main.h"

// Test if collision detection works correctly
TEST(CollisionTest, ObjectsCollide) {
    Entity* a = new Entity();
    Entity* b = new Entity();

    // Set positions and radii for testing collision
    a->setX(100);
    a->setY(100);
    a->setR(20);

    b->setX(110);
    b->setY(110);
    b->setR(25);

    bool result = isCollide(a, b);

    // Expecting collision between these objects
    EXPECT_TRUE(result);

    delete a;
    delete b;
}

// Test if creating an asteroid sets its position and attributes correctly
TEST(AsteroidCreationTest, AsteroidCreation) {
    Animation anim;
    Texture t4;
    t4.loadFromFile("images/rock.png");
    asteroid* ast = new asteroid();
    ast->settings(anim, 300, 400, 45, 30); // Set arbitrary values for position and attributes

    // Check if the asteroid's settings are applied correctly
    EXPECT_EQ(ast->getX(), 300);
    EXPECT_EQ(ast->getY(), 400);
    EXPECT_EQ(ast->getR(), 30);
    EXPECT_EQ(ast->getAngle(), 45);

    delete ast;
}

// Test if bullet creation and settings are correct
TEST(BulletCreationTest, BulletCreation) {
    Animation anim;
    Texture t5;
    t5.loadFromFile("images/fire_blue.png");

    bullet* b = new bullet();
    b->settings(anim, 200, 200, 90, 15); // Set arbitrary values for position and attributes

    // Check if bullet settings are applied correctly
    EXPECT_EQ(b->getX(), 200);
    EXPECT_EQ(b->getY(), 200);
    EXPECT_EQ(b->getR(), 15);
    EXPECT_EQ(b->getAngle(), 90);

    delete b;
}

// Test player movement update
TEST(PlayerMovementTest, PlayerMovement) {
    Animation anim;
    player* p = new player();
    p->settings(anim, 500, 500, 0, 20); // Set arbitrary values for player

    float initial_dx = p->getDx();
    float initial_dy = p->getDy();

    // Simulate player movement update
    p->update();

    // Check if the player's movement updates correctly
    EXPECT_NE(p->getDx(), initial_dx);
    EXPECT_NE(p->getDy(), initial_dy);

    delete p;
}

// Test case for keyPressEventHaldler function
TEST(KeyPressEventHandlerTest, SpaceBar) {
    RenderWindow app; 
    Animation sBullet; 
    std::list<Entity*> entities;
    player p;

    Event event;
    event.type = Event::KeyPressed;
    event.key.code = Keyboard::Space;


    for(int i = 0; i < 10; i++) {
        app.pollEvent(event); // Simulate pressing the spacebar
        keyPressEventHandler(&app, &sBullet, &entities, &p, &event);
    }
    
    ASSERT_FALSE(entities.empty());
    EXPECT_EQ(entities.size(), 10);

    Entity* bullet = entities.back();
    EXPECT_EQ(bullet->getName(), "bullet");

    // Clean up the dynamically allocated bullet memory
    delete bullet;
}

TEST(IntegrationTest, ObjectsCollide) {
    player p;
    Entity* b = new Entity();

    // Set positions and radii for testing collision
    p.setX(100);
    p.setY(100);
    p.setR(20);
    p.setAngle(0);

    b->setX(160);
    b->setY(100);
    b->setR(20);

    RenderWindow app; 
    Animation sBullet;
    std::list<Entity*> entities;

    Event event;
    event.type = Event::KeyPressed;
    event.key.code = Keyboard::Space;


    for(int i = 0; i < 1; i++) {
        app.pollEvent(event); // Simulate pressing the spacebar
        keyPressEventHandler(&app, &sBullet, &entities, &p, &event);
    }

    for(int i = 0; i < 10; i++){
        entities.back()->update();
    }
    
    bool result = isCollide(entities.back(), b);

    // Expecting collision between these objects
    EXPECT_TRUE(result);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    
    printf("RETURN: %d\n", RUN_ALL_TESTS());
    return 0;
}
