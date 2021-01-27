#pragma once

#include<string_view>
#include<variant>
#include<iostream>

import "animals2.h";
import "transports2.h";

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

namespace Collections::Algorithms2
{
	using namespace Internals;

	inline bool can_transport_animal(const Transport2::Transport& transport,
		const Animal2::Animal& animal)
	{
		using namespace Transport2;
		using namespace Animal2;

		return std::visit(Overloaded
			{
				[](const Car&, const Horse&) { return false; },
				[](const Plane&, const auto&) { return false; },
				[](const Horse&, const Horse&) { return false; },
				[](const auto&, const auto&) { return true; }
			},
			transport, animal);
	}

	inline std::string_view to_string(const Transport2::Transport& transport)
	{
		using namespace Transport2;
		using namespace Animal2;

		return std::visit(Overloaded
			{
				[](const Car&) { return "Car"; },
				[](const Plane&) { return "Plane"; },
				[](const Horse&) { return "Horse"; }

			}, transport);
	}

	inline std::string_view to_string(const Animal2::Animal& animal)
	{
		using namespace Animal2;

		return std::visit(Overloaded
			{
				[](const Dog&) { return "Dog"; },
				[](const Cat&) { return "Cat"; },
				[](const Horse&) { return "Horse"; }

			}, animal);
	}
}

std::string_view can_cannot(bool b)
{
	return b ? "can" : "cannot";
}


void result2(Collections::Transport2::Transport transport, Collections::Animal2::Animal animal)
{
	using namespace Collections::Algorithms2;
	std::cout << "a " << to_string(transport) << " " <<
		can_cannot(can_transport_animal(transport, animal)) <<
		" transport a " << to_string(animal) << std::endl;
}