#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

class Menu
{
public:
    Menu(float _width, float _height);
    void draw(RenderWindow& _window);
    void moveUp();
    void moveDown();
    int getSelectedIndex() const;
    void selectOption(Vector2f mousePosition); 
    void UpdateEffetSurvol(Vector2f mousePosition);
protected:
    vector<Text> _menuOptions;
    int _selectedIndex;
    Font _MenuFont;
};

#endif // !MENU_H
