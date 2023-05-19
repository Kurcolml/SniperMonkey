#include "Collisionable.h"
#include "Classes.h"

bool Collisionable::isCollision(Collisionable& ref)const {

	return getBounds().intersects(ref.getBounds());
}
