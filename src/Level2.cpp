#pragma once

#include "Level2.h"

Level2::Level2()
{
}


Level2::~Level2()
{
}

void Level2::build_Level(std::vector<Point>& m_points) // level creation function
{
    auto value = 78;

    for (auto i = 2, j = 0; i < 45; i++, j++) // emplaces points to vector by given distance and location
    {
        if (i < 5) // 3 points creation
        {
            auto location = sf::Vector2f((i + 3.5) * value, 240);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i >= 5 && i <= 8) // 4 points creation
        {
            auto location = sf::Vector2f((i) * value, 310);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 8 && i <= 13) // 5 points creation
        {
            auto location = sf::Vector2f((i - 4.5) * value, 380);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 13 && i <= 19) // 6 points creation
        {
            auto location = sf::Vector2f((i - 10) * value, 450);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 19 && i <= 26) // 7 points creation
        {
            auto location = sf::Vector2f((i - 16.5) * value, 520);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 26 && i <= 32) // 6 points creation
        {
            auto location = sf::Vector2f((i - 23) * value, 590);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 32 && i <= 37) // 5 points creation
        {
            auto location = sf::Vector2f((i - 28.5) * value, 660);
            m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else if (i > 37 && i <= 41) // 4 points creation
        {
        auto location = sf::Vector2f((i - 33) * value, 730);
        m_points.emplace_back(location, m_numOfEdges.at(j));
        }
        else // 3 points creation
        {
        auto location = sf::Vector2f((i - 36.5) * value, 800);
        m_points.emplace_back(location, m_numOfEdges.at(j));
        }
    }
}