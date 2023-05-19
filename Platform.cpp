#include "Classes.h"
# include<iostream>
Platform::Platform() :Entity()
{







}
void Platform::SpawnPla(int id)
{

   

    
    
    sf::Vector2i randPos[12];
    randPos[0].x = 0;
    randPos[0].y = 709;
    randPos[1].x = 174;
    randPos[1].y = 557;
    randPos[2].x = 421;
    randPos[2].y = 711;
    randPos[3].x = 483;
    randPos[3].y = 620;
    randPos[4].x = 621;
    randPos[4].y = 710;
    randPos[5].x = 831;
    randPos[5].y = 492;
    randPos[6].x = 976;
    randPos[6].y = 310;
    randPos[7].x = 1231;
    randPos[7].y = 625;
    randPos[8].x = 1736;
    randPos[8].y = 733;
    rect.setFillColor(sf::Color::Transparent);
   
    switch (id)
    {
    case 0:
        rect.setSize(sf::Vector2f(175,10));
        rect.setPosition(randPos[id].x, randPos[id].y);
        hitbox.setPosition(rect.getPosition().x, rect.getPosition().y);
        hitbox.setScale(30, 1);
        break;
    case 1:
        rect.setSize(sf::Vector2f(245, 10));
        rect.setPosition(randPos[id].x, randPos[id].y);
        hitbox.setPosition(rect.getPosition().x, rect.getPosition().y);
        hitbox.setScale(32, 1);
        break;
    
    case 2:
        rect.setSize(sf::Vector2f(61, 10));
        rect.setPosition(randPos[id].x, randPos[id].y);
        hitbox.setPosition(rect.getPosition().x, rect.getPosition().y);
        hitbox.setScale(32, 1);
        break;
    case 3:
        rect.setSize(sf::Vector2f(136, 10));
        rect.setPosition(randPos[id].x, randPos[id].y);
        hitbox.setPosition(rect.getPosition().x, rect.getPosition().y);
        hitbox.setScale(10, 1);
        break;
    case 4:
        rect.setSize(sf::Vector2f(210, 10));
        rect.setPosition(randPos[id].x, randPos[id].y);
        hitbox.setPosition(rect.getPosition().x, rect.getPosition().y);
        hitbox.setScale(32, 1);
        break;
    case 5:
        rect.setSize(sf::Vector2f(139, 10));
        rect.setPosition(randPos[id].x, randPos[id].y);
        hitbox.setPosition(rect.getPosition().x, rect.getPosition().y);
        hitbox.setScale(32, 1);
        break;
    case 6:
        rect.setSize(sf::Vector2f(248, 10));
        rect.setPosition(randPos[id].x, randPos[id].y);
        hitbox.setPosition(rect.getPosition().x, rect.getPosition().y);
        hitbox.setScale(32, 1);
        break;
    case 7:
        rect.setSize(sf::Vector2f(495, 10));
        rect.setPosition(randPos[id].x, randPos[id].y);
        hitbox.setPosition(rect.getPosition().x, rect.getPosition().y);
        hitbox.setScale(60, 1);
        break;
    case 8:
        rect.setSize(sf::Vector2f(183, 10));
        rect.setPosition(randPos[id].x, randPos[id].y);
        hitbox.setPosition(rect.getPosition().x, rect.getPosition().y);
        hitbox.setScale(32, 1);
        break;

    }
}
    
    
sf::FloatRect Platform::getBounds() const
{
    return hitbox.getGlobalBounds();
}
    


