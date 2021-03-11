#ifndef HORIZONTAL_SCROLLBAR_H
#define HORIZONTAL_SCROLLBAR_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "gui_element.h"
#include "music_player.h"

class Horizontal_Scrollbar : public GUI_Element 
{
private:
    sf::Vector2f position;
    sf::RectangleShape horizShape;
    sf::Texture horizTex;

    std::string path;
    sf::Color fillColor;
    sf::Vector2f dimensions;

    sf::RectangleShape thumbShape;    

    sf::FloatRect rect;

    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;

    sf::Vector2i startingPos;
    sf::Vector2f currentPos;

public:
    Horizontal_Scrollbar(std::string path, sf::Color fillColor, sf::Vector2f position, sf::Vector2f dimensions);    

    bool isClicked(std::shared_ptr<sf::RenderWindow> window);
    void draw(std::shared_ptr<sf::RenderWindow> window);

    void scrub(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Music_Player> music_player);
    void autoScroll(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Music_Player> music_player);
};

#endif