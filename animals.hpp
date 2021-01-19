#pragma once
#include<variant>

namespace Collections::Animal
{
	struct Dog {};
	struct Cat {};
	struct Horse {};

	using Animal = std::variant<Dog, Cat, Horse>;
}
