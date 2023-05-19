

# include<iostream>



#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27
#include "Classes.h"
Textbox::Textbox()
{


}
void Textbox::SetBox(int size, sf::Color Color, bool sel)
{
	textbox.setCharacterSize(size);
	textbox.setFillColor(Color);
	textbox.setScale(2.0f, 2.0f);
	isSelected = sel;
	if (sel)
	{
		textbox.setString("_");
	}
	else
	{
		textbox.setString("");
	}
}



	void Textbox::setFont(sf::Font& font)
	{
		textbox.setFont(font);
	}

	void Textbox::setPosition(sf::Vector2f pos)
	{
		textbox.setPosition(pos);
	}

	void Textbox::setLimit(bool ToF)
	{
		hasLimit = ToF;
	}

	void Textbox::setLimit(bool ToF, int Limit)
	{
		hasLimit = ToF;
		limit = Limit - 1;
	}

	void Textbox::setSelected(bool sel)
	{
		isSelected = sel;

		if (!isSelected)
		{
			std::string T = text.str();
			std::string newT = "";

			for (int i = 0; i < T.length(); i++)
			{
				newT += T[i];
			}
			textbox.setString(newT);
		}
	}

	std::string Textbox::getText()
	{
		return text.str();
	}

	void Textbox::draw(sf::RenderWindow& window)
	{
		window.draw(textbox);
	}

	void Textbox::typedOn(sf::Event imput)
	{
		if (isSelected)
		{
			int charTyped = imput.text.unicode;
			if (charTyped < 128)
			{
				if (hasLimit)
				{
					if (text.str().length() <= limit)
					{
						imputlogic(charTyped);

					}
					else if (text.str().length() > limit && charTyped == DELETE_KEY)
					{
						deleteLastChar();
					}
				}
				else
				{
					imputlogic(charTyped);
				}
			}


		}

	}

	void Textbox::imputlogic(int charTyped)
	{

		if (charTyped != DELETE_KEY && charTyped != ESCAPE_KEY && charTyped != ENTER_KEY)
		{
			text << static_cast<char>(charTyped);
		}
		else if (charTyped == DELETE_KEY)
		{
			if (text.str().length() > 0)
			{
				deleteLastChar();
			}
		}
		textbox.setString(text.str() + "_");
	}

	void Textbox::deleteLastChar()
	{
		std::string T = text.str();
		std::string newT = "";

		for (int i = 0; i < T.length() - 1; i++)
		{
			newT += T[i];
		}
		text.str("");
		text << newT;
		textbox.setString(text.str());



	}
	void Textbox::deleteAllChars()
	{
		std::string T = text.str();
		

		
		text.str("");
		
		textbox.setString(text.str());



	}
