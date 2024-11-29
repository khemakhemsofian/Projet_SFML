#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>

using namespace sf;
using namespace std;

class GameScene
{
public:
    GameScene(float _width, float _height);
    void handleEvents(Event& event, RenderWindow& _window);
    void Update(float _deltaTime);
    void draw(RenderWindow& _window);
    bool checkReturnToMenu(Vector2f mousePosition); 

private:
    CircleShape _player;
    Text _returnToMenu; 
    Font _font; 
};

#endif // !GAMESCENE_H
