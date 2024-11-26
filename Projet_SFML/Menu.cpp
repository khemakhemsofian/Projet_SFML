#include "Menu.h"

Menu::Menu(float _width, float _height) {
    if (!_MenuFont.loadFromFile("Assets/Font/Super_Mario_64_font.ttf")) {
        cerr << "Erreur de chargement de la police" << endl;
    }

    vector<string> _options = { "Nouvelle Partie", "Charger une Partie", "Options", "Quitter" };
    _selectedIndex = 0;

    for (size_t i = 0; i < _options.size(); i++) {
        Text _TextMenu;
        _TextMenu.setFont(_MenuFont);
        _TextMenu.setString(_options[i]);
        _TextMenu.setCharacterSize(24);
        _TextMenu.setFillColor(Color(0, 0, 0, 230));
        _TextMenu.setStyle(Text::Bold);
        _TextMenu.setPosition(_width / 2 - _TextMenu.getGlobalBounds().width / 2, _height / (_options.size() + 1) * (i + 1));
        _menuOptions.push_back(_TextMenu);
    }

    _menuOptions[_selectedIndex].setFillColor(Color(255, 51, 10, 230));
}

void Menu::draw(RenderWindow& _window) {
    for (const auto& _option : _menuOptions) {
        _window.draw(_option);
    }
}

void Menu::moveUp() {
    if (_selectedIndex - 1 >= 0) {
        _menuOptions[_selectedIndex].setFillColor(Color(255, 255, 255, 230));
        _selectedIndex--;
        _menuOptions[_selectedIndex].setFillColor(Color(255, 51, 10, 230));
    }
}

void Menu::moveDown() {
    if (_selectedIndex + 1 < _menuOptions.size()) {
        _menuOptions[_selectedIndex].setFillColor(Color(255, 255, 255, 230));
        _selectedIndex++;
        _menuOptions[_selectedIndex].setFillColor(Color(255, 51, 10, 230));
    }
}

int Menu::getSelectedIndex() const {
    return _selectedIndex;
}

void Menu::selectOption(Vector2f mousePosition) {
    for (size_t i = 0; i < _menuOptions.size(); i++) {
        if (_menuOptions[i].getGlobalBounds().contains(mousePosition)) {
            _menuOptions[_selectedIndex].setFillColor(Color(255, 255, 255, 230)); // R�initialiser la couleur de l'option pr�c�dente
            _selectedIndex = i; // Mettre � jour l'index s�lectionn�
            _menuOptions[_selectedIndex].setFillColor(Color(255, 51, 10, 230)); // Mettre � jour la couleur de l'option s�lectionn�e
            break;
        }
    }
}
