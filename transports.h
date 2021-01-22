#ifndef __TRANSPORT_H__
#define __TRANSPORT_H__


import "animals.h";


namespace Collections::Transport
{
	struct Car {};
	struct Plane {};

	using Transport = std::variant<Car, Plane, Animal::Horse>;
}

#endif