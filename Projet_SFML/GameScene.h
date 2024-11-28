#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

class GameScene
{
public:
	GameScene(float _width,float _height);
	void handleEvents(Event& event, RenderWindow& _window);
	void Update(float _deltaTime);
	void draw(RenderWindow& _window);

private:
	CircleShape _player;
};

#endif // !GAMESCENE_H



