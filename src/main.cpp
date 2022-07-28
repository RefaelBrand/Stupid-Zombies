#include "Controller.h"
#include<iostream>

int main()
{
	try
	{
		Controller().run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}