#include "Menu.h"

Menu::Menu(float _width, float _height) {

    _MenuFont.loadFromFile("Assets/Font/Super_Mario_64_font.ttf");
    if (!_MenuFont.loadFromFile("Assets/Font/Super_Mario_64_font.ttf")) {
        std::cerr << "Erreur de chargement de la police" << std::endl;
    }


    vector<string> _options = { "Nouvelle Partie", "Charger une Partie", "Options", "Quitter" };

    _selectedIndex = 0;

    for (size_t i = 0; i < _options.size(); i++)
    {
        Text _TextMenu;
        _TextMenu.setFont(_MenuFont);
        _TextMenu.setString(_options[i]);
        _TextMenu.setCharacterSize(24);
        _TextMenu.setFillColor(Color(0, 0, 0, 230));
        _TextMenu.setStyle(Text::Bold);
        _TextMenu.setPosition(_width / 2, _height / (_options.size() + 1) * (i + 1 ));
        _menuOptions.push_back(_TextMenu);
    }

    _menuOptions[_selectedIndex].setFillColor(Color(255,51,10,230));
}

void Menu::draw(RenderWindow &_window)
{
    for (const auto& _option : _menuOptions) {
        _window.draw(_option);
    }
}

void Menu::moveUp() {
    if (_selectedIndex - 1 >= 0) {
        _menuOptions[_selectedIndex].setFillColor(Color(255,255,255,230));
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