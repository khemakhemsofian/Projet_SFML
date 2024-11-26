
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include "Menu.h"


using namespace sf;
using namespace std;



int main()
{
    // Création de la fenêtre SFML
    RenderWindow _window(sf::VideoMode(800, 600), "Mario Tzu Party");
    _window.setFramerateLimit(60);

    // Chargement de l'image de fond
    Texture _backgroundTexture;
    SoundBuffer _CLickSoundBuffer;
    Music _musicDeFond;
   
    if (!_backgroundTexture.loadFromFile("Assets/Image/Young_Sun_Tzu_cosplay_Mario.jpg")) {
        return -1; // Vérification si l'image a été correctement chargée
    }
    if (!_CLickSoundBuffer.loadFromFile("Assets/Audio/UI-Click_Sound.wav")) {
        return -1; // Vérification si l'image a été correctement chargée
    }
    if (!_musicDeFond.openFromFile("Assets/Audio/572__aarondbaron__ambienceforyou.wav")) {
        return -1; // Vérification si l'image a été correctement chargée
    }

   
    

    _musicDeFond.setLoop(true);
    _musicDeFond.setVolume(30.0f);
    _musicDeFond.play();
    Sound _ClickSound;
    _ClickSound.setBuffer(_CLickSoundBuffer);
    // Création d'un sprite pour le fond
    Sprite _backgroundSprite(_backgroundTexture);
    
    // Créer une instance de Menu
    Menu _menu(_window.getSize().x, _window.getSize().y);
    
    // Boucle principale
    while (_window.isOpen())
    {
        Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                _window.close();
        }
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left )
        {
            _ClickSound.play();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                _menu.moveUp();
            }
            if (event.key.code == sf::Keyboard::Down) {
                _menu.moveDown();
            }
            if (event.key.code == sf::Keyboard::Enter) {
                // Gérer la sélection de l'option
                int _selected = _menu.getSelectedIndex();
                switch (_selected) {
                case 0:
                    // Logique pour démarrer une nouvelle partie
                    cout << "Nouvelle Partie sélectionnée" << endl;
                    // Ici, tu peux ajouter la logique pour démarrer le jeu
                    break;
                case 1:
                    // Logique pour charger une partie
                    cout << "Charger une Partie sélectionnée" << endl;
                    // Ici, tu peux ajouter la logique pour charger une partie sauvegardée
                    break;
                case 2:
                    // Logique pour accéder aux options
                    cout << "Options sélectionnées" << endl;
                    // Ici, tu peux ajouter la logique pour afficher les options
                    break;
                case 3:
                    // Logique pour quitter le jeu
                    cout << "Quitter le jeu" <<endl;
                    _window.close(); // Ferme la fenêtre
                    break;
                }
            }
        }

            }
        // Effacement de la fenêtre avec une couleur (par défaut, noir)
        _window.clear();
        _window.draw(_backgroundSprite);
        _menu.draw(_window);
        // Afficher le contenu de la fenêtre
        _window.display();
        
        return 0;
    }

    


