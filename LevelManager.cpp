#include "Classes.h"
# include<iostream>
LevelManager::LevelManager()
{

    myHero.Spawn("crosshair.png");
    edificios.Spawn("edificiospj.png");
    bgPowerUp.Spawn("bgPowerUp.jpg");
    tapaPowerUp.Spawn("tapaPowerUp.png");
    TOP10.Spawn("top10.jpg");
    cantEnemys = 74;
    maxNodes = 74;
    colisionables_e = new Enemy[cantEnemys];
    colisionables_p = new PowerUp[maxPUp];
    //vecSonidos = new sf::Sound[6];
   
   
    SpawnPoints = new Node[74];
 
    //myHero.SetSniper();
    
    
    contadorPower = 0;
    contadorEnemy = 0;
   
    center.x = 1920 / 2;
    center.y = 1080 / 2;
    setPositions();
    fuenteTop.loadFromFile("fontTop.ttf");

    
    estado = MAINMENU;

    mostrarRegistros = 0;
    
    timeToSpawn = 180;/*
    for (int i = 0; i < 10; i++)
    {
        ArchivoPuntajes ap;
        ap.cargarCadena();
        ap.grabarEnDisco();
    }*/

    /*bufferMenu.loadFromFile("audio/mainmenu.wav");
    sonidoMenu.setBuffer(bufferMenu);
    sonidoMenu.setVolume(20);*/


}

void LevelManager::mostrarRegistrosPuntos()
{
    if (mostrarRegistros == 0)
    {
        //int pos1 = 0;
        ArchivoPuntajes ap;
       
        int cantidad = registro.contarRegistros();
        ArchivoPuntajes* vecRegistos = new ArchivoPuntajes[cantidad];
        for (int i = 0; i < cantidad; i++)
        {
            vecRegistos[i].leerDeDisco(i);
        }
        OrdenarVector(cantidad, vecRegistos);



        for (int i = 0; i < 10; i++)
        {
            
            top10[i][0].setFont(fuenteTop);
            top10[i][0].setFillColor(sf::Color::White);
            top10[i][1].setFont(fuenteTop);
            top10[i][1].setFillColor(sf::Color::White);
            top10[i][0].setScale(2.8f, 2.8f);
            top10[i][1].setScale(2.8f, 2.8f);
            top10[i][0].setString(vecRegistos[i].getNombre());
            top10[i][1].setString(vecRegistos[i].getPoints());
            top10[i][0].setPosition(500, 120+(i*95));
            top10[i][1].setPosition(1500, 120 + (i * 95));
            std::cout << cantidad << std::endl;
            ap.Mostrar();


        }

       

        delete[]vecRegistos;
        mostrarRegistros = 1;
    }
}

void LevelManager::GenPlatforms()
{
    for (int i = 0; i < 9; i++)
    {

            Platform pla;
            pla.SpawnPla(i);
            platforms[i]=pla;

           

        
    }




}
void LevelManager::AddEnemy(Enemy nuevo)
{
    Enemy* aux = new Enemy[contadorEnemy + 1];
    for (int i = 0; i < contadorEnemy; i++)
    {
        aux[i] = colisionables_e[i];
    }
    aux[contadorEnemy] = nuevo;

   
    delete[]colisionables_e;
    
    colisionables_e = aux;
    contadorEnemy++;

}

void LevelManager::AddPUp(PowerUp nuevo)
{
    PowerUp* aux = new PowerUp[contadorPower + 1];
    for (int i = 0; i < contadorPower; i++)
    {
        aux[i] = colisionables_p[i];
    }
    aux[contadorPower] = nuevo;


    delete[]colisionables_p;

    colisionables_p = aux;
    contadorPower++;

}
void LevelManager::setPositions()
{
    for (int i = 0; i < maxNodes; i++)
    {
        switch (i)
        {
        case 0:SpawnPoints[i].setCoordinate(96, 645); //piedra 
            break;
        case 1:
            SpawnPoints[i].setCoordinate(181, 798);
            break;
        case 2:
            SpawnPoints[i].setCoordinate(230, 564);
            break;
        case 3:
            SpawnPoints[i].setCoordinate(329, 609);
            break;
        case 4:SpawnPoints[i].setCoordinate(263, 565);
            break;
        case 5:SpawnPoints[i].setCoordinate(261, 605);
            break;
        case 6:SpawnPoints[i].setCoordinate(297, 570);
            break;
        case 7:SpawnPoints[i].setCoordinate(297, 616);
            break;
        case 8:SpawnPoints[i].setCoordinate(227, 617);
            break;
        case 9:SpawnPoints[i].setCoordinate(330, 566);
            break;
        case 10:SpawnPoints[i].setCoordinate(1051, 677);
            break;
        case 11:SpawnPoints[i].setCoordinate(212, 674);
            break;
        case 12:SpawnPoints[i].setCoordinate(260, 677);
            break;
        case 13:SpawnPoints[i].setCoordinate(335, 672);
            break;
        case 14:SpawnPoints[i].setCoordinate(373, 792);
            break;

        case 15:SpawnPoints[i].setCoordinate(501, 626);
            break;
        case 16:SpawnPoints[i].setCoordinate(502, 677);
            break;
        case 17:SpawnPoints[i].setCoordinate(534, 627);
            break;
        case 18:SpawnPoints[i].setCoordinate(534, 677);
            break;
        case 19:SpawnPoints[i].setCoordinate(568, 629);
            break;
        case 20:SpawnPoints[i].setCoordinate(566, 674);
            break;
        case 21:SpawnPoints[i].setCoordinate(600, 628);
            break;
        case 22:SpawnPoints[i].setCoordinate(605, 674);
            break;
        case 23:SpawnPoints[i].setCoordinate(660, 641);
            break;
        case 24:SpawnPoints[i].setCoordinate(749, 670);
            break;

        case 25:SpawnPoints[i].setCoordinate(773, 675);
            break;
        case 26:SpawnPoints[i].setCoordinate(799, 670);
            break;
        case 27:SpawnPoints[i].setCoordinate(854, 673);
            break;
        case 28:SpawnPoints[i].setCoordinate(853, 622);
            break;
        case 29:SpawnPoints[i].setCoordinate(855, 519);
            break;
        case 30:SpawnPoints[i].setCoordinate(889, 517);
            break;
        case 31:SpawnPoints[i].setCoordinate(890, 571);
            break;
        case 32:SpawnPoints[i].setCoordinate(886, 622);
            break;
        case 33:SpawnPoints[i].setCoordinate(889, 672);
            break;
        case 34:SpawnPoints[i].setCoordinate(923, 516);
            break;
        case 35:SpawnPoints[i].setCoordinate(168, 450);   ///palo de luz
            break;
        case 36:SpawnPoints[i].setCoordinate(923, 621);
            break;
        case 37:SpawnPoints[i].setCoordinate(924, 672);
            break;
        case 38:SpawnPoints[i].setCoordinate(968, 517);
            break;
        case 39:SpawnPoints[i].setCoordinate(960, 622);
            break;

        case 40:SpawnPoints[i].setCoordinate(1094, 677);
            break;
        case 41:SpawnPoints[i].setCoordinate(1059, 591);
            break;
        case 42:SpawnPoints[i].setCoordinate(1124, 591);
            break;
        case 43:SpawnPoints[i].setCoordinate(1016, 591);
            break;
        case 44:SpawnPoints[i].setCoordinate(1123, 519);
            break;
        case 45:SpawnPoints[i].setCoordinate(1037, 515);
            break;
        case 46:SpawnPoints[i].setCoordinate(984, 438);
            break;
        case 47:SpawnPoints[i].setCoordinate(1016, 438);
            break;
        case 48:SpawnPoints[i].setCoordinate(1711, 455);
            break;
        case 49:SpawnPoints[i].setCoordinate(1101, 441);
            break;
        case 50:SpawnPoints[i].setCoordinate(1148, 440);
            break;
        case 51:SpawnPoints[i].setCoordinate(1122, 358);
            break;
        case 52:SpawnPoints[i].setCoordinate(1080, 358);
            break;
        case 53:SpawnPoints[i].setCoordinate(1033, 359);
            break;
        case 54:SpawnPoints[i].setCoordinate(1011, 278);
            break;
        case 55:SpawnPoints[i].setCoordinate(1048, 276);
            break;
        case 56:SpawnPoints[i].setCoordinate(1119, 277);
            break;
        case 57:SpawnPoints[i].setCoordinate(1195, 277);
            break;

        case 58:SpawnPoints[i].setCoordinate(1209, 657);
            break;
        case 59:SpawnPoints[i].setCoordinate(1268, 662);
            break;
        case 60:SpawnPoints[i].setCoordinate(1328, 662);
            break;
        case 61:SpawnPoints[i].setCoordinate(1352, 662);
            break;
        case 62:SpawnPoints[i].setCoordinate(1295, 604);
            break;
        case 63:SpawnPoints[i].setCoordinate(1409, 604);
            break;
        case 64:SpawnPoints[i].setCoordinate(1392, 656);
            break;
        case 65:SpawnPoints[i].setCoordinate(1442, 659);
            break;
        case 66:SpawnPoints[i].setCoordinate(1528, 659);
            break;
        case 67:SpawnPoints[i].setCoordinate(1568, 661);
            break;
        case 68:SpawnPoints[i].setCoordinate(1584, 610);
            break;
        case 69:SpawnPoints[i].setCoordinate(1627, 661);
            break;
        case 70:SpawnPoints[i].setCoordinate(1653, 659);
            break;
        case 71:SpawnPoints[i].setCoordinate(1711, 661);
            break;
        case 72:SpawnPoints[i].setCoordinate(1189, 799);
            break;
        case 73:SpawnPoints[i].setCoordinate(1343, 792);
            break;

        }
    }
    

}
void LevelManager::DeleteEnemy(int pos)
{
    Enemy* aux = new Enemy[contadorEnemy - 1];
    for (int i = 0; i < pos; i++)
    {
        aux[i] = colisionables_e[i];
    }
    for (int i = pos; i < contadorEnemy -1; i++)
    {
        aux[i] = colisionables_e[i+1];
    }
    delete[]colisionables_e;
    colisionables_e = aux;
    contadorEnemy--;
    




}
void LevelManager::Pintar(int  decision)
{
    if (decision)
    {
        for (int i = 0; i < contadorEnemy; i++)
        {
            colisionables_e[i].model.setColor(sf::Color::Red);
        }
        for (int i = 0; i < contadorPower; i++)
        {
            colisionables_p[i].model.setColor(sf::Color(32,144,145));
        }
        if (!isSoundVision)
        {
        sonidioInfrared.play();
        isSoundVision = true;
        }
    }
    else

    {
        for (int i = 0; i < contadorEnemy; i++)
        {
            colisionables_e[i].model.setColor(sf::Color::White);
        }
        for (int i = 0; i < contadorPower; i++)
        {
            colisionables_p[i].model.setColor(sf::Color::White);
        }
        isSoundVision = false;
    }
    
}
void LevelManager::DeletePUp(int pos)
{
    PowerUp* aux = new PowerUp[contadorPower - 1];
    for (int i = 0; i < pos; i++)
    {
        aux[i] = colisionables_p[i];
    }
    for (int i = pos; i < contadorPower - 1; i++)
    {
        aux[i] = colisionables_p[i + 1];
    }
    delete[]colisionables_p;
    colisionables_p = aux;
    contadorPower--;





}

void LevelManager::EnemySpawner()
{
    if (contadorEnemy < cantEnemys)
    {
        timeToSpawn--;
        //std::cout << timeToSpawn << std::endl;

        if (timeToSpawn <= 0)
        {

            Enemy e ;
           
            int num = rand() % 73;
            if(SpawnPoints[num].isTaken()==true)
            {
               
                std::cout << num<< std::endl;
               
                
            }
            else
            {
                if (kills > 3)
                {
                    int selector = rand() % 100;
                    if (selector < 30)
                    {
                        e.SpawnEnemy(civilSkin, SpawnPoints[num], 1,num);
                        SpawnPoints[num].setState(true);
                        AddEnemy(e);
                    }
                    else
                    {
                        e.SpawnEnemy(enemySkin, SpawnPoints[num], 0, num);
                        SpawnPoints[num].setState(true);
                        AddEnemy(e);
                    }
                   
                }
                else
                {
                    e.SpawnEnemy(enemySkin, SpawnPoints[num], 0, num);
                    SpawnPoints[num].setState(true);
                    AddEnemy(e);
                }
                
                //timeToSpawn += 60;
                
            }
            timeToSpawn += (5+rand() % (13 - 5)) * seconds;
            
        }
    }
   
    


}
void LevelManager::PUpSpawner()
{
    if (contadorPower < maxPUp)
    {

        timeToPower--;
       // std::cout << timeToPower << std::endl;

        if (timeToPower == 0)
        {


            PowerUp p;
          
            int num = rand() % 100;
            if (num < 20&& myHero.isVisionSniper() == false)
            {
                p.SpawnPUP(infraUpSkin, rand(),1 );
               
            }
            else
            {
                p.SpawnPUP(pUpSkin, rand(), 0);
            }
           

            AddPUp(p);
            timeToPower += (20 + rand() % (41 - 20)) * seconds;
            //timeToPower = 60;
        }
   }
    


}
void  LevelManager::StartGame(sf::RenderWindow& window, sf::View& camera, sf::Event& evento)
{
     
       
        menu.SetMenu(5);
        menuDerrota.SetMenu(2);
        /**********************////////////////////INSTANCIA DE TEXTURAS///////////////////////////////////******
        enemySkin.loadFromFile("enemy.png");
        civilSkin.loadFromFile("civil.png");
        pUpSkin.loadFromFile("botiquin.png");
        plaSkin.loadFromFile("platform.png");
        infraUpSkin.loadFromFile("infrarojo.png");


        
        BufferHit.loadFromFile("audio/impacto1.wav");
        sonidoHit.setBuffer(BufferHit);

        bufferCivil.loadFromFile("audio/tiroHit.wav");
        sonidoCivil.setBuffer(bufferCivil);

        BufferGameOver.loadFromFile("audio/gameOver.wav");
        sonidoGameOver.setBuffer(BufferGameOver);
        BufferVictory.loadFromFile("audio/victoria.wav");
        sonidoVictory.setBuffer(BufferVictory);
        
        bufferInfrared.loadFromFile("audio/infrarojo.wav");
        sonidioInfrared.setBuffer(bufferInfrared);

        bufferVision.loadFromFile("audio/vision.wav");
        sonidoVision.setBuffer(bufferVision);
        bufferVida.loadFromFile("audio/vida1.wav");
        sonidoVida.setBuffer(bufferVida);
        sonidoVida.setVolume(20);

       
/*
        bufferJugando.loadFromFile("audio/jugando.wav");
        sonidoJugando.setBuffer(bufferJugando);
        sonidoJugando.setVolume(20);*/



        /*sf::Sprite background;
        sf::Texture print_b;
        print_b.loadFromFile("background.jpg");
        background.setTexture(print_b);
        */
        
        //background.Spawn("background.jpg");
        mainMenu.Spawn("fondo.jpg");
        background.Spawn("background3.jpg");
        background.model.setPosition(-515, -323);
        bgPowerUp.model.setPosition(-515, -323);
        tapa.Spawn("tapa.png");
        tapa.model.setPosition(-515, -323);
        tapaPowerUp.model.setPosition(-515, -323);
        nombre.Spawn("nombre.jpg");
        /* sf::Sprite crosshair;

         */

       
       

       
        
       

        
        //tapa.Spawn("fondotrucho.png");

       


   
        
         
        myHud.Spawn("hud.png");
        
       
      

        textVictoriaNombre.setFont(myHud.fuentePuntos);
        textVictoriaNombre.setPosition(500,500);

        textNombre.setPosition(1920 / 2 - 100, 1080 / 2 + 100);
        textNombre.setFillColor(sf::Color::White);
        flawVictory.setString("FLAWLESS");
        flawVictory.setFont(fuenteTop);
        flawVictory.setPosition(1000, 300);
        flawVictory.setScale(2, 2);
        flawVictory.setFillColor(sf::Color::Red);
        colateral.setString("COLLATERAL");
        colateral.setFont(fuenteTop);
        colateral.setPosition(1000, 400);
        colateral.setScale(2, 2);
        colateral.setFillColor(sf::Color::Red);
        Entity spriteNombreCase;
        spriteNombreCase.Spawn("rectangle1.png");
        spriteNombreCase.model.setPosition(1920 / 2 - 200, 1080 / 2 + 160);

       
           
            //window.setMouseCursorVisible(false);
       

           

           

            




         



            //window.setView(camera);
        cantRegistros = registro.contarRegistros();
        pos = 0;
       
        /*cantRegistros = puntos.contarRegistros();
        vec = new Points[cantRegistros];
       */
}
            
            
       


LevelManager::~LevelManager() {

    std::cout << "eliminado" << std::endl;
    

}                                       ///////////////////////////////////////////ACTUALIZANDO ESTADOS
void LevelManager::Update(sf::RenderWindow& window, sf::View& camera)
{ 

    window.setView(camera);
    switch (estado)
    {
    case LevelManager::NOMBRE:
        textbox1.setSelected(true);
        break;
    case LevelManager::JUGANDO:
     
        myHud.Update();
        puntos.Update();
        for (int j = 0; j < contadorPower; j++)
        {
            for (int c = 0; c < 9; c++)
            {

                if (colisionables_p[j].isCollision(platforms[c]))
                {
                    if (colisionables_p[j].estado != PowerUp::IDLE)
                    {
                        colisionables_p[j].ChangeState();
                    }
                   
                   

                }

                //std::cout << "disparo y mato" << std::endl;

            }
        }
            myHero.getPixelPos(window);
            myHero.Update();
            //background.Update();
       /**********************////////////////////GENERADOR DE ENEMIGOS Y POWERUPS///////////////////////////////////******
           
            EnemySpawner();
            PUpSpawner();
           
            Pintar(myHero.isVisionSniper());
           

            /**********************////////////////////UPDATE DE ENEMIGOS Y POWERUPS///////////////////////////////////******
            target.model.setPosition(myHero.worldPos.x, myHero.worldPos.y);
            myHud.setLife(myHero);


            for (int x = 0; x < contadorEnemy; x++)
            {

                colisionables_e[x].UpdateTarget(myHero);
                if (colisionables_e[x].isAlive == false)
                {
                    DeleteEnemy(x);
                   
                }
                // std::cout << "vive" << std::endl;

            }
            for (int i = 0; i < contadorPower; i++)
            {

                colisionables_p[i].UpdateTarget(myHero);
                if (colisionables_p[i].isDestroyed)
                {
                    if (myHero.isVisionSniper())
                    {
                      // sonidoVision.play();
                    }
                    else
                    {
                        //sonidoVida.play();
                    }
                    DeletePUp(i);
                }
                // std::cout << "vive" << std::endl;

            }

            /**********************////////////////////CONDICION DERROTA///////////////////////////////////******
            if (myHero.isDeadSniper() == true)
            {
                sonidoGameOver.play();
                camera.setSize(1920, 1080);
                camera.setCenter(1920 / 2, 1080 / 2);

                jugar = false;
                dondeEstoy = 0;
                l_texture.loadFromFile("gameover.jpg");

                level.setTexture(l_texture);

                std::cout << "fin del juego" << "\n";
                level.setPosition(0, 0);
                registro.SetPoints(puntos.GetPoints());
                registro.grabarEnDisco();
                //sonidoJugando.pause();
                estado = DERROTA;
                //std::cout << "esta muerto" << std::endl;

            }
            /**********************////////////////////CONDICION VICTORIA///////////////////////////////////******
            if (kills >= 15 )
            {
                if (myHero.isFlaw())
                {
                    puntos.AddPoints(2000);
                }
                if (damageColateral == false)
                {
                    puntos.AddPoints(750);
                }
                puntos.AddPoints(1000);
                sonidoVictory.play();
                l_texture.loadFromFile("victoria.jpg");

                level.setTexture(l_texture);
                registro.SetPoints(puntos.GetPoints());
                registro.grabarEnDisco();
                //sonidoJugando.pause();
                estado = VICTORIA;

            }
        
            if (myHero.isVisionSniper())
            {
                timeVision--;
                if (timeVision < 0)
                {
                    myHero.setVision(false);
                    timeVision = 2640;
                }
            }
       
        
       

        break;
    case LevelManager::PAUSA:

      
        std::cout << estado << "\n";
        break;
    case LevelManager::DERROTA:
        std::cout << estado << "\n";
        
        break;
    case LevelManager::VICTORIA:
        break;
    case LevelManager::MAINMENU:
        //mostrarRegistros = 0;
        //std::cout << estado << "\n";
        
        break;
    case PUNTAJES:
        mostrarRegistrosPuntos();
       /* while (puntos.leerDeDisco(pos++))
        {
            puntos.Mostrar();
        }*/
        //puntos.leerDeDisco(0);
        
       

        break;
    }
    
}                                         ////////////////////////////////////////DIBUJOS////////////////////////////////////
void LevelManager::UpdateDraw(sf::RenderWindow& window)
{
    switch (estado)
    {
    case MAINMENU:
        window.draw(mainMenu);
        if (dondeEstoy == 0)
        {
            
            menu.drawMenu(window);
       }
      

        break;

    case NOMBRE:
        window.draw(nombre);
        window.draw(spriteNombreCase);
        window.draw(textNombre);
        textbox1.draw(window);
     

        break;
    
    case JUGANDO:

      
        if (myHero.isVisionSniper())
        {
            window.draw(bgPowerUp);
        }
        else
        {
            window.draw(background);
        }
       
        for (int i = 0; i < contadorEnemy; i++)
        {
          
            window.draw(colisionables_e[i]);
            window.draw(colisionables_e[i].hitbox);

        }
        for (int i = 0; i < 9; i++)
        {

            window.draw(platforms[i].rect);
            window.draw(platforms[i].hitbox);

        }
        for (int x = 0; x < contadorPower; x++)
        {

            window.draw(colisionables_p[x]);
            window.draw(colisionables_p[x].hitbox);

        }
       
        if (myHero.isVisionSniper())
        {
            window.draw(tapaPowerUp);
        }
        else
        {
            window.draw(tapa);
        }
      
       
       
        if (!myHero.isZoom())
        {
          

            window.draw(myHero);
            
            window.draw(edificios);
            window.draw(myHero.pj);

        }
            window.draw(myHero.hitbox);
        if (myHero.isZoom())
        {
            window.draw(myHero.zoom);
        }
        window.draw(myHud.lifeBar);
        window.draw(myHud);
       
        

        window.draw(myHud.gettextPuntos());
        myHud.textViewPuntos.setString(std::to_string(puntos.GetPoints()));
        window.draw(myHud.textViewPuntos);
       
       
        
        break;
    case DERROTA:
      
       
        window.draw(level);
        menuDerrota.drawMenu(window);
        myHud.textPuntos.setPosition(1300, 250);
        myHud.textPuntos.setFont(fuenteTop);

        myHud.textPuntos.setFillColor(sf::Color::White);
        myHud.textPuntos.setScale(3, 3);




        window.draw(myHud.textPuntos);


        myHud.textViewPuntos.setString(std::to_string(puntos.GetPoints()));

        myHud.textViewPuntos.setPosition(1500, 250);
        myHud.textViewPuntos.setFillColor(sf::Color::White);

        myHud.textViewPuntos.setFont(fuenteTop);
        myHud.textViewPuntos.setScale(3, 3);
        window.draw(myHud.textViewPuntos);
        textVictoriaNombre.setString(registro.getNombre());
        textVictoriaNombre.setScale(2, 2);
        textVictoriaNombre.setFillColor(sf::Color::White);
        textVictoriaNombre.setPosition(1150, 140);
        textVictoriaNombre.setFont(fuenteTop);
        window.draw(textVictoriaNombre);
        
        
        break;
    
      case ESPERAR:
          window.draw(level);
          
          break;
      case VICTORIA:
         

          window.draw(level);
          menuDerrota.drawMenu(window);

          myHud.textPuntos.setPosition(600, 250);
          myHud.textPuntos.setFont(fuenteTop);

          myHud.textPuntos.setFillColor(sf::Color::White);
          myHud.textPuntos.setScale(1.5f, 1.5f);

          
         
        
          window.draw(myHud.textPuntos);
         
       
          myHud.textViewPuntos.setString(std::to_string(puntos.GetPoints()));

          myHud.textViewPuntos.setPosition(800, 250);
          myHud.textViewPuntos.setFillColor(sf::Color::White);

          myHud.textViewPuntos.setFont(fuenteTop);
          window.draw(myHud.textViewPuntos);
          textVictoriaNombre.setString(registro.getNombre());
          textVictoriaNombre.setScale(2, 2);
          textVictoriaNombre.setFillColor(sf::Color::White);
          textVictoriaNombre.setPosition(500, 140);
          textVictoriaNombre.setFont(fuenteTop);
          window.draw(textVictoriaNombre);
      
          if (myHero.isFlaw())
          {
              flawVictory.setFillColor(sf::Color::Yellow);
          }
          else
          {
              flawVictory.setFillColor(sf::Color::Red);
          }
          if (damageColateral)
          {
              colateral.setFillColor(sf::Color::Red);
          }
          else
          {
              colateral.setFillColor(sf::Color::Yellow);
          }
          window.draw(flawVictory);
          window.draw(colateral);
          break;
      case PUNTAJES:
          
          window.draw(TOP10);
          for (int i = 0; i < 10; i++)
          {

              window.draw(top10[i][0]);
              window.draw(top10[i][1]);

          }
          

          break;
}
     
}
                                 /********************************////////// IMPUTS 
void LevelManager::UpdateImput(sf::RenderWindow& window, sf::View& camera, sf::Event& evento)
{
    switch (estado)
    {
    case PUNTAJES:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            mainMenu.model.setOrigin(0, 0);
            dondeEstoy--;

            
            mostrarRegistros = 0;

            estado = MAINMENU;
        }
            


        break;
    case NOMBRE:
       
        if (evento.type == sf::Event::KeyReleased)
        {
            if (evento.key.code == sf::Keyboard::Enter)
            {
                contador = 0;
                std::cout << "apreta enter°°°" << "\n";

            }

        }
        // ESTO PARA QUE DETECTE LA LETRA QUE ESCRIBE 
        if (evento.type == sf::Event::TextEntered)
        {
            textbox1.typedOn(evento);
            
        }
        //HASTA ACA 
        if (contador == 0) {


            if (evento.type == sf::Event::KeyPressed)
            {

                if (evento.key.code == sf::Keyboard::Enter)
                {
                    registro.CargarNombre(textbox1.getText());
                   
                    estado = JUGANDO;


                }

            }


        }

        break;
    case MAINMENU:
     
        if (evento.type == sf::Event::KeyReleased)
        {
            if (evento.key.code == sf::Keyboard::Enter)
            {
                contador = 0;
                std::cout << "apreta enter°°°" << "\n";

            }
        }

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();*/


        else if (evento.key.code == sf::Keyboard::Escape && dondeEstoy != 0)
        {
            mainMenu.model.setOrigin(0, 0);
            dondeEstoy--;
        }if (jugar == false && contador==0) {
            if (evento.type == sf::Event::KeyPressed)
            {


                if (evento.key.code == sf::Keyboard::Up)
                {
                    menu.MoveUp();

                }
                if (evento.key.code == sf::Keyboard::Down)
                {
                    menu.MoveDown();

                }

                if (evento.key.code == sf::Keyboard::Enter)
                {
                    switch (menu.getItem()) {

                    case 0:
                        /*sonidoMenu.pause();
                        sonidoJugando.play();*/
                        std::cout << "COMENZAR EL JUEGO" << "\n";
                        background.model.setOrigin(0 , 0);
                        bgPowerUp.model.setOrigin(0, 0);
                        
                        jugar = 1;

                        colisionables_e = new Enemy[cantEnemys];
                        colisionables_p = new PowerUp[maxPUp];
                        platforms = new Platform[9];
                        myHud.model.setScale(1, 1);
                        myHud.model.setPosition(10, 20);
                        myHud.lifeBar.setPosition(myHud.model.getPosition().x + 107, myHud.model.getPosition().y + 81);
                        myHud.lifeBar.setScale(1, 1);
                        GenPlatforms();
                
                        textbox1.SetBox(29, sf::Color::White, false);
                        textbox1.setFont(fuenteTop);
                        textbox1.setPosition({470, 400 });
                        textbox1.setLimit(true, 20);
                        
                        myHero.SetSniper();
                       

                        estado = NOMBRE;

                        break;
                    case 1:
                        mainMenu.model.setOrigin(window.getSize().x * 1, 0);
                        dondeEstoy++;
                        break;
                    case 2:
                        mainMenu.model.setOrigin(window.getSize().x * 2, 0);
                        dondeEstoy++;
                        break;
                    case 3:
                        
                        dondeEstoy++;
                        
                       
                     
                        estado = PUNTAJES;
                        break;
                        
                    case 4:
                        window.close();
                        break;
                    }


                }
               

            }
           
        }
       
  


        case JUGANDO:          ////////////////////////////////////COLISIONES////////////////////////////////
           
           /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                //window.close();*/
         if ( evento.type == sf::Event::MouseButtonReleased && evento.mouseButton.button == sf::Mouse::Left)  //if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
         {
             if (myHero.estado != Sniper::DISPARANDO)
             {
                    myHero.Shoot();
                    std::cout << " mouse en x " << sf::Mouse::getPosition().x << " mouse en y " << sf::Mouse::getPosition().y << std::endl;
                

                    noSound = false;
                for (int i = 0; i < contadorEnemy; i++)
                {
                    if (myHero.isCollision(colisionables_e[i]))
                    { 
                        noSound = true;
                        if (check == 0)
                        {
                            colisionables_e[i].Execute();
                            SpawnPoints[colisionables_e[i].nodo].setState(false);
                            std::cout << "mataste en la ubicacion "<<colisionables_e[i].nodo << std::endl;
                            sonidoHit.play();
                            if (colisionables_e[i].wasCivil()==true)
                            {
                                civiles++;
                                puntos.RemovePoints(civiles*200);
                                sonidoCivil.play();
                            }
                            else {
                                kills++;
                                puntos.AddPoints(150);
                            }
                            DeleteEnemy(i);
                            check=1;
                            
                        }                        
                        
                        //std::cout << "disparo y mato" << std::endl; 
                        
                    }

                }
               
               
                for (int j = 0; j < contadorPower; j++)
                {
                    
                    if (myHero.isCollision(colisionables_p[j]))
                    {
                        if (check == 0)
                        {
                            noSound = true;
    
                            colisionables_p[j].estado= PowerUp::EXECUTE;
                            //std::cout << myHero.life << std::endl;
                            if (colisionables_p[j].isVision)
                            {
                                sonidoVision.play();
                            }
                            else
                            {
                                sonidoVida.play();
                            }
                            
                            check = 1;
                            puntos.AddPoints(100);
                          

                        }
                       
                        //std::cout << "disparo y mato" << std::endl;

                    }

                } 
                if (noSound == false&&estado==JUGANDO)
                {
                    //sonidoTiro.play();

                }

             }
         }
                
                  
               



            
            //cout << "posicion zoom y : " << zoom.getPosition().x << endl;


            

            if (sf::Event::MouseEntered&&estado==JUGANDO)
            {

                if (evento.type == sf::Event::MouseButtonPressed)
                {
                    if (evento.mouseButton.button == sf::Mouse::Right)
                    {
                        if (myHero.getCount() == 0)
                        {




                            camera.setSize(1920 / 4, 1080 / 4);
                            camera.setCenter(myHero.pixelPos.x, myHero.pixelPos.y);
                            myHud.model.setScale(0.25f, 0.25f);
                            myHud.model.setPosition(myHero.pixelPos.x-237, myHero.pixelPos.y-130);
                           // myHud.lifeBar.setPosition(myHero.pixelPos.x - 186, myHero.pixelPos.y -87);
                            myHud.lifeBar.setPosition(myHud.model.getPosition().x + 27, myHud.model.getPosition().y + 20);
                            myHud.lifeBar.setScale(0.25f, 0.25f);

                            sf::Mouse::setPosition(center);



                            //zoom.model.setColor(sf::Color::White);
                            //background.setPosition(window.getSize().x / 2 - background.getGlobalBounds().width / 2, window.getSize().x / 2 - background.getGlobalBounds().height / 1.7);
                            //std::cout << myHero.count << "\n";





                        }
                        else if (myHero.getCount() == 1)
                        {


                            camera.setSize(1920, 1080);
                            camera.setCenter(1920 / 2, 1080 / 2);
                            myHud.model.setScale(1, 1);
                            myHud.model.setPosition(10, 20);
                            myHud.lifeBar.setPosition(myHud.model.getPosition().x + 107, myHud.model.getPosition().y + 81);
                            myHud.lifeBar.setScale(1, 1);
                            sf::Mouse::setPosition(center);




                        }
                        myHero.Aim();



                    }
                }

                if (evento.type == sf::Event::MouseButtonReleased)
                {
                    if (evento.mouseButton.button == sf::Mouse::Right)
                    {
                        myHero.CheckCount();
                       

                    }
                    if (evento.mouseButton.button == sf::Mouse::Left)
                    {
                        check = 0;


                    }
                }




            }

            break;
        case DERROTA:
            camera.setSize(1920, 1080);
            camera.setCenter(1920 / 2, 1080 / 2);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

            if (evento.key.code == sf::Keyboard::Up)
            {
                menuDerrota.MoveUp();

            }
            if (evento.key.code == sf::Keyboard::Down)
            {
                menuDerrota.MoveDown();

            }

            if (evento.key.code == sf::Keyboard::Enter)
            {
                switch (menuDerrota.getItem()) {

                case 0:
                    std::cout << "Menu Principal" << "\n";
                    mainMenu.model.setOrigin(0, 0);

                    dondeEstoy = 0;
                    kills = 0;
                    civiles = 0;
                    jugar = false;
                    //myHero.SetSniper();

                    contador = 1;
                    check = 0;

                    estado = ESPERAR;
                    contadorEnemy = 0;
                    contadorPower = 0;
                    delete[]colisionables_e;
                    delete[]colisionables_p;
                    damageColateral = false;
                    cantRegistros = registro.contarRegistros();
                    break;
                    //sonidoMenu.play();

                case 1:
                    dondeEstoy++;
                    window.close();
                    break;

                default:
                    std::cout << "FAILED" << "\n";
                    break;
                }

                break;
            }

            
      

            
            break;
        case ESPERAR:
            estado = MAINMENU;
           
            
            break;
        case VICTORIA:
          
            camera.setSize(1920, 1080);
            camera.setCenter(1920 / 2, 1080 / 2);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

            if (evento.key.code == sf::Keyboard::Up)
            {
                menuDerrota.MoveUp();

            }
            if (evento.key.code == sf::Keyboard::Down)
            {
                menuDerrota.MoveDown();

            }

            if (evento.key.code == sf::Keyboard::Enter)
            {
                switch (menuDerrota.getItem()) {

                case 0:
                    std::cout << "Menu Principal" << "\n";
                    mainMenu.model.setOrigin(0, 0);

                    dondeEstoy = 0;
                    kills = 0;
                    jugar = false;
                    //myHero.SetSniper();

                    contador = 1;
                    check = 0;
                    civiles = 0;
                    estado = ESPERAR;
                    contadorEnemy = 0;
                    contadorPower = 0;
                    delete []colisionables_e;
                    delete[]colisionables_p;
                    damageColateral = false;
                    cantRegistros = registro.contarRegistros();
                    //sonidoMenu.play();
                    break;
                    

                case 1:
                    dondeEstoy++;
                    window.close();
                    break;

                default:
                    std::cout << "FAILED" << "\n";
                    break;
                }

            break;
            }
    }
}
