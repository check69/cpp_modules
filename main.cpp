#include<variant>

import "collections.h";

using namespace Collections;

int main()
{
	using namespace Animal;
	using namespace Transport;

	result(Horse{}, Dog{});
	result(Horse{}, Cat{});
	result(Horse{}, Horse{});
	result(Car{}, Dog{});
	result(Car{}, Cat{});
	result(Car{}, Horse{});
	result(Plane{}, Dog{});
	result(Plane{}, Cat{});
	result(Plane{}, Horse{});
}