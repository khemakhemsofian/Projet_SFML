#ifndef OPTIONSSCENE_H
#define OPTIONSSCENE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

inline float clamp(float value, float minVal, float maxVal) {
    return (value < minVal) ? minVal : (value > maxVal) ? maxVal : value;
}

class OptionsScene {
public:
    OptionsScene(float _width, float _height);
    void handleEvents(Event& event, RenderWindow& _window);
    void Update(float _deltaTime);
    void draw(RenderWindow& _window);
    void saveSettings();
    void loadSettings();
    bool checkReturnToMenu(Vector2f mousePosition);

private:
    RectangleShape _fullscreenCheckbox;
    bool _isFullscreen;
    float _brightness;
    float _masterVolume;
    float _musicVolume;
    float _sfxVolume;

    Text _returnToMenu;
    Text _brightnessText;
    Text _volumeText;
    Font _font;

    // Slider pour la luminosité
    RectangleShape _brightnessSlider;
    RectangleShape _brightnessIndicator;

    // Slider pour le volume
    RectangleShape _volumeSlider;
    RectangleShape _volumeIndicator;

    void updateBrightnessIndicator();
    void updateVolumeIndicator();
};

#endif // !OPTIONSSCENE_H