import collections;
import "collections2.h";

using namespace Collections;

void header_files()
{

	using namespace Animal2;
	using namespace Transport2;

	result2( Horse{}, Dog{} );
	result2( Horse{}, Cat{} );
	result2( Horse{}, Horse{} );
	result2( Car{}, Dog{} );
	result2( Car{}, Cat{} );
	result2( Car{}, Horse{} );
	result2( Plane{}, Dog{} );
	result2( Plane{}, Cat{} );
	result2( Plane{}, Horse{} );
}

void modules()
{
	using namespace Animal;
	using namespace Transport;

	result( Horse{}, Dog{} );
	result( Horse{}, Cat{} );
	result( Horse{}, Horse{} );
	result( Car{}, Dog{} );
	result( Car{}, Cat{} );
	result( Car{}, Horse{} );
	result( Plane{}, Dog{} );
	result( Plane{}, Cat{} );
	result( Plane{}, Horse{} );
}

int main()
{
	header_files();
	modules();
}