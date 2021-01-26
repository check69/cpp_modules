#pragma once

#include<variant>


import "animals.h";

export namespace Collections::Transport
{
	struct Car {};
	struct Plane {};

	using Transport = std::variant<Car, Plane, Animal::Horse>;
}