#include <SFML/Graphics.hpp>
# include<iostream>
# include<cstdlib>

# include<time.h>
# include<stdlib.h>
#include "Classes.h"

using namespace std;


int main()
{
       // create the window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Sniper Monkey");
    window.setKeyRepeatEnabled(false);
    window.setMouseCursorVisible(false);
    float width = 1920, height = 1080;
    sf::View camera;
    sf::View hud;
    sf::Texture texture;
    sf::Sprite model;


    camera.setSize(width , height );
    camera.setCenter(width / 2, height / 2);
    camera.setViewport(sf::FloatRect(0, 0, 1, 1));
    camera.zoom(1);
    window.setFramerateLimit(60);
   
    sf::Event evento;
   
    srand(time(NULL));

    texture.loadFromFile("arma.png");
    model.setTexture(texture);
        
    LevelManager manager;
    manager.StartGame(window, camera, evento);
    while (window.isOpen()) {

        
        while (window.pollEvent(evento))
        {
           
           
            
                manager.UpdateImput(window, camera, evento);
            
            
           

        }

       

        

      
       manager.Update(window, camera);
        

        hud.setCenter(300, 300);
        hud.setViewport(sf::FloatRect(1, 1, 1, 1));
        hud.setSize(800, 600);
  
       

       
        window.setView(camera);
       
        manager.UpdateDraw(window);
     
        
        
        
      
        window.setView(hud);
        window.draw(model);
      
   
    
        window.display();
   
    
       

   
    }

   

    return 0;
}