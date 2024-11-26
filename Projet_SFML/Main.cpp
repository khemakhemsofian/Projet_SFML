#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include "Menu.h"

using namespace sf;
using namespace std;

int main() {
    // Cr�ation de la fen�tre SFML
    RenderWindow _window(VideoMode(800, 600), "Mario Tzu Party");
    _window.setFramerateLimit(60);

    // Chargement des ressources
    Texture _backgroundTexture;
    SoundBuffer _clickSoundBuffer;
    Music _backgroundMusic;


    if (!_backgroundTexture.loadFromFile("Assets/Image/Young_Sun_Tzu_cosplay_Mario.jpg")) {
        return -1;
    }


    if (!_clickSoundBuffer.loadFromFile("Assets/Audio/UI-Click_Sound.wav")) {
        return -1;
    }


    if (!_backgroundMusic.openFromFile("Assets/Audio/572__aarondbaron__ambienceforyou.wav")) {
        return -1;
    }

    _backgroundMusic.setLoop(true);
    _backgroundMusic.setVolume(30.0f);
    _backgroundMusic.play();


    Sound _clickSound;
    _clickSound.setBuffer(_clickSoundBuffer);


    Sprite _backgroundSprite(_backgroundTexture);

    
    Menu _menu(_window.getSize().x, _window.getSize().y);


    while (_window.isOpen()) {
        Event event;
        while (_window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                _window.close();
            }

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2f _mousePosition = _window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                _menu.selectOption(_mousePosition);
                _clickSound.play();


                int _selected = _menu.getSelectedIndex();
                switch (_selected) {
                case 0:
                    cout << "Nouvelle Partie s�lectionn�e" << endl;

                    break;
                case 1:
                    cout << "Charger une Partie s�lectionn�e." << endl;

                    break;
                case 2:
                    cout << "Options s�lectionn�es" << endl;
                    //faire une fenetre pour les option ,je verrai un changement de scene 
                    break;
                case 3:
                    cout << "Quitter le jeu" << endl;
                    _window.close();
                    break;
                }
            }
        }


        _window.clear();
        _window.draw(_backgroundSprite);
        _menu.draw(_window);
        _window.display();
    }

    return 0;
}
