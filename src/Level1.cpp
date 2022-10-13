#pragma once

#include "Level1.h"


Level1::Level1()
{
}


Level1::~Level1()
{
}

void Level1::build_Level(std::vector<Point>& m_points) // level creation function
{
    auto value = 78;

    for (auto i = 2, j = 0; i < 21; i++, j++) // emplaces points to vector by given distance and location
    {
        if (i < 5) // 3 points creation
        {
            auto location = sf::Vector2f((i + 3.5) * value, 310);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i >= 5 && i <= 8) // 4 points creation
        {
            auto location = sf::Vector2f((i) * value, 380);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 8 && i <= 13) // 5 points creation
        {
            auto location = sf::Vector2f((i - 4.5) * value, 450);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 13 && i <= 17) // 4 points creation
        {
            auto location = sf::Vector2f((i - 9) * value, 520);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else // 3 points creation
        {
            auto location = sf::Vector2f((i - 12.5) * value, 590);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
    }
}
