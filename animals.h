#ifndef __ANIMALS_H__
#define __ANIMALS_H__

#include<variant>

namespace Collections::Animal
{
	struct Dog {};
	struct Cat {};
	struct Horse {};

	using Animal = std::variant<Dog, Cat, Horse>;
}

#endif