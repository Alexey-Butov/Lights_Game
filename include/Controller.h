#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath> 

#include "Point.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

class Controller
{
public:

	Controller();
	~Controller();
	
	void run();


private:

	void traverse(std::vector < std::vector<int>>& m_neighbours, std::vector<Point>& m_points, int row);

	sf::Clock m_clock;
	sf::Text m_mytext;
	sf::Font m_font;

	Level1 m_level1; // level1 member
	Level2 m_level2; // level2 member
	Level3 m_level3; // level3 member



	unsigned int m_curentlevel = 0;

	std::vector<Point> m_points;
	std::vector<std::vector<int>> m_neighbours;
};
