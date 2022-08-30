#include "Warrior.h"

//-------------------------------------------------------------------------
void Warrior::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}