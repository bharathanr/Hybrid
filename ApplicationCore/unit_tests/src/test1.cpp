#include<iostream>
#include<boost/signals.hpp>
#include"InputSystem.h"

void test_slot()
{
	std::cout<<"BHello, World!"<<std::endl;
}

int main()
{
	InputSystem input_system;
	input_system.HelloWorld.connect(test_slot);
	input_system.HelloWorld();
}
