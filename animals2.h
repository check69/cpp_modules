#pragma once

#include<variant>

export namespace Collections::Animal2
{
	struct Dog {};
	struct Cat {};
	struct Horse {};

	using Animal = std::variant<Dog, Cat, Horse>;
}