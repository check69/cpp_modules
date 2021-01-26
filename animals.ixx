#include<variant>

export module collections:animals;

export namespace Collections::Animal
{
	struct Dog {};
	struct Cat {};
	struct Horse {};

	using Animal = std::variant<Dog, Cat, Horse>;
}