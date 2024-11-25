
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace sf;


int main()
{
    // Création de la fenêtre SFML
    RenderWindow window(sf::VideoMode(800, 600), "Mario Tzu Party");
    window.setFramerateLimit(60);

    // Chargement de l'image de fond
    Texture backgroundTexture;
    Font MenuFont;
    SoundBuffer CLickSoundBuffer;
    Music musicDeFond;
   
    if (!backgroundTexture.loadFromFile("Assets/Image/Young_Sun_Tzu_cosplay_Mario.jpg")) {
        return -1; // Vérification si l'image a été correctement chargée
    }
    if (!MenuFont.loadFromFile("Assets/Font/Super_Mario_64_font.ttf")) {
        return -1; // Vérification si l'image a été correctement chargée
    }
    if (!CLickSoundBuffer.loadFromFile("Assets/Audio/UI-Click_Sound.wav")) {
        return -1; // Vérification si l'image a été correctement chargée
    }
    if (!musicDeFond.openFromFile("Assets/Audio/572__aarondbaron__ambienceforyou.wav")) {
        return -1; // Vérification si l'image a été correctement chargée
    }

   
    Text TextMenu;
    TextMenu.setFont(MenuFont);
    TextMenu.setString(L"La font a mario 64 avec é");
    TextMenu.setCharacterSize(24);
    TextMenu.setFillColor(Color(0,0,0,200));
    TextMenu.setStyle(Text::Bold);

    musicDeFond.setLoop(true);
    musicDeFond.setVolume(30.0f);
    musicDeFond.play();
    Sound ClickSound;
    ClickSound.setBuffer(CLickSoundBuffer);
    // Création d'un sprite pour le fond
    Sprite backgroundSprite(backgroundTexture);
    
    // Boucle principale
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left )
        {
            ClickSound.play();
        }

        // Effacement de la fenêtre avec une couleur (par défaut, noir)
        window.clear();

        // Dessiner le fond sur la fenêtre
        window.draw(backgroundSprite);
        window.draw(TextMenu);

        // Afficher le contenu de la fenêtre
        window.display();
    }

    return 0;
}

