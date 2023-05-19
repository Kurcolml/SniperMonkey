#include "Classes.h"

Menu::Menu() :Entity()
{

}
void Menu::SetMenu(int cantidad)
{
	if (!font.loadFromFile("sniper.ttf")) {

		//error
	}
	int x = 0;
	this->numeroDeItems = cantidad;
	switch (cantidad)
	{
	case 5:
		for (int i = 0; i < numeroDeItems; i++)
		{
			sf::Text txt;
			txt.setFont(font);
			txt.setFillColor(sf::Color::Black);
			txt.setScale(1.5f, 1.5f);
			txt.setPosition(sf::Vector2f((1920 / 2) - 100, x + 150));
			txt.setOutlineColor(sf::Color::White);
			txt.setOutlineThickness(2.f);
			x += 100;
			texto.push_back(txt);
		}



		texto[0].setString("Play");
		texto[0].setFillColor(sf::Color::Red);
		texto[1].setString("Tutorial");
		texto[2].setString("Credits");
		texto[3].setString("HighScores");
		texto[4].setString("Exit");
		break;
	case 2:
		int c = 650;
		for (int i = 0; i < numeroDeItems; i++)
		{
			sf::Text txt;
			txt.setFont(font);
			txt.setFillColor(sf::Color::Black);
			txt.setScale(1.5f, 1.5f);
			txt.setOutlineColor(sf::Color::White);
			txt.setPosition(sf::Vector2f((1920 / 2) - 100, c + 150));
			c += 100;
			texto.push_back(txt);
		}



		texto[0].setString("Main Menu");
		texto[0].setFillColor(sf::Color::Red);
		texto[1].setString("Exit");
		texto[1].setPosition(sf::Vector2f((1920 / 2)-30, 750 + 150));
	
		break;
	}

	

	ItemSeleccionado = 0;
}


void Menu::MoveUp()
{
	if (ItemSeleccionado - 1 >= 0)
	{
		texto[ItemSeleccionado].setFillColor(sf::Color::Black);
		ItemSeleccionado--;
		texto[ItemSeleccionado].setFillColor(sf::Color::Red);
	}

}

void Menu::MoveDown()
{
	if (ItemSeleccionado + 1 < numeroDeItems)
	{
		texto[ItemSeleccionado].setFillColor(sf::Color::Black);
		ItemSeleccionado++;
		texto[ItemSeleccionado].setFillColor(sf::Color::Red);
	}
	
	

}
void Menu::Move(int direccion)
{
	for (int i = 0; i < numeroDeItems; i++) {
		texto[i].setFillColor(sf::Color::White);
	}
	ItemSeleccionado += direccion;
	
	
	

	

		

		

	
}

void Menu::drawMenu(sf::RenderWindow& window)
{
	for (int i = 0; i < numeroDeItems; i++) {
		window.draw(texto[i]);
	}

}

int Menu::getItem()
{
	return ItemSeleccionado;
}

