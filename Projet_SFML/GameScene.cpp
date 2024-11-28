#include "GameScene.h"

GameScene::GameScene(float _width,float _height)
{
	_player.setRadius(30.0f);
	_player.setFillColor(Color(47, 255, 126, 230));
	_player.setPosition(_width / 2 - _player.getRadius(), _height / 2 - _player.getRadius());
}

void GameScene::handleEvents(Event& event, RenderWindow& _window) 
{
	if (event.type == Event::KeyPressed)
	{
		if(event.key.code == Keyboard::Z)
		{
			_player.move(0, -10);
		}
		else if(event.key.code == Keyboard::S)
		{
			_player.move(0,10);
		}
		else if(event.key.code == Keyboard::Q)
		{
			_player.move(-10,0);
		}else if(event.key.code == Keyboard::D)
		{
			_player.move(10,0);
		}
	}
}

void GameScene::Update(float _deltaTime)
{
	// a faire plus tard ce sera la logique de mise a jour  pour les animations ou autre
}

void GameScene::draw(RenderWindow& _window)
{
	_window.draw(_player);
}