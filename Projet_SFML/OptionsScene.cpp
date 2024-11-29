#include "OptionsScene.h"

OptionsScene::OptionsScene(float _width, float _height) {
    // Chargement de la police
    if (!_font.loadFromFile("Assets/Font/Super_Mario_64_font.ttf")) {
        cerr << "Erreur de chargement de la police" << endl;
    }

    // Initialisation des options
    _isFullscreen = false; // Par défaut, pas en plein écran
    _brightness = 1.0f; // Valeur par défaut de la luminosité
    _masterVolume = 1.0f; // Volume principal par défaut (1.0 = 100%)
    _musicVolume = 1.0f; // Volume de la musique par défaut (1.0 = 100%)
    _sfxVolume = 1.0f; // Volume des effets sonores par défaut (1.0 = 100%)

    // Configuration de la case à cocher pour le plein écran
    _fullscreenCheckbox.setSize(Vector2f(20, 20));
    _fullscreenCheckbox.setFillColor(Color::White);
    _fullscreenCheckbox.setPosition(100, 100); // Positionner la case à cocher

    // Configuration du texte pour le bouton de retour
    _returnToMenu.setFont(_font);
    _returnToMenu.setString("Retour au Menu");
    _returnToMenu.setCharacterSize(24);
    _returnToMenu.setFillColor(Color::White);
    _returnToMenu.setPosition(10, 10); // Positionner le texte en haut à gauche

    // Configuration des sliders
    _brightnessSlider.setSize(Vector2f(200, 10));
    _brightnessSlider.setFillColor(Color::White);
    _brightnessSlider.setPosition(100, 150); // Positionner le slider de luminosité

    _brightnessIndicator.setSize(Vector2f(10, 10));
    _brightnessIndicator.setFillColor(Color::Green);
    _brightnessIndicator.setPosition(100 + _brightness * 200, 145); // Positionner l'indicateur de luminosité

    _volumeSlider.setSize(Vector2f(200, 10));
    _volumeSlider.setFillColor(Color::White);
    _volumeSlider.setPosition(100, 200); // Positionner le slider de volume

    _volumeIndicator.setSize(Vector2f(10, 10));
    _volumeIndicator.setFillColor(Color::Green);
    _volumeIndicator.setPosition(100 + _masterVolume * 200, 195); // Positionner l'indicateur de volume

    // Charger les paramètres si disponibles
    loadSettings();
}

void OptionsScene::handleEvents(Event& event, RenderWindow& _window) {
    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
        Vector2f mousePosition = _window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));

        // Vérifier si le bouton de retour est cliqué
        if (checkReturnToMenu(mousePosition)) {
            cout << "Retour au menu sélectionné." << endl;
            saveSettings(); // Sauvegarder les paramètres avant de quitter
            // Logique pour retourner au menu principal
        }

        // Vérifier si la case à cocher pour le plein écran est cliquée
        if (_fullscreenCheckbox.getGlobalBounds().contains(mousePosition)) {
            _isFullscreen = !_isFullscreen; // Inverser l'état du plein écran
            if (_isFullscreen) {
                _fullscreenCheckbox.setFillColor(Color::Green); // Indiquer que le plein écran est activé
            }
            else {
                _fullscreenCheckbox.setFillColor(Color::White); // Indiquer que le plein écran est désactivé
            }
        }

        // Vérifier si le slider de luminosité est cliqué
        if (_brightnessSlider.getGlobalBounds().contains(mousePosition)) {
            float newBrightness = (mousePosition.x - _brightnessSlider.getPosition().x) / _brightnessSlider.getSize().x;
            _brightness = clamp(newBrightness, 0.0f, 1.0f); // Limiter la valeur entre 0 et 1
            updateBrightnessIndicator();
        }

        // Vérifier si le slider de volume est cliqué
        if (_volumeSlider.getGlobalBounds().contains(mousePosition)) {
            float newVolume = (mousePosition.x - _volumeSlider.getPosition().x) / _volumeSlider.getSize().x;
            _masterVolume = clamp(newVolume, 0.0f, 1.0f); // Limiter la valeur entre 0 et 1
            updateVolumeIndicator();
        }
    }
}

bool OptionsScene::checkReturnToMenu(Vector2f mousePosition) {
    return _returnToMenu.getGlobalBounds().contains(mousePosition);
}

void OptionsScene::Update(float _deltaTime) {
    // Logique de mise à jour pour les options (par exemple, ajustement de la luminosité)
}

void OptionsScene::draw(RenderWindow& _window) {
    _window.draw(_fullscreenCheckbox);
    _window.draw(_returnToMenu);
    _window.draw(_brightnessSlider);
    _window.draw(_brightnessIndicator);
    _window.draw(_volumeSlider);
    _window.draw(_volumeIndicator);
}

void OptionsScene::saveSettings() {
    ofstream settingsFile("settings.txt");
    if (settingsFile.is_open()) {
        settingsFile << _isFullscreen << endl;
        settingsFile << _brightness << endl;
        settingsFile << _masterVolume << endl;
        settingsFile << _musicVolume << endl;
        settingsFile << _sfxVolume << endl;
        settingsFile.close();
    }
    else {
        cerr << "Erreur lors de l'ouverture du fichier de paramètres." << endl;
    }
}

void OptionsScene::loadSettings() {
    ifstream settingsFile("settings.txt");
    if (settingsFile.is_open()) {
        settingsFile >> _isFullscreen;
        settingsFile >> _brightness;
        settingsFile >> _masterVolume;
        settingsFile >> _musicVolume;
        settingsFile >> _sfxVolume;
        settingsFile.close();
    }
    else {
        cerr << "Aucun fichier de paramètres trouvé, utilisation des valeurs par défaut." << endl;
    }
}

void OptionsScene::updateBrightnessIndicator() {
    _brightnessIndicator.setPosition(100 + _brightness * 200, 145); // Mettre à jour la position de l'indicateur de luminosité
}

void OptionsScene::updateVolumeIndicator() {
    _volumeIndicator.setPosition(100 + _masterVolume * 200, 195); // Mettre à jour la position de l'indicateur de volume
}