#include<string_view>
#include<variant>
#include<iostream>

export module collections:algorithms;

import :animals;
import :transports;

namespace Collections::Internals
{
	template<typename... Lambdas>
	struct Overloaded : Lambdas...
	{
		using Lambdas::operator ()...;
	};

	template<typename... Lambdas>
	Overloaded(Lambdas...)->Overloaded<Lambdas...>;
}

export namespace Collections::Algorithms
{
	using namespace Internals;

	inline bool can_transport_animal(const Transport::Transport& transport,
		const Animal::Animal& animal)
	{
		using namespace Transport;
		using namespace Animal;

		return std::visit(Overloaded
			{
				[](const Car&, const Horse&) { return false; },
				[](const Plane&, const auto&) { return false; },
				[](const Horse&, const Horse&) { return false; },
				[](const auto&, const auto&) { return true; }
			},
			transport, animal);
	}

	inline std::string_view to_string(const Transport::Transport& transport)
	{
		using namespace Transport;
		using namespace Animal;

		return std::visit(Overloaded
			{
				[](const Car&) { return "Car"; },
				[](const Plane&) { return "Plane"; },
				[](const Horse&) { return "Horse"; }

			}, transport);
	}

	inline std::string_view to_string(const Animal::Animal& animal)
	{
		using namespace Animal;

		return std::visit(Overloaded
			{
				[](const Dog&) { return "Dog"; },
				[](const Cat&) { return "Cat"; },
				[](const Horse&) { return "Horse"; }

			}, animal);
	}
}

export std::string_view can_cannot(bool b)
{
	return b ? "can" : "cannot";
}


export void result(Collections::Transport::Transport transport, Collections::Animal::Animal animal)
{
	using namespace Collections;
	using namespace Algorithms;
	std::cout << "a " << to_string(transport) << " " <<
		can_cannot(can_transport_animal(transport, animal)) <<
		" transport a " << to_string(animal) << std::endl;
}