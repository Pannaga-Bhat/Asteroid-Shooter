# Asteroid Shooter Game
This C++ code implements a simple Asteroids-like game using the SFML (Simple and Fast Multimedia Library) for graphics. The game includes classes for different entities like asteroids, bullets, and the player’s spaceship, along with animations for various actions like explosions. The main loop handles user input, collisions, updates, and rendering.

## Running the game
Run the following commands in order on the terminal:

    make
    ./main
Controls are 
1. <kbd>&uarr;</kbd> for speed up
2. <kbd>&darr;</kbd> for slow down
3. <kbd>&larr;</kbd> and <kbd>&rarr;</kbd> for rotation
4. <kbd>Space</kbd> for firing
5. <kbd>P</kbd> to toggle pause
6. <kbd>R</kbd> to restart
7. <kbd>Q</kbd> to quit

## Running tests
Run the following commands in the terminal:

    g++ -std=c++11 -pthread *.cpp googletest/build/lib/libgtest.a -o test_executable -L /mnt/c/Users/HP/Desktop/SE/Demo/SFML-2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system
    ./test_executable
The results of all the tests will now be displayed.

## Classes
- Animation:
    - Attributes:
        - Frame: Current frame of the animation.
        - speed: Speed of the animation.
        - sprite: SFML Sprite object for rendering.
        - frames: Vector of IntRect representing frames of the animation.
    - Methods:
        - update(): Advances the animation frame based on the speed.
        - isEnd(): Checks if the animation has reached its end.
2. Entity:
- Attributes:
    - x, y: Position of the entity.
    - dx, dy: Velocity components.
    - R: Radius of the entity.
    - angle: Rotation angle.
    - life: Flag indicating if the entity is alive.     
    - name: Identifier for the entity type.
    - anim: Animation object for the entity. • Methods:
    - settings(): Initializes entity attributes.
    - update(): Virtual function for updating entity logic.
    - draw(RenderWindow &app): Renders the entity.
    - Destructor: Virtual destructor for proper memory management.

3. Asteroid (Derived from Entity):
- Attributes:
    - Inherits attributes from the base Entity class.
- Methods:
    - update(): Updates asteroid position, providing screen wrapping.

4. Bullet (Derived from Entity):
- Attributes:
    - Inherits attributes from the base Entity class.
- Methods:
    - update(): Updates bullet position and marks it as not alive if it goes out of bounds.
5. Player (Derived from Entity):
- Attributes:
    - Inherits attributes from the base Entity class.
    - thrust: Boolean flag for player thrust.
    - dir: Direction of thrust (1 or -1). 
- Methods:
    - update(): Updates player position and velocity based on thrust and user input.

## Functions
keyPressEventHandler:
- Parameters:
    - app: SFML RenderWindow for event handling.
    - sBullet: Animation for bullets.
    - entities: List of entities in the game. - p: Player object.
    - event: SFML Event object.
- Description:
    - Handles various keyboard events such as shooting bullets and controlling the player’s spaceship.

bulletAsteroidCollisionHandler:
- Parameters:
    - a: Bullet entity.
    - b: Asteroid entity.
    - sExplosion: Animation for explosion.
    - sRock small: Animation for smaller asteroids. - entities: List of entities in the game.
- Description:
    - Handles collisions between bullets and asteroids, triggering animations and creating smaller asteroids upon impact.

playerAsteroidCollisionHandler:
- Parameters:
    - p: Player object.
    - a: Asteroid entity.
    - b: Asteroid entity.
    - sExplosion ship: Animation for player spaceship explosion. - sPlayer: Animation for the player’s spaceship.
    - entities: List of entities in the game.
- Description:
    - Handles collisions between the player’s spaceship and asteroids, triggering animations and reset- ting the player’s position.

main:
- Description:
    - The main game loop where entities are updated, collisions are checked, and rendering is per- formed.
    - Initializes textures, animations,
    - Initializes textures, animations, entities, and handles user input.
    - Features include background rendering, animations for explosions, and random spawning of
    asteroids.
- Inheritance:
    - Inheritance Usage:
        - Asteroid, Bullet, and Player classes inherit from the base Entity class.
        - Inheritance enables the reuse of common entity attributes and methods, promoting code abstraction and organization.
        Other Features:
- Randomized Gameplay:
    - Random spawning of asteroids and random initial directions for asteroids and bullets contribute to dynamic gameplay.
- SFML Integration:
    - The code utilizes the SFML library for graphics rendering, event handling, and window management.
- User Interaction:
    - Player control includes rotation, thrust, and shooting bullets.
- Collision Handling:
    - Collision detection and handling functions manage interactions between bullets, asteroids, and the player’s spaceship.
- Animation Effects:
    - Explosions and changes in animation based on player actions contribute to visual feedback.

## Testing
- CollisionTest: ObjectsCollide
    - Description: Tests the collision detection function (isCollide()) to ensure it accurately detects colli- sions between two entities.
    - Expected Outcome: Expects a true result indicating a collision due to the overlapping positions of the two entities.
- AsteroidCreationTest: AsteroidCreation
    - Description: Validates the creation of an asteroid and the correct application of its attributes using the settings() function.
    - Expected Outcome: Expects the asteroid’s position, radius, and angle to be set according to the provided arbitrary values.


- BulletCreationTest: BulletCreation
    - Description: Ensures the successful creation of a bullet and proper setting of its attributes using the settings() function.
    - Expected Outcome: Expects the bullet’s position, radius, and angle to be set based on the provided arbitrary values.
- PlayerMovementTest: PlayerMovement
    - Description: Verifies that the player’s movement updates correctly when the update() function is called.
    - Expected Outcome: Expects changes in the player’s velocity components after calling the update()
    function.
- KeyPressEventHandlerTest: SpaceBar
    - Description: Checks if the keyPressEventHandler() function correctly adds bullets to the entities list when the spacebar is pressed.
    - Expected Outcome: Expects the entities list to contain bullets after simulating spacebar presses, demon- strating proper event handling.
- IntegrationTest: ObjectsCollide
    - Description: Serves as an integration test by simulating the interaction between functions, specifically keyPressEventHandler, update, and isCollide.
    - Expected Outcome: Expects a true result indicating a collision between the last added bullet and a dynamically allocated entity (b). Demonstrates the integrated functionality of different parts of the code.

