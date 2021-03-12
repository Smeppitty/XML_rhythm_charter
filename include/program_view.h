#ifndef PROGRAM_VIEW_H
#define PROGRAM_VIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "program_logic.h"
#include "gui_element.h"
#include "music_player.h"

#include "button.h"
#include "horizontal_scrollbar.h"
#include "textfield.h"
#include "play_time.h"
#include "chart.h"

class Program_View
{
private:
    std::shared_ptr<Program_Logic> program_logic;
    std::shared_ptr<sf::RenderWindow> window;
    sf::Vector2f WINDOW_SIZE;

    sf::Font font;

    std::shared_ptr<Button> play_button;
    std::shared_ptr<Button> stop_button;
    std::shared_ptr<Button> chart_button;
    std::shared_ptr<Horizontal_Scrollbar> horiz_scrollbar;
    std::shared_ptr<Textfield> textfield;
    std::shared_ptr<Play_Time> musicTime;
    std::shared_ptr<Chart> chart;

    std::shared_ptr<sf::Music> music;
    std::shared_ptr<Music_Player> music_player;
    
    std::vector<std::shared_ptr<GUI_Element>> button_list;
    std::vector<std::shared_ptr<GUI_Element>> gui_element_list;

    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;

public:
    Program_View(std::shared_ptr<Program_Logic> program_logic);

    std::shared_ptr<Music_Player> getMusic() { return music_player; };

    void init();
    void pollInput();
    void draw();
    void chart_music();
    void track_music();
    void update(const float& dt);
};
#endif 