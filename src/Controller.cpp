#pragma once

#include "Controller.h"

Controller::Controller()
{
    // loads font file from windows, which will be used for the Time font
    if (!m_font.loadFromFile("C:\\Windows\\Fonts\\arialbd.ttf")) 
    {
        std::cerr << "error"; // prints invisible error since there is no cmd terminal
    }

    m_mytext.setFont(m_font); // uses loaded font file as a font of the Time
    m_mytext.setCharacterSize(36); // sets font size
    m_mytext.setColor(sf::Color::Cyan); // sets font color
    m_mytext.setPosition(10, 5); // sets font position on screen
}

Controller::~Controller()
{
}
// recursive function to find all neighbours of the center and to turn them on
void Controller::traverse(std::vector<std::vector<int>>& m_neighbours, std::vector<Point>& m_points, int row)
{
    if (m_neighbours.at(row).empty())
        return; // checking if the row is empty

    const auto next = m_neighbours.at(row).at(0); // storing the first element in 'next' and removing it from the row

    m_points.at(next).paint(); // sets the next ellement that it found to ON.
    m_points.at(next).setOnLight();// sets the next ellement that it found to True.


    // removes the element to use the same section for next recursive iteration
    m_neighbours.at(row).erase(m_neighbours.at(row).begin() + 0); 

    traverse(m_neighbours, m_points, next); // goes to next element until there are no more
    traverse(m_neighbours, m_points, row); // goes to next row until there are no more
}

void Controller::run() // main loop of the game
{
    int count = 0;
    unsigned int minutes = 0;
    unsigned int levelcounter = 1;

    auto window = sf::RenderWindow(sf::VideoMode(1000, 1000), "Lights Game");
        
    m_level1.build_Level(m_points); // builds first level
 

    while (window.isOpen()) // window loop
    {

        // checks if the level is up and sets the next level accordingly 
        if (m_curentlevel < levelcounter)
        {
            if (!m_neighbours.empty())
            {
                for (int i = 0; i < m_neighbours.size(); i++)
                    m_neighbours.at(i).clear();

                m_neighbours.clear();
            }
                

            if (m_curentlevel == 0)
            {
                for (auto i = 0; i < m_level1.getlevelsize(); i++) // level 1 neighbours
                    m_neighbours.emplace_back(i);
            }
            if (m_curentlevel == 1)
            {
                m_points.clear();

                m_level2.build_Level(m_points); // builds second level

                for (auto i = 0; i < m_level2.getlevelsize(); i++) // level 2 neighbours
                    m_neighbours.emplace_back(i);
            }
            if (m_curentlevel == 2)
            {
                m_points.clear();

                m_level3.build_Level(m_points); // builds third level

                for (auto i = 0; i < m_level3.getlevelsize(); i++) // level 3 neighbours
                    m_neighbours.emplace_back(i);

            }

            m_points.at(m_points.size() / 2).paint(); // sets the centeral point to ON.
            m_points.at(m_points.size() / 2).setOnLight(); // sets the centeral point light boolean variable to True.

            m_curentlevel++; // counts up current level to prevent reseting the level before it changed to the next.
        }


        unsigned int seconds = static_cast<unsigned int>(m_clock.getElapsedTime().asSeconds());
        //saves game Time in a local variable 

        if (seconds == 60) // minutes counter
        {
            m_clock.restart();
            seconds = 0;
            minutes++;
        }
            

        std::ostringstream oss; // streaming time into a string
        oss << minutes << ":" << seconds;
        m_mytext.setString(oss.str()); // sets printed string on screen from given string

        window.clear();

        for (const auto& p : m_points) // draws all points on screen
        {
            p.draw(window);
        }

        window.draw(m_mytext); // draws text on window to display time

        for (int i = 0; i < m_points.size(); i++) // comparing points from start to end
        {
            for (int j = 0; j < m_points.at(i).getEdge().size(); j++)
            {
                for (int k = 0; k < m_points.size(); k++) // gets all edges in every point vector 
                {
                    if (i == k || abs(i - k) > 10) // skips unnececery runs in this heavy loop
                        continue;

                    for (int l = 0; l < m_points.at(k).getEdge().size(); l++) // seeks intersections
                    {
                        if (m_points.at(i).getEdge().at(j).getGlobalBounds().intersects(m_points.at(k).getEdge().at(l).getGlobalBounds()))
                        {
                            m_neighbours.at(i).push_back(k);
                            continue; // skips after the condition ended in hopes to make it less heavy
                        }

                        if (!m_points.at(m_points.size() / 2).getEdge().at(l).getGlobalBounds().intersects(m_points.at(i).getEdge().at(j).getGlobalBounds())
                            && (i != m_points.size() / 2))
                        {
                            m_points.at(i).paintGray();
                            m_points.at(i).setOffLight();
                        }
                        continue; // skips after turn ended in hopes to make it less heavy
                    }
                }
            }
        }

        // recursive function to find all neighbours of the center and to turn them on
        traverse(m_neighbours, m_points, (m_neighbours.size() - 1) / 2);  

        for (int i = 0; i < m_neighbours.size(); i++) // clears all neighbours to prevent leftovers in the vector
            m_neighbours.at(i).clear();

        window.display();

        if (auto event = sf::Event{}; window.waitEvent(event)) // sfml events loop
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                const auto location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                switch (event.mouseButton.button) // mouse button event
                {
                case sf::Mouse::Button::Right: // right mouse click action
                    for (auto& p : m_points)
                    {
                        p.click(location);
                    }
                    break;

                case sf::Mouse::Button::Left: // left mouse click action
                    for (auto& p : m_points)
                    {
                        p.clickLeft(location);
                    }
                    break;
                }
            }
        }

        // a loop that Checks if all points are turned on 
        for (auto& p : m_points)
        {
            if (!(p.getLight()))
            {
                count = 0;
                break;
            }
            else
                count++;
        }
        
        // a level counter limited to 3 turns, exits after all levels are finished
        if (levelcounter > 3)
            break;

        // sets the level up if all points are on.
        if (count == m_points.size())
            levelcounter++;
    }


}
