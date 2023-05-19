#include "Classes.h"
# include<iostream>
HUD::HUD() : Entity()
{ 
	
	lifeSkin.loadFromFile("life.png");
	lifeBar.setTexture(lifeSkin);
	lifeBar.setOrigin(94, 94);
	lifeBar.setTextureRect({ 0,0,188,188 });
	lifeBar.setPosition(model.getPosition().x + 114, model.getPosition().y + 100);
	model.setTextureRect({ 0,0,176,185 });
	model.setOrigin(0, 0);
	
	fuentePuntos.loadFromFile("font2.ttf");
	fuenteTiempo.loadFromFile("font.ttf");

	textPuntos.setFont(fuentePuntos);
	textPuntos.setString("Points");
	textPuntos.setPosition(1550, 80);
	textPuntos.setFillColor(sf::Color::Black);
	textPuntos.setScale(1.5f, 1.5f);
	textViewPuntos.setFont(fuentePuntos);
	textViewPuntos.setPosition(1700, 80);
	textViewPuntos.setFillColor(sf::Color::Black);
	textViewPuntos.setScale(1.5f, 1.5f);
	//life = 100;

}

void HUD::Update()
{
	angulo = life * 1.8f;
	lifeBar.setRotation(angulo);
	
	if (life >35)
	{
		if (life > 70)
		{
			model.setTextureRect({ 0,0,176,185 });
			lifeBar.setTextureRect({ 0,0,188,188 });

		}
		else
		{
			model.setTextureRect({ 176,0,176,185 });
			lifeBar.setTextureRect({ 188,0,188,188 });
		}
		
		
		
	}else 
	
	{
		
		model.setTextureRect({ 352,0,176,185 });
		lifeBar.setTextureRect({ 376,0,188,188 });
	}

	



}

void HUD::setLife(Sniper& s)
{
	life = s.getLife();
	
	



/*
	textTiempo.setFont(fuenteTiempo);

	textTiempo.setString("Time");
	textTiempo.setFillColor(sf::Color::Black);

	textViewTiempo.setFont(fuenteTiempo);
	textViewTiempo.setPosition(400, 140);
	textViewTiempo.setFillColor(sf::Color::Black);
	textViewTiempo.setScale(1.5f, 1.5f);*/

}
