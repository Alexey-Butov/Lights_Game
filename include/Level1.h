#pragma once

#include <vector>

#include "Point.h"


class Level1
{
public:

	Level1();
	~Level1();


	void build_Level(std::vector<Point>& m_points); // gets vector of points and builds level from the vector

	const int getlevelsize() { return m_numOfEdges.size(); }; // gets level size it's the only acsess that i need here

private:

	// Level 1 Vector of vectors, the raws are the points and the colomns are the edges
	std::vector < std::vector<int>> m_numOfEdges = { 
		{1}, {1}, {1}, {1,3} , {1,2,3}, {1,3}, {1,2,3,4},
		{1}, {1,2}, {1,2,3,4}, {1,3}, {1}, {1,2}, {1,3},
		{1,3,5}, {1}, {1}, {1,2}, {1} };

};