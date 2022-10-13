#pragma once

#include <exception>
#include <iostream>

#include "Controller.h"

int main() try {
	{
		Controller a;
		a.run();
	}
}
catch (...)
{
	std::cerr << "Unknown exception\n"; 
	return EXIT_FAILURE;
}

