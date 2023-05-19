#include "Classes.h"
# include<iostream>
Sniper::Sniper():Entity()
{
  
    
   
   



}
void Sniper::SetSniper()
{
    this->life = 100 ;
    setEstado(IDLE);
    skinZoom.loadFromFile("zoom.png");
    zoom.setTexture(skinZoom);
    setDead(false);
    setCount(0);
    setZoom(false);
   model.setColor(sf::Color::Black);
    skinpj.loadFromFile("spritespj.png");
    pj.setTexture(skinpj);
    pj.setPosition(875, 775);
    pj.setTextureRect({ 0,0,146,341 });
    pj.setOrigin(0, 0);
   

    bufferShooted.loadFromFile("audio/impacto2.wav");
    sonidoShooted.setBuffer(bufferShooted);

  
}
void Sniper::getPixelPos(sf::RenderWindow& w)
{
    
        pixelPos = sf::Mouse::getPosition();
       
        aux.x = pixelPos.x / 2;
        aux.y = pixelPos.y / 2;
        worldPos = w.mapPixelToCoords(pixelPos);
     
        
        currentPos.x = worldPos.x;
        currentPos.y = worldPos.y;
}

void Sniper::Move()
{
  
    model.setPosition(pixelPos.x - model.getLocalBounds().width / 2, pixelPos.y - model.getLocalBounds().height / 2);
        hitbox.setPosition(pixelPos.x - hitbox.getLocalBounds().width / 2, pixelPos.y - hitbox.getLocalBounds().height / 2);
        
}
void Sniper::ZoomMovement()
{
   
       zoom.setPosition(currentPos.x - zoom.getLocalBounds().width / 2, currentPos.y - zoom.getLocalBounds().height / 2);
        hitbox.setPosition(currentPos.x - hitbox.getLocalBounds().width / 2, currentPos.y - hitbox.getLocalBounds().height / 2);
   
        
   
}
void Sniper::Aim()
{
    

    if (getCount() == 0)
    {

        
        setZoom(true);
       
     
      



    }
    else if (getCount() == 1)
    {

        
      

       setZoom(false);
      
       model.setColor(sf::Color::Black);

    }


}
void Sniper::CheckCount() {

    if (!isZoom()) {

        setCount(0);
        //model.setColor(sf::Color::Transparent);
     ;


    }
    else if (isZoom()) {


        setCount(1);
        //model.setColor(sf::Color::Transparent);
        

    }
}
void Sniper::AddSprite(sf::Sprite target, const char nombre[10])
{
    sf::Texture s;
    s.loadFromFile(nombre);
    target.setTexture(s);
}
void Sniper::getDamage()
{
    if (getLife() > 0)
    {
    sonidoShooted.play();
    }
    setLife(getLife() - (10 + rand() % (18 - 10)));
   
    flawless = false;
   // life -= 0.05f;
   //std::cout << "recibi danio   "<<life << std::endl;
    //std::cout << life << std::endl;
   setEstado(HERIDO);
        if (getLife() <= 0)
    {

           
 
        setDead(true);
  
    }
}
sf::FloatRect Sniper::getBounds() const
{
   
    return hitbox.getGlobalBounds();
}

void Sniper::Shoot()
{
    setEstado(DISPARANDO);
    BufferTiro.loadFromFile("audio/tiro.wav");
    sonidoTiro.setBuffer(BufferTiro);

    sonidoTiro.setVolume(50);
    sonidoTiro.play();
}

void Sniper::Update()
{
    
    /*
    frame += 0.2;if (frame <= 4)
    {
        frame = 0;
    }
    pj.setTextureRect({ 0+=int(frame) * 120,0,120,319 });*/
    switch (getEstado())
    {
    case Sniper::IDLE:
        pj.setTextureRect({ 0,0,146,341 });
        break;
    case Sniper::HERIDO:
        frame += 0.3f;
        pj.setTextureRect({ 0+int(frame)*146,341,146,341 });
        if (frame >= 4)
        {
            frame = 0;
            setEstado(IDLE);
        }

        
        break;
    case Sniper::DISPARANDO:
         frame += 0.13f;
        pj.setTextureRect({0 + int(frame) * 146,0,146,341});
        if (frame >= 6)
        {
            frame = 0;
            setEstado(IDLE);
        }
        break;
    default:
        break;
    }
   
    if (!isZoom())
    {
        Move();

    }
    else

    {
        ZoomMovement();
    }
   
   
}
