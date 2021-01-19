#pragma once

#include<variant>
#include "animals.hpp"

namespace Collections::Transport
{
	struct Car {};
	struct Plane {};

	using Transport = std::variant<Car, Plane, Animal::Horse>;
}