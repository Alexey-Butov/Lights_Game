#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

constexpr auto maxEdges = 5;
constexpr auto pointSize = 10;
constexpr auto rotation = 60;
constexpr auto rotationLeft = -60;
constexpr auto edgeWidth = pointSize / 2;
constexpr auto edgeLength = pointSize * 3;

class Point
{
public:

    Point(sf::Vector2f location, std::vector<int>& edges);
    
    void draw(sf::RenderTarget& target) const;
    void click(sf::Vector2f location);
    void clickLeft(sf::Vector2f location);
    void paint();
    void paintGray();
   

    sf::CircleShape get();
    std::vector<sf::RectangleShape> getEdge(); 

    void setOnLight(); 
    void setOffLight(); 
    bool getLight(); 


private:

    sf::Color m_pointColor = sf::Color::Color(170, 190, 150, 230);
    sf::Color m_pointColor2 = sf::Color::Color(255, 223, 90, 255);
    sf::Color m_edgeColor = sf::Color::Color(100, 120, 120, 230);

    std::vector<int> m_numOfEdges;
    bool m_light = false;


    void rotate();
    void rotateLeft();


    sf::CircleShape m_point;
    std::vector<sf::RectangleShape> m_edges;

};