#include<variant>

export module collections:transports;

import :animals;

export namespace Collections::Transport
{
	struct Car {};
	struct Plane {};

	using Transport = std::variant<Car, Plane, Animal::Horse>;
}