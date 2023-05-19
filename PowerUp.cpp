#include "Classes.h"

PowerUp::PowerUp() :Entity()
{
	estado = MOVE;
}

void PowerUp::UpdateTarget(Sniper& s)
{


	switch (estado)
	{
	case PowerUp::IDLE:
		timetoDie--;
		std::cout << "restando vida   "<< std::endl;
		if (timetoDie < 0)
		{
			std::cout << "entro en die  " << timetoDie << std::endl;
			estado = PowerUp::DIE;
		}

		break;
	case PowerUp::MOVE:
		Move();
		break;
	case PowerUp::EXECUTE:
		Execute(s);

		break;
	case PowerUp::DIE:
		isDestroyed = true;


		break;
	


	default:
		break;
	}

}


void PowerUp::SpawnPUP	(sf::Texture& t,int num,int decision)
{


	hitbox.setScale(4, 2);

	if (decision == 1)
	{
		isVision = true;
	}
	else
	{
		isVision = false;
	}
	model.setTexture(t);
	ancho = model.getLocalBounds().width;
	int num1 = rand() % (rand() - num);
	if (num1 < ancho/10)
	{
		num1 = 190 + rand() % (900 - ancho/10);
	}else

		if (num1 > 1900)
		{
			num1= 900 + rand() % (1850-900);
	    }
	srand(time(NULL));
	model.setScale(0.5f, 0.5f);
	
	model.setPosition(num1, 0);

	hitbox.setPosition(model.getPosition().x+3, model.getPosition().y+7);
   

	
}
void PowerUp::ChangeState()
{
	if (checkIdle == 0)
	{
		estado = IDLE;
		checkIdle++;
}
		

		
}
void PowerUp::Execute(Sniper&sniper)
{
	if (isVision)
	{
		sniper.setVision(true);
		
	}
	else
	{
		if (sniper.getLife() > 65)
		{
			sniper.setLife(100);
		}
		else
		{
			sniper.setLife(sniper.getLife()+35);
		}
		std::cout << "ejecuto" << std::endl;
	}
	

	estado = DIE;



}
void PowerUp::Move()
{
	model.move(0, 1);
	hitbox.setPosition(model.getPosition().x+3, model.getPosition().y+7);
	//std::cout << "vive" << std::endl;

}
sf::FloatRect PowerUp::getBounds() const
{
	return hitbox.getGlobalBounds();
}

