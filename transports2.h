#pragma once

#include<variant>

import "animals2.h";

export namespace Collections::Transport2
{
	struct Car {};
	struct Plane {};

	using Transport = std::variant<Car, Plane, Animal2::Horse>;
}