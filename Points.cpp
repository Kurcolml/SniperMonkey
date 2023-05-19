#include "Classes.h"

Points::Points()
{
	fuentePuntos.loadFromFile("font2.ttf");

}






void Points::Update()
{
aux++;

if (aux >= segundos) {

points += 2;
aux = 0;
	}
}
void Points::draw(sf::RenderWindow& window)
{
	window.draw(textPuntos);
	
}
