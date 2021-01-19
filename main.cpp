#include<iostream>
#include<string_view>

#include "collections_header.hpp"


std::string_view can_cannot(bool b)
{
	return b ? "can" : "cannot";
}


using namespace Collections;

void result(Transport::Transport transport, Animal::Animal animal)
{
	using namespace Algorithms;
	std::cout << "A " << to_string(transport) << " " <<
		can_cannot(can_transport_animal(transport, animal)) <<
		" transport a " << to_string(animal) << std::endl;
}

int main()
{
	using namespace Animal;
	using namespace Transport;

	result(Horse{}, Dog{});
	result(Horse{}, Cat{});
	result(Horse{}, Horse{});
	result(Car{}, Dog{});
	result(Car{}, Cat{});
	result(Car{}, Horse{});
	result(Plane{}, Dog{});
	result(Plane{}, Cat{});
	result(Plane{}, Horse{});
}