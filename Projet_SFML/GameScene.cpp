#include "GameScene.h"

GameScene::GameScene(float _width, float _height) {
    _player.setRadius(30.0f);
    _player.setFillColor(Color(47, 255, 126, 230));
    _player.setPosition(_width / 2 - _player.getRadius(), _height / 2 - _player.getRadius());

    // Chargement de la police
    if (!_font.loadFromFile("Assets/Font/Super_Mario_64_font.ttf")) {
        cerr << "Erreur de chargement de la police" << endl;
    }

    // Configuration du texte pour le bouton de retour
    _returnToMenu.setFont(_font);
    _returnToMenu.setString("Retour au Menu");
    _returnToMenu.setCharacterSize(24);
    _returnToMenu.setFillColor(Color::White);
    _returnToMenu.setPosition(10, 10); // Positionner le texte en haut à gauche
}

void GameScene::handleEvents(Event& event, RenderWindow& _window) {
    if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Z) {
            _player.move(0, -10);
        }
        else if (event.key.code == Keyboard::S) {
            _player.move(0, 10);
        }
        else if (event.key.code == Keyboard::Q) {
            _player.move(-10, 0);
        }
        else if (event.key.code == Keyboard::D) {
            _player.move(10, 0);
        }
    }
}

bool GameScene::checkReturnToMenu(Vector2f mousePosition) {
    return _returnToMenu.getGlobalBounds().contains(mousePosition);
}

void GameScene::Update(float _deltaTime) {
    // À faire plus tard : ce sera la logique de mise à jour pour les animations ou autre
}

void GameScene::draw(RenderWindow& _window) {
    _window.draw(_player);
    _window.draw(_returnToMenu);
}