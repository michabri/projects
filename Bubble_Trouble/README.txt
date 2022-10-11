Final Project: Bubble Trouble

Students info:
Michael Basov - 315223156
Shlomo Gulayev - 318757382
Micha Briskman - 208674713

Summary:
For the final project of the semester we built a game called 'Bubble Trouble'.
In the game, the player controls a chrarcter using the arrow (left, right) keys,
the character has to destroy the bouncing balls on each level using their weapon (press 'space' to shoot)
while avoiding getting hit by them. once every ball is cleared, the game procceeds to next level.
There are four sizes of balls, every size has different color and when the player pops a ball,
two smaller balls drop. A ball can drop a gift, there are different gifts such as different weapons,
shield, extra health and more; On some levels there are doors that open once every ball to the right is popped.
You can play alone or with another player from same computer, or can connect over LAN (wi-fi or physic connection)
to play with another person, the second character is moving using 'A' and 'D' keys for movemennt and shooting with Lshift.

The game is using two C++ libraries, SFML for graphics and Box2d for physics.

List of files (each file has .h and .cpp):
Animation - Controls the animation of the Player class.
Ball - Represnts the ball that the player needs to destroy and avoid getting hit by.
Board - Manages the graphics and drawing and game on the window, manages events on the board.
Button - Represents a button that can be pressed.
Caption - Manages the captions, titles and text seen while playing.
ContactListener - Manages collision between different objects in the game.
Controller - Controls the game and levels, everything is controlled over there.
GameObject - Represnts every object in the game. An abstarct class.
Gate - Controls the gates in the game, opens if all balls to the right are destroyed.
Gift - Represents a gift in the game. An abstract class.
HookWeapon - Represnts a weapon that is sticking to the cieling for 3 seconds before disapearing.
LaserWeapon - Represtns a weapon that is smaller and shoots faster lasers.
macros - Stores important includes, enum classes and const variables that used by few classes. does not has a .cpp file.
Menu - Controls the menu options and buttons.
MovingObjects - Represnts every moving object in the game. An abstarct class.
NormalWeapon - Represtns the default weapon the player starts with.
Player - Represents the player, it's collisions and controls.
Resources - A singlton, loads and stores the textures, pictures and sounds to the game.
Shield - Represnts a gift, if player picks it up he gets a shield for few seconds and can't be hit.
Socket - Represents a socket control for LAN connection.
StaticObject - Represnts every static object in the game. An abstarct class.
Wall - Represents a wall that blocks every object in the game.
Weapon - Represents a weapon. An abstarct class.

Main databases:
vector of Player - stores the players playing.
vector of Ball - stores the active balls in the game
vector of static objects - stores the walls, doors and gifts.

Special algorithms:

Known bugs:

Other:

