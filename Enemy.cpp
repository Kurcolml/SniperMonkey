#include "Classes.h"
# include<iostream>

Enemy::Enemy() :Entity()
{ 
	
	
	isCivil = false;
	timeToShoot = 300 + rand() % 720 - 300;
    
}

void Enemy::SetTarget(Sniper& t)
{
	this->target = t;
}

void Enemy::SpawnEnemy(sf::Texture &t,Node &n,int num,int pos)
{
	
    hitbox.setScale(3, 4);
	positionVec = n;
	nodo = pos;
	if (num == 0)
	{
		estado = Enemy::ESTADOS::IDLE;
		model.setScale(0.24f, 0.24f);
		if (nodo == 72 || nodo == 14 || nodo == 1 || nodo == 35)
		{
			model.setScale(0.30f, 0.30f);
		}
		else
		{
			model.setScale(0.24f, 0.24f);
		}
	}
	else

	{
		
		setCivilTrue();
		estado = Enemy::ESTADOS::CIVIL;
		if (nodo == 72 || nodo == 14 || nodo == 1 || nodo == 35)
		{
			model.setScale(0.15f, 0.15f);
		}
		else
		{
			model.setScale(0.1f, 0.1f);
		}

		
	}

	model.setTexture(t);


	

	//std::cout << "nace" << std::endl;
	
	model.setPosition(positionVec.getCoordinate().x, positionVec.getCoordinate().y);
	hitbox.setPosition(model.getPosition().x , model.getPosition().y );
		

	
}
void Enemy::setTimers(int S,int R)
{
	
}
void Enemy::Execute()
{
	std::cout << "esta muerto" << std::endl;
	isAlive = false;
	
	

	
}
void Enemy::Shoot(Sniper& s)
{
	s.getDamage();
	//std::cout << "disparo y la vida del personaje es " <<target.life<< std::endl;
	//std::cout << target.model.getPosition().x << std::endl;
	isShooting = false;
	timeToShoot = (5 + rand() % (11 - 5)) * 60;
	estado = IDLE;

	
	
}
void Enemy::StateMachine(Sniper& s)
{
	switch (estado)
	{
	case Enemy::IDLE:
		timeToShoot--;

		if (timeToShoot == 0)
		{
			isShooting = true;
		}
		if (isShooting)
		{
			estado = DISPARANDO;
		}
		break;
	case Enemy::DISPARANDO:
		Shoot(s);
		break;
	case Enemy::MUERTO:
		Execute();
		break;
	case Enemy::CIVIL:
		timetoDie--;
		if (timetoDie <= 0)
		{
			estado = MUERTO;
		}
		
		break;
	default:
		break;
	}
	
		
	

	
}
sf::FloatRect Enemy::getBounds() const
{
	return hitbox.getGlobalBounds();
}

void Enemy::UpdateTarget(Sniper& s)
{
	//std::cout << "vive" << std::endl;
	//std::cout << model.getPosition().x << std::endl;
	
	StateMachine(s);

}
void Enemy::Update()
{
	
}