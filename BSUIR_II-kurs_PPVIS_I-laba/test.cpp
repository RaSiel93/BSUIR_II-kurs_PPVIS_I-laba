//#include "stdafx.h"
#include "UnitTest++.h" // Главный заголовочный файл библиотеки UnitTest++
#include <iostream>
#include <fstream>
#include <strstream>

#include "menu.h"
#include "mashina.h"

TEST( test1 )
{
	MashinTuring ob1, ob2, ob3;

	ob1.AddElement( 20 );
	ob2 = ob1;
	MashinTuring ob4 = ob2;
	ob3.AddElement( 30 );

	CHECK( ob1 == ob2 );
	CHECK( ob3 != ob2 );
	CHECK( ob4 == ob2 );
}

TEST( test2 )
{
	MashinTuring ob;

	ob.AddPravilo( 20, 1, 0, -1, 21 );
	CHECK( ob.SearchPravilo( 20, 1 )->getEl() == 0 );
	CHECK( ob.SearchPravilo( 20, 1 )->getCar() == -1 );
	CHECK( ob.SearchPravilo( 20, 1 )->getGo() == 21 );
}

TEST( test3 )
{
	MashinTuring ob;

	ob.AddElement( 20 );
	CHECK( ob[ 20 ] == true );
}

TEST( test4 )
{
	MashinTuring ob;

	ob.AddElement( 20 );
	ob.AddElement( 21 );

	CHECK( ob.SearchElement( 20 ) == true );
	CHECK( ob.SearchElement( 21 ) == true );
	CHECK( ob.SearchElement( 22 ) != true );
}

TEST( test5 )
{
	MashinTuring ob;

	char buf[ 1000 ];
	ostrstream out( buf, 1000 );
	out << 3 << endl;
	out << ends;

	istrstream in( buf );
	in >> ob;

	CHECK( 1 == ob[ 3 ] );
}

TEST( test6 )
{
	MashinTuring ob;

	ob.setCaretka( 20 );
	ob++;
	CHECK( 21 == ob.getCaretka() );
	ob--;
	CHECK( 20 == ob.getCaretka() );
}

TEST( test7 )
{
	MashinTuring ob;

	ob.AddElement( 20 );
	ob.AddElement( 21 );
	ob.AddElement( 22 );

	CHECK( ob.SearchElement( 20 ) );
	CHECK( ob.SearchElement( 21 ) );
	CHECK( ob.SearchElement( 22 ) );

	ob.DelElement( 20 );

	CHECK( !ob.SearchElement( 20 ) );
	CHECK( ob.SearchElement( 21 ) );
	CHECK( ob.SearchElement( 22 ) );

	ob.ClearElements();

	CHECK( !ob.SearchElement( 20 ) );
	CHECK( !ob.SearchElement( 21 ) );
	CHECK( !ob.SearchElement( 22 ) );
}

TEST( test8 )
{
	MashinTuring ob;
	
	ob.setHelpScreen( 20 );
	CHECK( ob.getHelpScreen() == 20 );
}

TEST( test9 )
{
	MashinTuring ob;
	
	ob.setHelpScreenPravila( 20 );
	CHECK( ob.getHelpScreenPravila() == 20 );
}

int main( int argc, char const *argv[] )
{
	//testcaseMenu( "testcase/test2.txt", 0 );
	if ( argc == 2 ) {
		if ( !strcmp( argv[ 1 ], "-menu" ) )
			return testcaseMenu( "testcase/test2.txt", 0 );
		else if ( !strcmp( argv[ 1 ], "-log" ) )
		{
			return testcaseMenu( "testcase/test2.txt", 1 );
		}
	}
	else 
		return UnitTest::RunAllTests();
}