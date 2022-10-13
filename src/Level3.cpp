#pragma once

#include "Level3.h"



Level3::Level3()
{
}


Level3::~Level3()
{
}

void Level3::build_Level(std::vector<Point>& m_points) // level creation function
{
    auto value = 78;

    for (auto i = 2, j = 0; i < 77; i++, j++) // emplaces points to vector by given distance and location
    {
        if (i < 5) // 3 points creation
        {
            auto location = sf::Vector2f((i + 3.5) * value, 100);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i >= 5 && i <= 8) // 4 points creation
        {
            auto location = sf::Vector2f((i) * value, 170);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 8 && i <= 13) // 5 points creation
        {
            auto location = sf::Vector2f((i - 4.5) * value, 240);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 13 && i <= 19) // 6 points creation
        {
            auto location = sf::Vector2f((i - 10) * value, 310);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 19 && i <= 26) // 7 points creation
        {
            auto location = sf::Vector2f((i - 16.5) * value, 380);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 26 && i <= 34) // 8 points creation
        {
            auto location = sf::Vector2f((i - 24) * value, 450);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 34 && i <= 43) // 9 points creation
        {
            auto location = sf::Vector2f((i - 32.5) * value, 520);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 43 && i <= 51) // 8 points creation
        {
            auto location = sf::Vector2f((i - 41) * value, 590);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 51 && i <= 58) // 7 points creation
        {
            auto location = sf::Vector2f((i - 48.5) * value, 660);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 58 && i <= 64) // 6 points creation
        {
            auto location = sf::Vector2f((i - 55) * value, 730);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 64 && i <= 69) // 5 points creation
        {
            auto location = sf::Vector2f((i - 60.5) * value, 800);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 69 && i <= 73) // 4 points creation
        {
            auto location = sf::Vector2f((i - 65) * value, 870);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else // 3 points creation
        {
            auto location = sf::Vector2f((i - 68.5) * value, 940);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
    }
}