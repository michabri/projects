#include "King.h"

//-------------------------------------------------------------------------
void King::handleCollision(GameObject& other_object)
{
	other_object.handleCollision(*this);
}