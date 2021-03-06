#ifndef __COLLECTIONS_HEADER_H__
#define __COLLECTIONS_HEADER_H__

#include<variant>
#include<string_view>

namespace Collections::Animal
{
	struct Dog {};
	struct Cat {};
	struct Horse {};

	using Animal = std::variant<Dog, Cat, Horse>;
}

namespace Collections::Transport
{
	struct Car {};
	struct Plane {};

	using Transport = std::variant<Car, Plane, Animal::Horse>;
}


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

namespace Collections::Algorithms
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

#endif