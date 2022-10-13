#pragma once

#include "Point.h"

Point::Point(sf::Vector2f location, std::vector<int>& edges) : m_point(pointSize), m_numOfEdges(edges)
{
    m_point.setOrigin(m_point.getRadius(), m_point.getRadius()); // sets point location
    m_point.setPosition(location); // sets point position on screen by given location
    m_point.setFillColor(m_pointColor); // filles points with color

    for (auto i = 0; i < edges.size(); ++i) // 
    {
        m_edges.push_back(sf::RectangleShape({ edgeWidth, edgeLength }));
        auto& e = m_edges.back();
        e.setFillColor(m_edgeColor); // filles edges with color
        e.setOrigin(e.getSize().x / 2, -m_point.getRadius()); // sets edge location
        e.setPosition(m_point.getPosition()); // sets edge position
        e.setRotation(rotation * edges.at(i) - 30); // sets edge position after rotation
    }
}

void Point::draw(sf::RenderTarget& target) const
{
    target.draw(m_point); // draws points
    for (const auto& e : m_edges) // draws edges
    {
        target.draw(e);
    }
}

void Point::click(sf::Vector2f location) // rotates right
{
    if (m_point.getGlobalBounds().contains(location))
    {
        rotate();
    }
}

void Point::clickLeft(sf::Vector2f location) // rotates left
{
    if (m_point.getGlobalBounds().contains(location))
    {
        rotateLeft();
    }
}

void Point::paint() // paints with yellow
{
    m_point.setFillColor(m_pointColor2);
}

void Point::paintGray() // paints with yellow
{
    m_point.setFillColor(m_pointColor);
}

sf::CircleShape Point::get() // access to point functions
{ return m_point; }

std::vector<sf::RectangleShape> Point::getEdge() // access to edge functions
{ return m_edges; }

void Point::setOnLight() { m_light = true; } // sets light boolean value to True
void Point::setOffLight() { m_light = false; } // sets light boolean value to False
bool Point::getLight() { return m_light; } // // gets light boolean value 





void Point::rotate() // rotates edges conter-clockwise
    {
        for (auto& e : m_edges)
        {
            e.rotate(60);
        }
    }

void Point::rotateLeft() // rotates edges clockwise
    {
        for (auto& e : m_edges)
        {
            e.rotate(-60);
        }
    }