//#include "stdafx.h"
#include "UnitTest++.h" // Главный заголовочный файл библиотеки UnitTest++
#include <iostream>
#include "menu.h"

int main( int argc, char const *argv[] )
{
	if ( argc == 2 )
		if ( !strcmp( argv[ 1 ], "-menu" ) )
			return testcaseMenu( "testcase/test2.txt", 0 );
		else if ( !strcmp( argv[ 1 ], "-log" ) )
		{
			return testcaseMenu( "testcase/test2.txt", 0 );
		}
	else
		return UnitTest::RunAllTests();
}