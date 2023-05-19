#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collisionable.h"
# include<iostream>
#include<stdlib.h>
#include <sstream>
#include <string>






class Entity: public sf::Drawable , public Collisionable
{
private:
	

public:
	Entity();
	
	
	sf::Sprite hitbox;
	
	sf::Sprite model;

	sf::Texture skin;
	sf::Texture skinB;
	
	
	
	void Spawn(const char nombre[10]);
	void Spawn(sf::Texture&t);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override ;
	sf::FloatRect getBounds() const override;
	void Execute();

	virtual void Update() {  };

	
	
	~Entity() {};

};
class Sniper: public Entity
{
private:
	
	int life = 0;
	int count = 0;
	int maxMove = 200;
	
	
	
	bool isZoomx2 = false, flawless = true, isVision = false;
	bool isDead = false;
	

	
public:
	sf::View camera;
	sf::Sound sonidoTiro;
	sf::Sprite zoom, pj;
	enum ESTADOS {
		IDLE,
		HERIDO,
		DISPARANDO


	};
	sf::Texture skinZoom, skinpj;
	sf::Sprite getModel() { return model; };
	ESTADOS estado;
	float width = 1920, height = 1080, frame = 0;
	int getLife() { return life; }
	void setLife(int c) { life= c; }
	int getCount() { return count; }
	void setCount(int d) { count=d ; }
	int getmaxMove() { return maxMove; }
	ESTADOS getEstado() { return estado; }
	sf::View getCamara() {
		return camera;
	}
	sf::Vector2i pixelPos, currentPos, aux;
	sf::Vector2f worldPos;
	void setEstado(ESTADOS e) {
		estado = e;
	}
	bool isZoom() { return isZoomx2; }
	void setZoom(bool d) { isZoomx2=d; }
	bool isFlaw() { return flawless; }
	void setFlaw(bool d) { flawless = d; }
	bool isVisionSniper() { return isVision; }
	void setVision(bool d) { isVision = d; }
	bool isDeadSniper() { return isDead; }
	void setDead(bool d) { isDead = d; }
	sf::Sprite getZoom() { return zoom; }
	sf::Sprite getPJ() { return pj; }


	Sniper();
	void SetSniper();
	
	void Shoot();

	sf::SoundBuffer bufferShooted;
	sf::Sound sonidoShooted;
	sf::SoundBuffer BufferTiro;


	void Update() override ;
	void Aim();
	void Move();
	void ZoomMovement();
	void CheckCount();
	void getPixelPos(sf::RenderWindow&);
	void AddSprite(sf::Sprite target, const char nombre[10]);
	void getDamage();
	sf::FloatRect getBounds() const override;
	
	
	~Sniper() {};
}; class HUD : public Entity
{
private:

	int life = 0, angulo = 0;
	int count = 0;
	

	


	float width = 1920, height = 1080;

public:
	sf::Text textPuntos, textViewPuntos, textTiempo, textViewTiempo;
	sf::Sprite lifeBar;
	sf::Texture lifeSkin;

	HUD();

	sf::Font fuentePuntos, fuenteTiempo;

	sf::Font getfuentePuntos() { return fuentePuntos; }
	sf::Sprite getlifeBar() { return lifeBar; }
	sf::Text gettextPuntos() { return textPuntos; }
	sf::Text gettextViewPuntos() { return textViewPuntos; }



	void Update() override;

	void setLife(Sniper& s);



};
class Node
{
private:
	sf::Vector2f _position;
	bool _taken = false;
public:
	Node();
	bool isTaken() { 
		if (_taken)
		{
			std::cout << "esta ocupado" << std::endl;
		}
		else
		{
			std::cout << "esta libre" << std::endl;
		}
		return _taken;
	};
	void setState(bool decision) { this->_taken = decision;
	std::cout << "esta libre" << std::endl;
	}

	void setCoordinate(int x, int y) { this->_position.x = x; this->_position.y = y; };
	sf::Vector2f getCoordinate() { return _position; };


}
;
class Enemy :public Entity
{
private:
	enum ESTADOS {
		IDLE,
		DISPARANDO,
		MUERTO,
		CIVIL
	

	};
public:
	Enemy()	;
	//sf::Sprite getModel() { return model; };
	ESTADOS estado;
	Sniper target;
	Node positionVec;
	int timeToShoot,nodo=0,timetoDie=420;
	bool isShooting = false, isAlive = true, isCivil = false;
	void SetTarget(Sniper& t);
	void SpawnEnemy(sf::Texture& t,Node &n,int num,int pos);
	void setTimers(int S, int R);
	
	bool wasCivil()
	{
		return isCivil;
	}
	void setCivilTrue()
	{
		isCivil = true;
	}
	void Shoot(Sniper& s);
	void StateMachine(Sniper& s);
	sf::FloatRect getBounds() const override;
	void Update()override;
	void UpdateTarget(Sniper& s);
	void Execute();

	~Enemy() {};

};
class Menu:public Entity

{
public:
	//sf::Sprite getModel() { return model; };
	Menu();
	void drawMenu(sf::RenderWindow& window);
	void SetMenu(int cantidad);
	void MoveUp();
	void MoveDown();
	void Move(int d);
	int getItem();
	int ItemSeleccionado,numeroDeItems;
	sf::Font font;
	std::vector<sf::Text> texto;

	~Menu() {};



private:
	
	
};
class PowerUp :public Entity
{ private:
	
public:
	enum ESTADOS {
		IDLE,
		MOVE,
		EXECUTE,
		DIE


	};
	//sf::Sprite getModel() { return model; };
	PowerUp();
	ESTADOS estado=IDLE;
	int ancho = 0, timetoDie=1200, checkIdle = 0;
	void Move();

	void UpdateTarget(Sniper& s);
	void ChangeState();
	void SpawnPUP(sf::Texture& t,int num,int d);
	bool isDestroyed = false, isVision = false;

	sf::FloatRect getBounds() const override;
	
	void Execute(Sniper& sniper);


};
class Platform : public Entity
{
private:


public:
	Platform();
	sf::RectangleShape rect;
	void SpawnPla( int id);
	sf::FloatRect getBounds() const override;
	sf::Sprite getModel() { return model; };

}
;
class Textbox
{

public :
	Textbox();
	void SetBox(int size, sf::Color Color, bool sel);
	void imputlogic(int charTyped);
	void setFont(sf::Font& font);
	void setPosition(sf::Vector2f pos);
	void setLimit(bool ToF);
	void setLimit(bool ToF, int Limit);
	void setSelected(bool sel);
	std::string getText();
	void draw(sf::RenderWindow& window);
	void typedOn(sf::Event imput);

	void deleteLastChar();
	void deleteAllChars();
	
private:
	sf::Text textbox;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;
	
	

};
class Points
{
private:

	int enemigo = 0, powerUp = 0, civil = 0, segundos = 60;	
public:
	int points = 0, aux = 0;
	Points();
	
	sf::Font fuentePuntos, fuenteTiempo;
	sf::Text textPuntos, textViewPuntos, textTiempo, textViewTiempo,textNombre;
	void AddPoints(int num) { points += num; };
	void RemovePoints(int num) { points =points- num; };
	void ResetPoints() { points = 0; };
	int GetPoints() { return points; };

	void Update();
	
	
	void draw(sf::RenderWindow& window);


};
class ArchivoPuntajes
{private:
	char nombre[30];
	int points;
public:
	ArchivoPuntajes()
	{
		
		points = (3000 + rand() % (7001 - 3000));

	}

	void cargarCadena() {
		int i;
		fflush(stdin);
		for (i = 0; i < 30; i++)
		{
			nombre[i] = std::cin.get();
			if (nombre[i] == '\n') break;
		}
		nombre[i] = '\0';
		fflush(stdin);
	}
	void CargarNombre(std::string n) { 
		strcpy(nombre, n.c_str()); 
	}
	std::string getNombre() {
		std::string aux = nombre;
		return aux;
	}
	void SetPoints(int num) { points = num; };
	std::string getPoints() { 
		std::string aux= std::to_string(points);
		return aux;
		 };
	int getPointsInt() {
		
		return points;
	};
	void Mostrar()
	{
		std::cout << "entro en mostrar" << std::endl;
		std::cout << points << " puntos del jugador " << nombre << std::endl;
	}



	bool grabarEnDiscoReferencia(ArchivoPuntajes puntaje) {
		FILE* p;
		p = fopen("highscore.dat", "ab");
		if (p == NULL) {
			return false;
		}
		fwrite(&puntaje, sizeof(ArchivoPuntajes), 1, p);
		fclose(p);
		return true;
	}
	bool grabarEnDisco() {
		FILE* p;
		p = fopen("highscore.dat", "ab");
		if (p == NULL) return false;
		bool escribio = fwrite(this, sizeof * this, 1, p);
		fclose(p);
		return escribio;
	}
	

	int leerDeDisco(int pos) {
		FILE* p;
		p = fopen("highscore.dat", "rb");
		if (p == NULL) return -1;
		fseek(p, sizeof(ArchivoPuntajes) * pos, 0);
		int leyo = fread(this, sizeof * this, 1, p);
		fclose(p);
		return leyo;
	}

	int contarRegistros() {
		FILE* p;
		p = fopen("highscore.dat", "rb");
		if (p == NULL) {
			return 0;
		}
		fseek(p, 0, SEEK_END);
		int cant = ftell(p) / sizeof(ArchivoPuntajes);
		fclose(p);
		return cant;
	}

};

class LevelManager
{
private:
	enum ESTADOS {
		NOMBRE,
		JUGANDO,
		PAUSA,
		DERROTA,
		VICTORIA,
		MAINMENU,
		ESPERAR,
		PUNTAJES
		

	};
public:
	LevelManager();
	ArchivoPuntajes registro;
	Entity mainMenu, background, tapa,tapaPowerUp, edificios,nombre,bgPowerUp,TOP10;
	void OrdenarMatriz();
	Sniper myHero;
	void EnemySpawner();
	void PUpSpawner();
	sf::Vector2i center;
	void AddEnemy(Enemy nuevo);
	void DeleteEnemy(int pos);
	void AddPUp(PowerUp nuevo);
	void DeletePUp(int pos);
	int timeToShoot = 5, timeToSpawn = 600, timeVision = 2640;
	int defaultTime = 180, timeToPower = 1200 ,seconds=60;
	Menu menu, menuDerrota;
	int contador = 0, contadorPower = 0, contadorEnemy = 0;
	
	sf::Sprite level;
	sf::Texture l_texture;
	sf::RenderWindow window;
	sf::View camera;
	sf::Text top10[10][2];

	int dondeEstoy = 0, kills = 0, civiles = 0, decision = 0, check = 0, mostrarRegistros = 0;
	int cantEnemys = 5, maxPUp = 10,maxNodes=0,pos=0,cantRegistros=0;
	bool jugar = false, damageColateral = false;
	Points puntos;
	Platform* platforms;
	Enemy* colisionables_e;
	PowerUp* colisionables_p;
	Node* SpawnPoints;
	Points* vec;
	HUD myHud;
	Enemy target;
	ESTADOS estado;
	
	void GenPlatforms();

	sf::SoundBuffer BufferHit, BufferGameOver, BufferVictory, bufferInfrared, bufferVision, bufferVida,bufferCivil;

	sf::Sound sonidoHit, sonidoGameOver, sonidoVictory, sonidioInfrared, sonidoVision, sonidoVida,sonidoCivil;
	//          0            1              2            3                  4            5
	sf::Sound* vecSonidos;
	bool noSound = false;

	bool isSoundVision = false;

	sf::Texture enemySkin,civilSkin;
	sf::Texture pUpSkin,infraUpSkin;
	sf::Texture plaSkin;
	sf::Font fuenteTop;
	void setPositions();
	void StartGame(sf::RenderWindow& w, sf::View& c, sf::Event& e);
	void UpdateDraw(sf::RenderWindow& w);
	void UpdateImput(sf::RenderWindow& w, sf::View& c, sf::Event& e);
	void Update(sf::RenderWindow& w, sf::View& c);

	sf::Text textNombre,textVictoriaNombre,flawVictory,colateral;
	

	sf::Texture textureNombreCase;
	
	sf::Sprite spriteNombreCase;
	

	Textbox textbox1;
	void mostrarRegistrosPuntos();
	void Pintar(int d);




	void OrdenarVector(int cantidad, ArchivoPuntajes* vec)
	{
		int i, j, temp;
		std::string nameTemp;
		for (i = 0; i < cantidad - 1; i++)
		{
			for (j = 0; j < cantidad - 1; j++)
			{
				if (vec[j].getPointsInt() < vec[j + 1].getPointsInt())
				{
					temp = vec[j].getPointsInt();
					nameTemp = vec[j].getNombre();

					vec[j].SetPoints(vec[j + 1].getPointsInt());
					vec[j].CargarNombre(vec[j + 1].getNombre());

					vec[j + 1].SetPoints(temp);
					vec[j+1].CargarNombre(nameTemp);


				}

			}
		}

	}
	~LevelManager();

};


