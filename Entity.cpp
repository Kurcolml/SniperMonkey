#include "Classes.h"
#include <iostream>

Entity::Entity()
{

    skinB.loadFromFile("hitbox.png");
    hitbox.setTexture(skinB);
    hitbox.setColor(sf::Color::Transparent);

}

void Entity::Spawn(const char nombre[10])
{
    skin.loadFromFile(nombre);
    model.setTexture(skin);
    
    
    
}
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    target.draw(model, states);

}
sf::FloatRect Entity::getBounds() const
{
    return hitbox.getGlobalBounds();
}
void Entity::Execute() 
{
    //std::cout << "muere" << std::endl;

    //ejecutar accion de hit
}

